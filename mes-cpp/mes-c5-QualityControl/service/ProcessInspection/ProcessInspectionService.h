#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PROCESSINSPECTION_SERVICE_
#define _PROCESSINSPECTION_SERVICE_
#include "list"
#include "domain/dto/ProcessInspection/ProcessInspectionDTO.h"
#include "domain/query/ProcessInspection/ProcessInspectionQuery.h"
#include "domain/do/ProcessInspection/ProcessInspectionDO.h"
#include "Macros.h"
class ProcessInspectionService
{
public:
	//��������
	bool updateData(const ProcessInspectionDTO::Wrapper& dto);
	//��ҳ��ѯ
	ProcessInspectionQueryPageDTO::Wrapper listAll(const ProcessInspectionQuery::Wrapper& query);
	//��idɾ����¼
	bool remove(uint64_t id);
	//��������Ҫ������
	list<ProcessInspectionDO> listAllExort(const ProcessInspectionQuery::Wrapper& query);
	// ��ȡ���̼��鵥����
	ProcessInspectionDTO::Wrapper getInspectionDetails(const ProcessInspectionQuery::Wrapper& query);
	// ȷ�ϼ��鵥
	bool updateConfirmOrdersData(const ProcessInspectionDTO::Wrapper& dto);
	// ��ɼ��鵥
	bool updateFinishOrdersData(const ProcessInspectionDTO::Wrapper& dto);
	//��������
	uint64_t saveData(const ProcessInspectionDTO::Wrapper& dto);
};
#endif