#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/24 11:04:56

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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/vo/repaircontent/RepaircontentVO.h"
#include "../../domain/query/repaircontent/RepaircontentQuery.h"
#include "../../domain/dto/repaircontent/RepaircontentDTO.h"
#include "../../domain/dto/repaircontent/DeleteMultiRepaircontentDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class RepaircontentService
{
public:
	// ��ҳ��ѯ��������
	RepaircontentPageDTO::Wrapper listAll(const RepaircontentQuery::Wrapper& query);
	//ͨ����Ŀ���ƻ�ȡ����
	RepaircontentDTO::Wrapper getData(const RepaircontentQuery::Wrapper& id);
	// ��������
	uint64_t saveData(const AddRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const ModifyRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

