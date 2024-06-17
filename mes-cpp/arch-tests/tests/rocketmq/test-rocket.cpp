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
 * 定义一个MQ订阅测试类，用于演示订阅效果
 */
class RocketSubscribe : public RocketClient::RConsumerListener {
public:
	// 接收到消息个数
	int number = 0;
	// 收到消息处理逻辑
	void receiveMessage(std::string payload) override
	{
		// 接收消息数+1
		number++;
		// 解析JSON消息到DTO中
		RC_RECEIVER_MSG_CONVERT(dto, SampleDTO, payload);
		// 打印消息数据
		std::cout << "receiveMessage: " << dto->id.getValue(-1)
			<< "-" << dto->name.getValue("")
			<< "-" << dto->sex.getValue("")
			<< "-" << dto->age.getValue(0)
			<< std::endl;
	}
};

/**
 * 定义一个测试夹具，用于处理MQ测试通用逻辑
 */
class RocketTest : public testing::Test {
protected:
	void SetUp() override
	{
		//获取配置
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
		string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");

		// 创建客户端
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
	// MQ客户端对象
	RocketClient* client = nullptr;
};

// 测试异步发送消息
TEST_F(RocketTest, SendAsync) {
	// 创建发送消息回调
	auto cb = make_shared<RocketClient::RSendCallback>([](SendStatus staus)
		{
			std::cout << "RSendCallback send status: " << staus << endl;
		});

	// 定义消息对象
	auto dto = SampleDTO::createShared();
	dto->name = "cat";
	dto->sex = "man";
	dto->age = 10;
	
	// 发送消息
	dto->id = 1;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, cb.get());
	dto->id = 2;
	RC_PUBLISH_OBJ_MSG_ASYNC(client, "hello", dto, nullptr);

	// 休眠1s等待消息发送完成
	std::this_thread::sleep_for(1s);
}

// 测试同步发送消息
TEST_F(RocketTest, SendSync) {
	// 定义消息对象
	auto dto = SampleDTO::createShared();
	dto->name = "cat";
	dto->sex = "man";
	dto->age = 10;
	dto->id = 3;
	// 发送消息
	RC_PUBLISH_OBJ_MSG_SYNC(res, client, "hello", dto);
	std::cout << "sync send result: " << res << endl;
}

// 测试订阅
TEST_F(RocketTest, Subscribe) {
	// 创建订阅消息观察者
	RocketSubscribe tl;

	// 开启订阅
	client->subscribe("hello");
	// 添加消息订阅观察者
	client->addListener(&tl);

	// 接收完2个消息就停止测试逻辑
	while (tl.number < 2)
	{
		// 短暂休眠
		std::this_thread::sleep_for(10ms);
	}
}

#endif // USE_ROCKETMQ