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
#ifndef _PURCHASERECEIVING_DAO_
#define _PURCHASERECEIVING_DAO_
#include "BaseDAO.h"
#include "../../domain/do/purchasereceiving/AddListDO.h"
#include "../../domain/do/purchasereceiving/ModifyListDO.h"
#include "../../domain/do/purchasereceiving/information/GetListDO.h"
#include "../../domain/query/information/GetListQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class purchasereceivingDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GetListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetListDO> selectWithPage(const GetListQuery::Wrapper& query);
	// ��������
	uint64_t insert(const AddListDO& iObj);
	// �޸�����
	int update(const ModifyListDO& uObj);
};
#endif // !_SAMPLE_DAO_
