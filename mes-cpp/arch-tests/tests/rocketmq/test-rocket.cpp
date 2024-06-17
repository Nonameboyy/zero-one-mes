/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/09 15:43:28

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
#include <iostream>
#include <mutex>
#include <thread>
#include "Macros.h"
#include "SampleDTO.h"
#include "NacosClient.h"
#include "RocketClient.h"

#include "gtest/gtest.h"

/**
 * ����һ��MQ���Ĳ����࣬������ʾ����Ч��
 */
class RocketSubscribe : public RocketClient::RConsumerListener {
public:
	// ���յ���Ϣ����
	int number = 0;
	// �յ���Ϣ�����߼�
	void receiveMessage(std::string payload) override
	{
		// ������Ϣ��+1
		number++;
		// ����JSON��Ϣ��DTO��
		RC_RECEIVER_MSG_CONVERT(dto, SampleDTO, payload);
		// ��ӡ��Ϣ����
		std::cout << "receiveMessage: " << dto->id.getValue(-1)
			<< "-" << dto->name.getValue("")
			<< "-" << dto->sex.getValue("")
			<< "-" << dto->age.getValue(0)
			<< std::endl;
	}
};

/**
 * ����һ�����Լоߣ����ڴ���MQ����ͨ���߼�
 */
class RocketTest : public testing::Test {
protected:
	void SetUp() override
	{
		//��ȡ����
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
		string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");

		// �����ͻ���
		this->client = new RocketClient(namesrv);
	}
	void TearDown() override
	{
		if (client)
		{
			client->unsubscribe();
			delete client;
			client = nullptr;
		}
	}
	// MQ�ͻ��˶���
	RocketClient* client = nullptr;
};

// �����첽������Ϣ
TEST_F(RocketTest, SendAsync) {
	// ����������Ϣ�ص�
	auto cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			std::cout << "RSendCallback send status: " << staus << endl;
		});

	// ������Ϣ����
	auto dto = SampleDTO::createShared();
	dto->name = "cat";
	dto->sex = "man";
	dto->age = 10;
	
	// ������Ϣ
	dto->id = 1;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, cb.get());
	dto->id = 2;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, nullptr);

	// ����1s�ȴ���Ϣ�������
	std::this_thread::sleep_for(1s);
}

// ����ͬ��������Ϣ
TEST_F(RocketTest, SendSync) {
	// ������Ϣ����
	auto dto = SampleDTO::createShared();
	dto->name = "cat";
	dto->sex = "man";
	dto->age = 10;
	dto->id = 3;
	// ������Ϣ
	RC_PUBLISH_OBJ_MSG_SYNC(res, client, "hello", dto);
	std::cout << "sync send result: " << res << endl;
}

// ���Զ���
TEST_F(RocketTest, Subscribe) {
	// ����������Ϣ�۲���
	RocketSubscribe tl;

	// ��������
	client->subscribe("hello");
	// �����Ϣ���Ĺ۲���
	client->addListener(&tl);

	// ������2����Ϣ��ֹͣ�����߼�
	while (tl.number < 2)
	{
		// ��������
		std::this_thread::sleep_for(10ms);
	}
}

#endif // USE_ROCKETMQ