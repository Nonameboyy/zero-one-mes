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

// ʹ��Redis��Ҫ�����ͷ�ļ�
#include "Macros.h"
#include "NacosClient.h"
#include "RedisClient.h"

#include "gtest/gtest.h"

/**
 *  ����һ�����Լо��࣬���ڹ������ݿ�����
 */
class RedisTest : public testing::Test {

protected:
	void SetUp() override
	{
		// ��ȡ����
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
		// ��ȡredis�������
		YamlHelper yaml;
		string host = yaml.getString(&node, "spring.redis.host");
		string port = yaml.getString(&node, "spring.redis.port");
		string password = yaml.getString(&node, "spring.redis.password");

		// ����RedisClient����
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
	// Redis�ͻ������Ӷ���
	RedisClient* rc = nullptr;
};

// ����setָ��
TEST_F(RedisTest, Set) {
	bool res = rc->execute<bool>(
		[](Redis* r) {
			return r->set("foo", "bar");
		});
	ASSERT_EQ(res, true);
}

// ����getָ��
TEST_F(RedisTest, Get) {
	string val = rc->execute<string>(
		[](Redis* r) {
			return r->get("foo").value();
		});
	ASSERT_NE(val, "");
	std::cout << val << std::endl;
}

#endif // USE_REDIS