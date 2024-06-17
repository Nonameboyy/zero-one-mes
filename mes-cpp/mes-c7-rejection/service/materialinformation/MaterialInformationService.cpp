/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/19 11:13:11

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
#include "MaterialInformationService.h"
#include "dao/materialinformation/MateriaInformationDAO.h"

uint64_t MaterialInformationService::saveData(const MaterialInformationDTO::Wrapper& dto)
{
	MaterialInformationDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_Id, rt_id, Rt_Code, rt_code, Rt_Name, rt_name,
		Workororder_Id, workororder_id, Workororder_Code, workororder_code,
		Warehouse_Id, warehouse_id, Warehouse_Code, warehouse_code, Warehouse_Name, warehouse_name,
		Location_Id, location_id, Location_Code, location_code, Location_Name, location_name,
		Area_Id, area_id, Area_Code, area_code, Area_Name, area_name,
		Rt_Date, rt_date,
		Remark,remark);
	// 执行数据添加
	MaterialinformationDAO dao;
	return dao.insert(data);
	
}

bool MaterialInformationService::updateData(const MaterialInformationDTO::Wrapper& dto)
{
	MaterialInformationDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_Id, rt_id, Rt_Code, rt_code, Rt_Name, rt_name,
		Workororder_Id, workororder_id, Workororder_Code, workororder_code,
		Warehouse_Id, warehouse_id, Warehouse_Code, warehouse_code, Warehouse_Name, warehouse_name,
		Location_Id, location_id, Location_Code, location_code, Location_Name, location_name,
		Area_Id, area_id, Area_Code, area_code, Area_Name, area_name,
		Rt_Date, rt_date,
		Remark, remark);
	// 执行数据修改
	MaterialinformationDAO dao;
	return dao.update(data) == 1;
}

bool MaterialInformationService::removeData(uint64_t id)
{
	MaterialinformationDAO dao;
	return dao.deleteById(id) == 1;
}

MaterialInformationPageDTO::Wrapper MaterialInformationService::listAll(const MaterialInformationQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MaterialInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MaterialinformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MaterialInformationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MaterialInformationDO sub : result)
	{
		auto dto = MaterialInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rt_id, Rt_Id, rt_code, Rt_Code, rt_name, Rt_Name,
			workororder_id, Workororder_Id, workororder_code, Workororder_Code,
			warehouse_id, Warehouse_Id, warehouse_code, Warehouse_Code, warehouse_name, Warehouse_Name,
			location_id, Location_Id, location_code, Location_Code, location_name, Location_Name,
			area_id, Area_Id, area_code, Area_Code, area_name, Area_Name,
			rt_date, Rt_Date,
			remark, Remark);
		pages->addData(dto);

	}
	return pages;
}
