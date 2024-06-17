#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:30
 
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
#ifndef __CONNECTION_POOL_H__
#define __CONNECTION_POOL_H__

#include "./mysql/jdbc.h"
#include <list>
#include <string>
#include <mutex>

using namespace std;
using namespace sql;
/**
 * ����һ�����ݿ����ӳ���
 */
class ConnPool final
{
public:
	// �����ʼ��
	ConnPool(string url, string user, string password, int maxSize);
	// �����ͷ��ڴ�
	~ConnPool();
	// ��ȡ���ݿ�����
	Connection* GetConnection();
	// �����ݿ����ӷŻص����ӳص�������
	void ReleaseConnection(Connection* conn);
	// ��ȡ��ǰ���ӳش�С
	int getPoolSize();
private:
	// ��ǰ�ѽ��������ݿ���������
	int curSize;
	// ���ӳض����������ݿ�������
	int maxSize;
	// �û���
	string username;
	// ����
	string password;
	// ���ӵ�ַ����tcp://localhost:3306/db
	string url;
	// ������������
	Driver* driver;
	// ���ӳ�����
	list<Connection*> connList;
	// �߳���
	mutex lock;
	
	// ����һ������
	Connection* CreateConnection();
	// ��ʼ�����ݿ����ӳ�
	void InitConnection(int iInitialSize);
	// �������ݿ����Ӷ���
	void DestoryConnection(Connection* conn);
	// �������ݿ����ӳ�
	void DestoryConnPool();
};

#endif /*_CONNECTION_POOL_H */
