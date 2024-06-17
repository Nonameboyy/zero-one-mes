#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:42
 
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
#ifndef _DB_INIT_
#define _DB_INIT_

#include "ConnectionPool.h"

/**
 * ���ݿ����ö���
 */
class DBConfig
{
public:
	// �û���
	string user = "";
	// ����
	string pass = "";
	// ���ݿ���
	string db = "";
	// ����IP
	string host = "127.0.0.1";
	// ����˶˿�
	int port = 3306;
	// ���������
	int poolMaxSize = 25;
	DBConfig() {}
	DBConfig(string _user, string _pass, string _db, string _host, int _port, int _maxSize) :user(_user), pass(_pass), db(_db), host(_host), port(_port), poolMaxSize(_maxSize) {}
};

/**
 * ���ݿ��ʼ��
 */
class DbInit final
{
private:
	// ��������
	static ConnPool* connPool;
public:
	//************************************
	// Method:    initDbPool
	// FullName:  DbInit::initDbPool
	// Access:    public static 
	// Returns:   bool �Ƿ��ʼ���ɹ�
	// Description: ��ʼ�����ӳ�
	// Parameter: DBConfig config ���ݿ����ö���
	//************************************
	static bool initDbPool(DBConfig config);

	//************************************
	// Method:    getConnPool
	// FullName:  DbInit::getConnPool
	// Access:    public static 
	// Returns:   ConnPool*
	// Description: ��ȡ���ӳض���
	//************************************
	static ConnPool* getConnPool();

	//************************************
	// Method:    releasePool
	// FullName:  DbInit::releasePool
	// Access:    public static 
	// Returns:   void
	// Description: �ͷ����ӳ�
	//************************************
	static void releasePool();
};

#endif // !DB_INIT_