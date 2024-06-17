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

#ifndef _EQUIPMENT_TYPE_DAO_H_
#define _EQUIPMENT_TYPE_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/equipment-type/EquipmentTypeDO.h"

class EquipmentTypeDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const EquipmentTypeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	// �����ڸ����ж��ܷ�ɾ��������pid���ڴ���id�ĸ�������count����������0��˵�����豸����ӵ�������ͣ�Ϊ��ά�����ṹ������ɾ�����豸����
	uint64_t countByPId(uint64_t id);
};
#endif 
