#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _EQUIPMENT_DO_
#define _EQUIPMENT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class EquipmentDO
{
	// �豸id
	CC_SYNTHESIZE(uint64_t, equipmentId, EquipmentId)
	// �豸����
	CC_SYNTHESIZE(string, equipmentCode, EquipmentCode);
	// �豸����
	CC_SYNTHESIZE(string, equipmentName, EquipmentName);
	// Ʒ��
	CC_SYNTHESIZE(string, brand, Brand);
	// ����ͺ�
	CC_SYNTHESIZE(string, specificationsAndModels, SpecificationsAndModels);
	// ��������
	CC_SYNTHESIZE(string, workshopName, WorkshopName);
	// �豸״̬
	CC_SYNTHESIZE(string, equipmentStatus, EquipmentStatus);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
public:
	EquipmentDO() {
		equipmentId = 0;
		equipmentCode = "";
		equipmentName = "";
		brand = "";
		specificationsAndModels = "";
		equipmentStatus = "";
		createTime = "";
	}
};

#endif // !_EQUIPMENT_DO_
