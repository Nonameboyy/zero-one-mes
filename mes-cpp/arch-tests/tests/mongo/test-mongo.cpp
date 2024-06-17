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

// MongoDBʹ����Ҫ�����ͷ�ļ�
#include "Macros.h"
#include "NacosClient.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

#include "gtest/gtest.h"

/**
 *  ����һ�����Լо��࣬���ڹ������ݿ�����
 */
class MongoTest : public testing::Test {
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
		// ��ȡmongodb�������
		YamlHelper yaml;
		string uri = yaml.getString(&node, "spring.data.mongodb.uri");

		// �������Ӷ���
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
	// MongoDB�ͻ������Ӷ���
	MongoClient* mc = nullptr;
};

// ������ӵ�������
TEST_F(MongoTest, AddOne) {
	// ʹ���ĵ������������ĵ�����
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
	// ִ���������
	auto res = mc->addOne("t1", doc.view());
	ASSERT_NE(res.type(), bsoncxx::type::k_null);
	std::cout << res.get_oid().value.to_string() << std::endl;
}

// ������Ӷ�������
TEST_F(MongoTest, AddMultiple) {
	// ��������ĵ�����
	std::vector<bsoncxx::document::value> documents;
	for (int i = 0; i < 10; i++) {
		documents.push_back(bsoncxx::builder::stream::document{} << "i" << i << finalize);
	}
	int32_t addNum = mc->addMultiple("t2", documents);
	ASSERT_GT(addNum, 0);
}

// ���Բ�ѯ����
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