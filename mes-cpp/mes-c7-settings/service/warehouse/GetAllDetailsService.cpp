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
#include "../../dao/warehouse/GetAllDetailsDAO.h"
#include"GetAllDetailsService.h"
GetAllDetailsDTO::Wrapper GetAllDetailsService::finddetails(const GetAllDetailsQuery::Wrapper& query)
{
	// 构建返回对象
	GetAllDetailsDAO dao;
	auto dto = GetAllDetailsDTO::createShared();
	// 查询数据
	list<Wm_WarehouseDO> res = dao.selectdetails(query);
	// 将DO转换成DTO
	for (Wm_WarehouseDO sub : res) {
		dto->warehouse_id = sub.getWarehouse_id();
		dto->warehouse_code = sub.getWarehouse_code();
		dto->warehouse_name = sub.getWarehouse_name();
		dto->location = sub.getLocation();
		dto->area = sub.getArea();
		dto->charge = sub.getCharge();
		dto->remark = sub.getRemark();
		dto->create_by = sub.getCreate_by();
		dto->create_time = sub.getCreate_time();
		dto->update_by = sub.getUpdate_by();
		dto->update_time = sub.getUpdate_time();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_code, Warehouse_code);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_name, Warehouse_name, location, Location);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, area, Area, charge, Charge, remark, Remark)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, create_by, Create_by, create_time, Create_time);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, update_by, Update_by, update_by, Update_by);
	}
	return dto;
}


