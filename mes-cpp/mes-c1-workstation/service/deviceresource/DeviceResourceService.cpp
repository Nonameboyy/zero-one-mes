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
#include "DeviceResourceService.h"
#include "../../dao/deviceresource/DeviceResourceDAO.h"

DeviceResourcePageDTO::Wrapper DeviceResourceService::listAll(const DeviceResourceQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DeviceResourcePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DeviceResourceDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DeviceResourceDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DeviceResourceDO sub : result)
	{
		auto dto = DeviceResourceDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, machineryId, MachineryId, equipmentCode, EquipmentCode, equipmentName, EquipmentName, quantity, Quantity)
			pages->addData(dto);
	}
	return pages;
}

uint64_t DeviceResourceService::saveData(const DeviceResourceDTO::Wrapper& dto)
{
	// 组装DO数据
	DeviceResourceDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,WorkstationId,workstationId,MachineryId,machineryId,EquipmentCode, equipmentCode, EquipmentName,equipmentName, Quantity, quantity)
		// 执行数据添加
		DeviceResourceDAO dao;
	return dao.insert(data);
}

bool DeviceResourceService::updateData(const DeviceResourceDTO::Wrapper& dto)
{
	// 组装DO数据
	DeviceResourceDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, DeviceResourceId, deviceResourceId, EquipmentCode, equipmentCode, EquipmentName, equipmentName, Count, count)
	// 执行数据修改
	DeviceResourceDAO dao;
	return dao.update(data) == 1;
}

bool DeviceResourceService::deleteData(uint64_t deviceResourceId)
{
	DeviceResourceDAO dao;
	return dao.deleteById(deviceResourceId) == 1;
}



