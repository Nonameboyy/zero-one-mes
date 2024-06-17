#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/5/27 14:23:49

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
#ifndef _MATDAO_H_
#define _MATDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/material/MatDO.h"
#include "../../domain/query/material/GetReturnListQuery.h"

/**
 * ��Ӧ���˻������ݿ����ʵ��
 */
class MatDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count1(const GetReturnListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MatlistDO> selectWithPage1(const GetReturnListQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<MatlistDO> selectByName1(const string& name);
	// ��������
	uint64_t insert1(const MatlistDO& iObj);
	// ��������
	uint64_t insert2(const MatlineDO& iObj);
	// �޸�����
	int update1(const MatlistDO& uObj);
	// ͨ��IDɾ������
	int deleteById1(uint64_t id);
};
#endif // !_MATDAO_H_
