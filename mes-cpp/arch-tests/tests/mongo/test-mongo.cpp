/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 15:16:00

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
#ifdef USE_MONGO

// MongoDB使用需要的相关头文件
#include "Macros.h"
#include "NacosClient.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

#include "gtest/gtest.h"

/**
 *  定义一个测试夹具类，用于管理数据库连接
 */
class MongoTest : public testing::Test {
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
		// 获取mongodb相关配置
		YamlHelper yaml;
		string uri = yaml.getString(&node, "spring.data.mongodb.uri");

		// 创建连接对象
		this->mc = new MongoClient(uri);
	}
	void TearDown() override
	{
		if (mc)
		{
			delete mc;
			mc = nullptr;
		}
	}
	// MongoDB客户端连接对象
	MongoClient* mc = nullptr;
};

// 测试添加单条数据
TEST_F(MongoTest, AddOne) {
	// 使用文档构建器构建文档数据
	auto docBuilder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc = docBuilder
		<< "name" << "MongoDB"
		<< "type" << "database"
		<< "count" << 1
		<< "versions" << open_array << "v3.2" << "v3.0" << "v2.6" << close_array
		<< "info"
		<< open_document
		<< "x" << 203
		<< "y" << 102
		<< close_document
		<< finalize;
	// 执行数据添加
	auto res = mc->addOne("t1", doc.view());
	ASSERT_NE(res.type(), bsoncxx::type::k_null);
	std::cout << res.get_oid().value.to_string() << std::endl;
}

// 测试添加多条数据
TEST_F(MongoTest, AddMultiple) {
	// 创建多个文档对象
	std::vector<bsoncxx::document::value> documents;
	for (int i = 0; i < 10; i++) {
		documents.push_back(bsoncxx::builder::stream::document{} << "i" << i << finalize);
	}
	int32_t addNum = mc->addMultiple("t2", documents);
	ASSERT_GT(addNum, 0);
}

// 测试查询调用
TEST_F(MongoTest, Query)
{
	bool res = mc->execute("t2",
		[](mongocxx::collection* collection) {
			auto cursor = collection->find({});
			for (auto doc : cursor) {
				cout << bsoncxx::to_json(doc) << endl;
			}
		});
	ASSERT_EQ(res, true);
}
#endif // USE_MONGO