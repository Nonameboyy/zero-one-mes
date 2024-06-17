#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:12:41
 
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
#ifndef _ROCKETCLIENT_H_
#define _ROCKETCLIENT_H_
#define WIN32_LEAN_AND_MEAN

#ifdef LINUX
#include "unistd.h"
#include <functional>
#endif
#include "rocketmq/DefaultMQProducer.h"
#include "rocketmq/DefaultMQPushConsumer.h"
using namespace rocketmq;

/**
 * ����һ��Rocketmq�ͻ��ˣ�����װ���ò�����
 * �ο����ӣ�https://github.com/apache/rocketmq-client-cpp/tree/release-2.1.0/example
 */
class RocketClient
{
private:
	/**
	 * MQ��Ϣ������
	 */
	class RMessageLisenter : public MessageListenerConcurrently {
	private:
		RocketClient* client;
	public:
		explicit RMessageLisenter(RocketClient* client);
		ConsumeStatus consumeMessage(const std::vector<MQMessageExt>& msgs) override;
	};
	/**
	 * MQ�Զ�ɾ���ص�
	 */
	class RAutoDeleteSendCallback : public AutoDeleteSendCallBack {
	public:
		void onSuccess(SendResult& sendResult) override;
		void onException(MQException& e) override;
	};
public:
	/**
	 * ��Ϣ�����ص�
	 */
	class RSendCallback : public SendCallback {
	private:
		std::function<void(SendStatus)> cf;
	public:
		explicit RSendCallback(std::function<void(SendStatus)> cf);
		void onSuccess(SendResult& sendResult) override;
		void onException(MQException& e) override;
	};
	/**
	 * ������Ϣ������
	 */
	class RConsumerListener {
	public:
		// ������Ϣ
		virtual void receiveMessage(std::string payload) = 0;
	};
private:
	// nameserver��ַ
	std::string namesrv;
	// ��������
	std::string groupname;
	// ��ǰ����
	std::string m_topic;
	// ������Ϣ�¼�֪ͨ����
	std::vector<RConsumerListener*> m_listeners;
	// ������
	DefaultMQProducer* m_producer;
	// ������
	DefaultMQPushConsumer* m_consumer;
	// MQ��Ϣ������
	RMessageLisenter* m_msgListener;
	// �ͷ�������
	void releaseProducer();
	// �ͷ�������
	void releaseConsumer();
public:
	//************************************
	// Method:    RocketClient
	// FullName:  RocketClient::RocketClient
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: const std::string & namesrv nameserver��ַ���磺ip1:port1;ip2:port2
	// Parameter: const std::string & groupName �������ƣ�Ĭ��ֵΪcpp-rocketmq
	//************************************
	explicit RocketClient(const std::string& namesrv, const std::string& groupName = "cpp-rocketmq");
	// �����ͷ���Դ
	~RocketClient();
	//************************************
	// Method:    productMsg
	// FullName:  RocketClient::productMsg
	// Access:    public 
	// Returns:   void
	// Description: ������Ϣ
	// Parameter: const std::string & topic ����
	// Parameter: const std::string & body ��Ϣ����
	// Parameter: SendCallback * cb ���ͽ���ص�����Ĭ��ֵnullptr
	//************************************
	void productMsgAsync(const std::string& topic, const std::string& body, SendCallback* cb = nullptr);
	//************************************
	// Method:    productMsgSync
	// FullName:  RocketClient::productMsgSync
	// Access:    public 
	// Returns:   rocketmq::SendStatus ��Ϣ���ͽ��״̬
	// Description: ͬ��������Ϣ
	// Parameter: const std::string & topic ����
	// Parameter: const std::string & body ��Ϣ����
	//************************************
	rocketmq::SendStatus productMsgSync(const std::string& topic, const std::string& body);
	//************************************
	// Method:    subscribe
	// FullName:  RocketClient::subscribe
	// Access:    public 
	// Returns:   bool ���ĳɹ�����true
	// Description: ��������
	// ע�⣺ͬһ��RocketClient����ֻ�ܶ���һ�Σ���Ȼ�����ȡ�����ģ�Ȼ�����¶���
	// Parameter: const std::string & topic ����
	//************************************
	bool subscribe(const std::string& topic);
	//************************************
	// Method:    unsubscribe
	// FullName:  RocketClient::unsubscribe
	// Access:    public 
	// Returns:   void
	// Description: ȡ������
	//************************************
	void unsubscribe();
	//************************************
	// Method:    addListener
	// FullName:  RocketClient::addListener
	// Access:    public 
	// Returns:   void
	// Description: ��Ӷ�����Ϣ���������
	// Parameter: RConsumerListener * listener �����߶���
	//************************************
	void addListener(RConsumerListener* listener);
	//************************************
	// Method:    removeListener
	// FullName:  RocketClient::removeListener
	// Access:    public 
	// Returns:   void
	// Description: �Ƴ�������Ϣ���������
	// Parameter: RConsumerListener * listener �����߶���
	//************************************
	void removeListener(RConsumerListener* listener);
	//************************************
	// Method:    removeAllListener
	// FullName:  RocketClient::removeAllListener
	// Access:    public 
	// Returns:   void
	// Description: �Ƴ����ж�����Ϣ���������
	//************************************
	void removeAllListener();
};

#endif // _ROCKETCLIENT_H_
