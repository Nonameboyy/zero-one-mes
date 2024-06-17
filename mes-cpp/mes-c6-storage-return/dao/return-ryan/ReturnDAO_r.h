#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _RETURN_DAO_R_
#define _RETURN_DAO_R_
#include "BaseDAO.h"
#include "../../domain/do/return-ryan/ReturnDO_r.h"
#include "../../domain/query/return-ryan/ReturnQuery_r.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ReturnDAO_r : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReturnQuery_r::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReturnDO_r> selectWithPage(const ReturnQuery_r::Wrapper& query, int flag);
	// ͨ��������ѯ����
	list<ReturnDO_r> selectByName(const string& name);
	// ��������
	uint64_t insert(const ReturnDO_r& iObj);


	// �޸�����
	int update(const ReturnDO_r& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	// ͨ��ID�޸�״̬
	int updateStatusById(uint64_t id);

};
#endif // !_RETURN_DAO_
#pragma once
