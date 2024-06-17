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
	// 修改数据
	int update(const EquipmentTypeDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 【用于辅助判断能否删除】计算pid等于传参id的个数，当count个数不等于0，说明此设备类型拥有子类型，为了维护树结构，不能删除该设备类型
	uint64_t countByPId(uint64_t id);
};
#endif 
