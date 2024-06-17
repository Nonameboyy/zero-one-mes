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
#include "EquipmentService.h"
#include "../../dao/equipment/EquipmentDAO.h"

list<EquipmentTypeDO> EquipmentService::listTypeAll()
{
	EquipmentDAO dao;
	// 查询设备类型总列表
	list<EquipmentTypeDO> result = dao.selectTypeList();
	return result;
}

EquipmentPageDTO::Wrapper EquipmentService::listAll(const EquipmentQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = EquipmentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EquipmentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<EquipmentDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (EquipmentDO sub : result)
	{
		auto dto = EquipmentDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, equipmentId, EquipmentId, equipmentCode, EquipmentCode, equipmentName, EquipmentName, brand, Brand,
			specificationsAndModels, SpecificationsAndModels, workshopName, WorkshopName, createTime, CreateTime)
			pages->addData(dto);

	}
	return pages;
}


