/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 21:03:33

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
#ifdef USE_REDIS

// 使用Redis需要的相关头文件
#include "Macros.h"
#include "NacosClient.h"
#include "RedisClient.h"

#include "gtest/gtest.h"

/**
 *  定义一个测试夹具类，用于管理数据库连接
 */
class RedisTest : public testing::Test {

protected:
	void SetUp() override
	{
		// 获取配置
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
		// 获取redis相关配置
		YamlHelper yaml;
		string host = yaml.getString(&node, "spring.redis.host");
		string port = yaml.getString(&node, "spring.redis.port");
		string password = yaml.getString(&node, "spring.redis.password");

		// 创建RedisClient对象
		this->rc = new RedisClient(host, atoi(port.c_str()), password);
	}
	void TearDown() override
	{
		if (rc)
		{
			delete rc;
			rc = nullptr;
		}
	}
	// Redis客户端连接对象
	RedisClient* rc = nullptr;
};

// 测试set指令
TEST_F(RedisTest, Set) {
	bool res = rc->execute<bool>(
		[](Redis* r) {
			return r->set("foo", "bar");
		});
	ASSERT_EQ(res, true);
}

// 测试get指令
TEST_F(RedisTest, Get) {
	string val = rc->execute<string>(
		[](Redis* r) {
			return r->get("foo").value();
		});
	ASSERT_NE(val, "");
	std::cout << val << std::endl;
}

#endif // USE_REDIS