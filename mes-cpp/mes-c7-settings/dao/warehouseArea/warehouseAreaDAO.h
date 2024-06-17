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
#ifndef _WAREHOUSE_AREA_DAO_
#define _WAREHOUSE_AREA_DAO_
#include "BaseDAO.h"
#include "domain/do/warehouseArea/warehouseAreaDO.h"
#include "domain/query/warehouseArea/warehouseAreaQuery.h"

/**
 * �Ա�wm_storage_location�����ݿ����ʵ��
 */
class warehouseAreaDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const WarehouseAreaQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<warehouseAreaDO> selectWithPage(const WarehouseAreaQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<SampleDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const warehouseAreaDO& iObj);
	// �޸�����
	int update(const warehouseAreaDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
