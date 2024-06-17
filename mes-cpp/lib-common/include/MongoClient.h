#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/17 20:47:04

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
#ifndef _MONGOCLIENT_H_
#define _MONGOCLIENT_H_
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <string>
#include <memory>
#include <functional>
using namespace std;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;

/**
 * MongoDB�ͻ���
 */
class MongoClient
{
private:
	// �û���
	string m_username;
	// ����
	string m_password;
	// MongoDB��������ַ
	string m_host;
	// ���ݿ�
	string m_db;
	// MongoDB�������˿�
	string m_port;
	// ���������
	int m_max = 25;
	// ��С��������
	int m_min = 25;
	// ����Ƿ��Ѿ���ʼ��
	bool isInit;
	// ���������������������ʵ������
	static mongocxx::instance m_inst;
	// ���ӳض���
	shared_ptr<mongocxx::pool> m_pool;
	// ��ʼ�����ӳ�
	bool initPool();
public:
	//************************************
	// Method:    MongoClient
	// FullName:  MongoClient::MongoClient
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: const string & username �û���
	// Parameter: const string & password ����
	// Parameter: const string & host ��������ַ
	// Parameter: const string & db ���ݿ�
	// Parameter: const string & port �������˿ڣ�Ĭ��ֵ27017
	//************************************
	MongoClient(const string& username, const string& password, const string& host, const string& db, const string& port = "27017");
	//************************************
	// Method:    MongoClient
	// FullName:  MongoClient::MongoClient
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: const string & uri ���ӵ�ַ����ʽΪ��mongodb://�˺�:����@������ַ:�˿�/���ݿ�����
	//************************************
	explicit MongoClient(const string& uri);
	// �������������
	void setMax(int max);
	// ������С������
	void setMin(int min);
	//************************************
	// Method:    execute
	// FullName:  MongoClient::execute
	// Access:    public 
	// Returns:   bool
	// Description: ����һ��ִ�з���������֧�ֲ�����չ
	// Parameter: const string & collectionName ��������
	// Parameter: std::function<void mongocxx::collection*> callfun ��չִ�лص�����
	//************************************
	bool execute(const string& collectionName, std::function<void(mongocxx::collection*)> callfun);
	//************************************
	// Method:    addOne
	// FullName:  MongoClient::addOne
	// Access:    public 
	// Returns:   bsoncxx::types::bson_value::view
	// Description: ���һ������
	// Parameter: const string & collectionName ��������
	// Parameter: const bsoncxx::document::view & document �ĵ�����
	//************************************
	bsoncxx::types::bson_value::view addOne(const string& collectionName, const bsoncxx::document::view& document);
	//************************************
	// Method:    addMultiple
	// FullName:  MongoClient::addMultiple
	// Access:    public 
	// Returns:   int32_t ������������
	// Description: ��Ӷ�������
	// Parameter: const string & collectionName ��������
	// Parameter: const std::vector<bsoncxx::document::value> & documents �ĵ������б�
	//************************************
	int32_t addMultiple(const string& collectionName, const std::vector<bsoncxx::document::value>& documents);
};

#endif // _MONGOCLIENT_H_