#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:08:43
 
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
#ifndef _TRANSACTION_MANAGER_
#define _TRANSACTION_MANAGER_
#include "BaseDAO.h"

/**
 * ����һ�����������
 */
class TransactionManager final
{
private:
	// ��¼һ�����ڹ��������DAO����
	BaseDAO* transDao;
	// ����Sqlsession
	void settingSqlsession(BaseDAO* transDao, BaseDAO* changeDao) {
		changeDao->setSqlSession(transDao->getSqlSession());
		changeDao->setAutoRelease(false);
	}
public:
	//************************************
	// Method:    TransactionManager
	// FullName:  TransactionManager::TransactionManager
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��,ʹ�ø������������ʱ�򣬾��Ѿ�����������
	// Parameter: BaseDAO * first ���������DAO����
	// Parameter: DAO ... args �����������DAO����
	//************************************
	template <class ... DAO>
	TransactionManager(BaseDAO* transDao, DAO ... args) {
		// �޸ı��й�DAO��sqlsession
		initializer_list<int>{(settingSqlsession(transDao, std::forward<DAO>(args)), 0)...};
		// ��������
		this->transDao = transDao;
		this->transDao->getSqlSession()->beginTransaction();
	}
	// �ύ����
	void commit() {
		this->transDao->getSqlSession()->commitTransaction();
	}
	// �ع�����
	void rollback() {
		this->transDao->getSqlSession()->rollbackTransaction();
	}
};
#endif // !_TRANSACTION_MANAGER_

