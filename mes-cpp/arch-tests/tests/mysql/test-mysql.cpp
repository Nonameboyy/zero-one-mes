/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 11:30:59

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
#include "Macros.h"
#include "DbInit.h"
#include "SqlSession.h"
#include "TransactionManager.h"
#include "LibTest.h"
#include "NacosClient.h"

#include "gtest/gtest.h"

/**
 * 定义一个测试夹具类，用于管理数据库连接池
 */
class MysqlTest : public testing::Test {
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
		// 获取数据库连接信息
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		std::string dbHost = "";
		std::string dbName = "";
		int dbPort = 0;
		// 解析数据库连接字符串
		yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);
		// 获取数据库用户名和密码
		std::string dbUsername = yaml.getString(&node, "spring.datasource.username");
		std::string dbPassword = yaml.getString(&node, "spring.datasource.password");
		// 初始化数据库连接池
		DbInit::initDbPool({ dbUsername, dbPassword, dbName, dbHost, dbPort, 4 });
	}
	void TearDown() override
	{
		// 释放数据库连接池
		DbInit::releasePool();
	}
};

TEST_F(MysqlTest, TestSS) {
	SqlSession sqlsession;
	// 创建表
	string table = "CREATE TABLE IF NOT EXISTS `lib_test` (`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,`first` text NOT NULL,`last` text NOT NULL,`age` smallint(5) unsigned NOT NULL,PRIMARY KEY(`id`)) ENGINE = InnoDB DEFAULT CHARSET = utf8";
	sqlsession.execute(table);
	// 插入数据
	string fullSql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES('" + ZH_WORDS_GETTER("mysql.zh1") + "', '" + ZH_WORDS_GETTER("mysql.zh2") + "', '96')";
	string sql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES(?, ?, ?)";
	uint64_t id = sqlsession.executeInsert(fullSql);
	ASSERT_GT(id, 0);
	cout << "full   sql excute id is " << id << endl;
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh5"), 97);
	ASSERT_GT(id, 0);
	cout << "format sql excute id is " << id << endl;
	// 查询数据
	string qsql = "SELECT * FROM `lib_test` WHERE id=?";
	string qfullSql = "SELECT * FROM `lib_test`";
	LibTestMapper mapper;
	list<LibTest> results = sqlsession.executeQuery<LibTest, LibTestMapper>(qsql, mapper, "cs", "2");
	cout << "query id is 2:" << endl;
	if (results.size() != 0) {
		LibTest sub = results.front();
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}
	cout << "query all:" << endl;
	results = sqlsession.executeQuery<LibTest, LibTestMapper>(qfullSql, mapper);
	for (LibTest sub : results)
	{
		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
	}

	// 测试事务
	cout << "test transaction begin" << endl;
	sqlsession.beginTransaction();
	string usql = "UPDATE `lib_test` SET `first`='" + ZH_WORDS_GETTER("mysql.zh4") + "' WHERE `id`=2";
	int row = sqlsession.executeUpdate(usql);
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh6"), 98);
	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	cout << "test transaction end" << endl;

	// 事务结束再提交一条数据,测试是否可以正常提交数据
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh5"), 99);
	ASSERT_GT(id, 0);
	cout << "transaction end insert data id is " << id << endl;
}

TEST_F(MysqlTest, TestTM) {
	// 定义两个DAO
	LibTestDAO1 d1;
	LibTestDAO2 d2;

	// 定义事务管理器
	TransactionManager tm(&d1, &d2);

	// 执行第一个DAO操作
	LibTest uObj;
	uObj.first = ZH_WORDS_GETTER("mysql.zh7");
	uObj.last = ZH_WORDS_GETTER("mysql.zh8");
	uObj.id = 1;
	int row = d1.update(uObj);
	// 执行第二个DAO操作
	row = row + d2.deleteById(6);
	// 判断是否提交事务
	if (row == 2)
	{
		cout << "tm commit" << endl;
		tm.commit();
	}
	else
	{
		cout << "tm rollback" << endl;
		tm.rollback();
	}
}
