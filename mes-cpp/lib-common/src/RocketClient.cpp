/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:17:08
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifdef USE_ROCKETMQ

#include "pch.h"
#include <iostream>
#include <sstream>
#include <mutex>
#include <chrono>
#include <thread>
#include "RocketClient.h"
using namespace std;
using namespace std::chrono;

// ����һ��ʵ������
#define RCMQ_INSTANCE_NAME_MK(_TAG_) \
auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); \
stringstream ss; \
ss << groupname << "@" << _TAG_ << "-" << now; \
string instanceName = ss.str() 

// ����һ��ȫ�ֻ�����
std::mutex rocket_mq_mtx;

RocketClient::RMessageLisenter::RMessageLisenter(RocketClient* client)
{
	this->client = client;
}

rocketmq::ConsumeStatus RocketClient::RMessageLisenter::consumeMessage(const std::vector<MQMessageExt>& msgs)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	for (const MQMessageExt& msg : msgs)
	{
#ifdef _DEBUG
		cout << "RMessageLisenter: " << msg.getBody() << endl;
#endif
		for (auto listener : client->m_listeners)
		{
			listener->receiveMessage(msg.getBody());
		}
	}
	return ConsumeStatus::CONSUME_SUCCESS;
}

void RocketClient::RAutoDeleteSendCallback::onSuccess(SendResult& sendResult)
{
	cout << "RAutoDeleteSendCallback: send success, status is " << sendResult.getSendStatus() << endl;
}

void RocketClient::RAutoDeleteSendCallback::onException(MQException& e)
{
	cout << "RAutoDeleteSendCallback: send exception, " << e << endl;
}

RocketClient::RSendCallback::RSendCallback(std::function<void(SendStatus)> cf)
{
	this->cf = cf;
}

void RocketClient::RSendCallback::onSuccess(SendResult& sendResult)
{
	// ���лص�
	cf(sendResult.getSendStatus());
}

void RocketClient::RSendCallback::onException(MQException& e)
{
	cout << "RSendCallback: send exception, " << e.what() << endl;
	// ���лص�
	cf(SendStatus::SEND_FLUSH_DISK_TIMEOUT);
}

void RocketClient::releaseProducer()
{
	if (m_producer)
	{
		m_producer->shutdown();
		delete m_producer;
		m_producer = nullptr;
		cout << "producer shutdown finish." << endl;
	}
}

void RocketClient::releaseConsumer()
{
	if (m_consumer)
	{
		m_consumer->shutdown();
		delete m_consumer;
		m_consumer = nullptr;
		cout << "consumer shutdown finish." << endl;
	}
}

RocketClient::RocketClient(const std::string& namesrv, const std::string& groupName /*= "cpp-rocketmq"*/)
{
	this->namesrv = namesrv;
	this->groupname = groupName;
	this->m_topic = "";
	this->m_producer = nullptr;
	this->m_consumer = nullptr;
	this->m_msgListener = new RMessageLisenter(this);
}

RocketClient::~RocketClient()
{
	delete this->m_msgListener;
	releaseConsumer();
	releaseProducer();
}

void RocketClient::productMsgAsync(const std::string& topic, const std::string& body, SendCallback* cb /*= nullptr*/)
{
	// ����һ��ʵ������
	RCMQ_INSTANCE_NAME_MK("async-producer");
	// ����������
	auto producer = new DefaultMQProducer(groupname);
	producer->setNamesrvAddr(namesrv);
	producer->setInstanceName(instanceName);
	// �ص�����
	SendCallback* delCallBack = nullptr;
	if (!cb) delCallBack = new RAutoDeleteSendCallback();
	// ����������
	try {
		producer->start();
	}
	catch (MQException& e) {
		if (cb)
			cb->onException(e);
		else
		{
			delCallBack->onException(e);
			delete delCallBack;
		}
		delete producer;
		return;
	}
	// ����������Ϣ�߳�
	std::thread th([=]() 
		{
			// ������Ϣ����
			MQMessage msg(topic, body);
			// ������Ϣ
			try {
				if (cb)
					producer->send(msg, cb);
				else
					producer->send(msg, delCallBack);
			}
			catch (MQException& e) {
				if (cb)
					cb->onException(e);
				else
				{
					delCallBack->onException(e);
					delete delCallBack;
				}
			}
			producer->shutdown();
			delete producer;
		});
	th.detach();
}

rocketmq::SendStatus RocketClient::productMsgSync(const std::string& topic, const std::string& body)
{
	// ����������
	if (!m_producer || this->m_topic != topic)
	{
		// �����ͷ���Դ
		releaseProducer();
		// ���õ�ǰ������
		this->m_topic = topic;
		// ����һ��ʵ������
		RCMQ_INSTANCE_NAME_MK("sync-producer");
		// ��������������
		m_producer = new DefaultMQProducer(groupname);
		m_producer->setNamesrvAddr(namesrv);
		m_producer->setInstanceName(instanceName);
		try
		{
			m_producer->start();
		}
		catch (MQException& e)
		{
			cout << "Sync start fail: " << e << endl;
			return rocketmq::SendStatus::SEND_FLUSH_DISK_TIMEOUT;
		}
	}
	// ������Ϣ����
	MQMessage msg(topic, body);
	// ������Ϣ
	try {
		SendResult sendResult = m_producer->send(msg);
		return sendResult.getSendStatus();
	}
	catch (const MQException& e) {
		cout << "Sync send fail: " << e << endl;
		return rocketmq::SendStatus::SEND_FLUSH_DISK_TIMEOUT;
	}
}

bool RocketClient::subscribe(const std::string& topic)
{
	// �ж��Ƿ��Ѿ����Ĺ�
	if (m_consumer)
	{
		std::cerr << "already subscribed, no need to subscribe again." << std::endl;
		std::cerr << "but you can unsubscribe and then subscribe." << std::endl;
		return true;
	}

	// ����һ��ʵ������
	RCMQ_INSTANCE_NAME_MK("push-consumer");
	
	// ����������
	m_consumer = new DefaultMQPushConsumer(groupname);
	m_consumer->setNamesrvAddr(namesrv);
	m_consumer->setInstanceName(instanceName);
	m_consumer->setConsumeFromWhere(CONSUME_FROM_LAST_OFFSET);
	m_consumer->setMessageModel(rocketmq::BROADCASTING);
	m_consumer->subscribe(topic, "*");
	m_consumer->setConsumeThreadCount(1);
	m_consumer->setTcpTransportTryLockTimeout(1000);
	m_consumer->setTcpTransportConnectTimeout(400);
	// ע���¼�����
	m_consumer->registerMessageListener(this->m_msgListener);
	m_consumer->setAsyncPull(true);
	m_consumer->setMessageTrace(true);
	try {
		m_consumer->start();
	}
	catch (MQException& e) {
		std::cout << "consumer start fail: " << e << endl;
		releaseConsumer();
		return false;
	}
	return true;
}

void RocketClient::unsubscribe()
{
	releaseConsumer();
}

void RocketClient::addListener(RConsumerListener* listener)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	m_listeners.push_back(listener);
}

void RocketClient::removeListener(RConsumerListener* listener)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	auto iter = std::find(m_listeners.begin(), m_listeners.end(), listener);
	if (iter != m_listeners.end())
	{
		m_listeners.erase(iter);
	}
}

void RocketClient::removeAllListener()
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	m_listeners.clear();
}

#endif // USE_ROCKETMQ