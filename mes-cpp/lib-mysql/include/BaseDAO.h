#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:10
 
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
#ifndef _ABSTRACT_DAO_
#define _ABSTRACT_DAO_
#include "SqlSession.h"

/**
 * ����һ��������DAO�࣬���������������DAO����Ҫ�̳���
 */
class BaseDAO
{
private:
	// �Ƿ��Զ��ͷ�SQLSession
	bool isAutoRelease;
protected:
	// ����һ��SqlSession
	SqlSession* sqlSession;
public:
	BaseDAO();
	virtual ~BaseDAO();
	// ��ȡSqlSession
	SqlSession* getSqlSession();
	// ����SqlSession
	void setSqlSession(SqlSession* session);
	// �����Ƿ��Զ��ͷ�SqlSession
	void setAutoRelease(bool release);
};

#endif // !_ABSTRACT_DAO_
