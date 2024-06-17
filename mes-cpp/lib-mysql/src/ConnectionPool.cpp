/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:10:25
 
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
#include "../include/ConnectionPool.h"
#include <stdexcept>
#include <exception>
#include <stdio.h>

// ���ݿ����ӳصĹ��캯��
ConnPool::ConnPool(string url, string userName, string password, int maxSize)
{
	this->maxSize = maxSize;
	this->curSize = 0;
	this->username = userName;
	this->password = password;
	this->url = url;

	try
	{
		this->driver = sql::mysql::get_mysql_driver_instance();
	}
	catch (sql::SQLException& e)
	{
		printf("get driver error. msg=%s\n", e.what());
	}
	catch (std::runtime_error& e)
	{
		printf("[ConnPool] run time error. msg=%s\n", e.what());
	}

	// �ڳ�ʼ�����ӳ�ʱ������һ�����������ݿ�����
	this->InitConnection(maxSize < 2 ? maxSize : maxSize / 2);
}

// ��ʼ�����ݿ����ӳأ��������������һ�����������
void ConnPool::InitConnection(int iInitialSize)
{
	Connection* conn;
	lock.lock();

	for (int i = 0; i < iInitialSize; i++)
	{
		conn = this->CreateConnection();
		if (conn)
		{
			connList.push_back(conn);
			++(this->curSize);
		}
		else
		{
			printf("Init connection<%d> error.\n", i + 1);
			break;
		}
	}

	lock.unlock();
}

// ����������һ������
Connection* ConnPool::CreateConnection()
{
	Connection* conn;
	try
	{
		// ��������
		conn = driver->connect(this->url, this->username, this->password);
		return conn;
	}
	catch (sql::SQLException& e)
	{
		printf("create connection error. msg=%s\n", e.what());
		return NULL;
	}
	catch (std::runtime_error& e)
	{
		printf("[CreateConnection] run time error. msg=%s\n", e.what());
		return NULL;
	}
}

// �����ӳ��л��һ������
Connection* ConnPool::GetConnection()
{
	Connection* con;
	lock.lock();

	// ���ӳ������л�������
	if (connList.size() > 0)
	{
		// ��ȡ��һ������
		con = connList.front();
		// �Ƴ���һ������
		connList.pop_front();
		// �жϻ�ȡ�������ӵĿ�����
		// ��������Ѿ����رգ�ɾ�������½���һ��
		if (con->isClosed() || !con->isValid())
		{
			delete con;
			con = this->CreateConnection();
			// �������Ϊ�գ�˵���������ӳ���
			if (con == NULL)
			{
				// ��������ȥ�����������
				--curSize;
			}
		}

		lock.unlock();
		return con;
	}
	// ���ӳ�������û������
	else
	{
		// ��ǰ�Ѵ�����������С��������������򴴽��µ�����
		if (curSize < maxSize)
		{
			con = this->CreateConnection();
			if (con)
			{
				++curSize;
				lock.unlock();
				return con;
			}
			else
			{
				lock.unlock();
				return NULL;
			}
		}
		// ��ǰ�������������Ѿ��ﵽ���������
		else
		{
			perror("[GetConnection] connections reach the max number. \n");
			lock.unlock();
			return NULL;
		}
	}
}

// �ͷ����ݿ����ӣ��������ӷŻص����ӳ���
void ConnPool::ReleaseConnection(sql::Connection* conn)
{
	if (conn)
	{
		lock.lock();

		connList.push_back(conn);

		lock.unlock();
	}
}

// ��ȡ��ǰ���ӳش�С
int ConnPool::getPoolSize()
{
	return curSize;
}

// ���ݿ����ӳص���������
ConnPool::~ConnPool()
{
	this->DestoryConnPool();
}

// �������ӳأ���Ҫ���������ӳص�������
void ConnPool::DestoryConnPool()
{
	list<Connection*>::iterator itCon;
	lock.lock();

	for (itCon = connList.begin(); itCon != connList.end(); ++itCon)
	{
		// �������ӳ��е�����
		this->DestoryConnection(*itCon);
	}
	curSize = 0;

	// ������ӳ��е�����
	connList.clear();

	lock.unlock();
}

// �������ݿ�����
void ConnPool::DestoryConnection(Connection* conn)
{
	if (conn)
	{
		try
		{
			// �ر�����
			conn->close();
		}
		catch (sql::SQLException& e)
		{
			printf("%s\n", e.what());
		}
		catch (std::exception& e)
		{
			printf("%s\n", e.what());
		}
		// ɾ������
		delete conn;
	}
}