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
#ifndef _PROCESSINSPECTION_DAO_
#define _PROCESSINSPECTION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProcessInspection/ProcessInspectionDO.h"
#include "../../domain/query/ProcessInspection/ProcessInspectionQuery.h"

class ProcessInspectionDAO : public BaseDAO
{
public:
	// 
	int update(const ProcessInspectionDO& uObj);
	//flag:1�ǵ���,0�ǲ�ѯ
	list<ProcessInspectionDO> select(const ProcessInspectionQuery::Wrapper& query,int flag);

	uint64_t count(const ProcessInspectionQuery::Wrapper& query);

	bool deleteById(uint64_t id);
	// ��ȡ���̼�������
	std::list<ProcessInspectionDO> selectInspectionDetails(const ProcessInspectionQuery::Wrapper& query);
	// ȷ�ϼ��鵥
	int updateConfirmOrders(const ProcessInspectionDO& uObj);
	// ��ɼ��鵥
	int updateFinishOrders(const ProcessInspectionDO& uObj);
	//��������
	uint64_t insert(const ProcessInspectionDO& iObj);
};
#endif // !_SAMPLE_DAO_
