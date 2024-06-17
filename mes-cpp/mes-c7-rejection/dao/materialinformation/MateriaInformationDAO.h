#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ������
 @Date: 2024/05/27 14:23:49

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
#ifndef _MATERIALINFORMATION_DAO_
#define _MATERIALINFORMATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/materialinformation/MaterialinformationDO.h"
#include "../../domain/query/materialinformation/MaterialInformationQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class MaterialinformationDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const MaterialInformationDO& iObj);
	// �޸�����
	int update(const MaterialInformationDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	// ͳ����������
	uint64_t count(const MaterialInformationQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MaterialInformationDO> selectWithPage(const MaterialInformationQuery::Wrapper& query);
};
#endif // !_MATERIALINFORMATION_DAO_