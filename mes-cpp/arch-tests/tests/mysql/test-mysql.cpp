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
 * ����һ�����Լо��࣬���ڹ������ݿ����ӳ�
 */
class MysqlTest : public testing::Test {
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
		// ��ȡ���ݿ�������Ϣ
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		std::string dbHost = "";
		std::string dbName = "";
		int dbPort = 0;
		// �������ݿ������ַ���
		yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);
		// ��ȡ���ݿ��û���������
		std::string dbUsername = yaml.getString(&node, "spring.datasource.username");
		std::string dbPassword = yaml.getString(&node, "spring.datasource.password");
		// ��ʼ�����ݿ����ӳ�
		DbInit::initDbPool({ dbUsername, dbPassword, dbName, dbHost, dbPort, 4 });
	}
	void TearDown() override
	{
		// �ͷ����ݿ����ӳ�
		DbInit::releasePool();
	}
};

TEST_F(MysqlTest, TestSS) {
	SqlSession sqlsession;
	// ������
	string table = "CREATE TABLE IF NOT EXISTS `lib_test` (`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,`first` text NOT NULL,`last` text NOT NULL,`age` smallint(5) unsigned NOT NULL,PRIMARY KEY(`id`)) ENGINE = InnoDB DEFAULT CHARSET = utf8";
	sqlsession.execute(table);
	// ��������
	string fullSql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES('" + ZH_WORDS_GETTER("mysql.zh1") + "', '" + ZH_WORDS_GETTER("mysql.zh2") + "', '96')";
	string sql = "INSERT INTO `lib_test` (`first`, `last`, `age`) VALUES(?, ?, ?)";
	uint64_t id = sqlsession.executeInsert(fullSql);
	ASSERT_GT(id, 0);
	cout << "full   sql excute id is " << id << endl;
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh5"), 97);
	ASSERT_GT(id, 0);
	cout << "format sql excute id is " << id << endl;
	// ��ѯ����
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

	// ��������
	cout << "test transaction begin" << endl;
	sqlsession.beginTransaction();
	string usql = "UPDATE `lib_test` SET `first`='" + ZH_WORDS_GETTER("mysql.zh4") + "' WHERE `id`=2";
	int row = sqlsession.executeUpdate(usql);
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh6"), 98);
	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	cout << "test transaction end" << endl;

	// ����������ύһ������,�����Ƿ���������ύ����
	id = sqlsession.executeInsert(sql, "%s%s%i", ZH_WORDS_GETTER("mysql.zh3"), ZH_WORDS_GETTER("mysql.zh5"), 99);
	ASSERT_GT(id, 0);
	cout << "transaction end insert data id is " << id << endl;
}

TEST_F(MysqlTest, TestTM) {
	// ��������DAO
	LibTestDAO1 d1;
	LibTestDAO2 d2;

	// �������������
	TransactionManager tm(&d1, &d2);

	// ִ�е�һ��DAO����
	LibTest uObj;
	uObj.first = ZH_WORDS_GETTER("mysql.zh7");
	uObj.last = ZH_WORDS_GETTER("mysql.zh8");
	uObj.id = 1;
	int row = d1.update(uObj);
	// ִ�еڶ���DAO����
	row = row + d2.deleteById(6);
	// �ж��Ƿ��ύ����
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
