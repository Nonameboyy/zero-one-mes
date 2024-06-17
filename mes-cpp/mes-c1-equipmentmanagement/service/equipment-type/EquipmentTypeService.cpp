/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "EquipmentTypeService.h"
#include "../../dao/equipment-type/EquipmentTypeDAO.h"
#include "../../domain/do/equipment-type/EquipmentTypeDO.h"
 

bool EquipmentTypeService::updateData(const ModifyEquipmentTypeDTO::Wrapper& dto)
{
	EquipmentTypeDO data;
 
	data.setId(dto->id.getValue(0));
	data.setName(dto->name.getValue(""));
	data.setParentId(dto->parentId.getValue(0));
	data.setRemark(dto->remark.getValue(""));
	data.setEnable(dto->enable.getValue(true) == true ? "Y" : "N");
	data.setUpdateTime(dto->updateTime.getValue(""));

	EquipmentTypeDAO dao;

	return dao.update(data) == 1;
}

bool EquipmentTypeService::removeData(uint64_t id)
{
	EquipmentTypeDAO dao;
	return dao.deleteById(id) == 1;
}

bool EquipmentTypeService::countPId(uint64_t id)
{
	EquipmentTypeDAO dao;
	return dao.countByPId(id) == 0;
}