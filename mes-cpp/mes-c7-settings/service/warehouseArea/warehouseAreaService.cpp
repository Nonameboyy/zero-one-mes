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
#include "warehouseAreaService.h"
#include "dao/warehouseArea/warehouseAreaDAO.h"
//根据给定的query返回查询对应的结果,类型为分页传输对象DTO
warehousePageDTO::Wrapper warehouseAreaService::listAll(const WarehouseAreaQuery::Wrapper& query)
{
	//构建返回对象pageDTO
	auto pages = warehousePageDTO::createShared();
	pages->pageIndex = query->pageIndex;//提取分页查询的参数:第几页
	pages->pageSize = query->pageSize;//提取每页大小

	//查询wm_storage_location表里符合query的数据条数
	warehouseAreaDAO dao;//调用DAO层:用于和数据库交互
	uint64_t count = dao.count(query);//满足条件的个数
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;//记录符合query的条数
	pages->calcPages();//根据pagesize计算一共有多少页
	list<warehouseAreaDO> result = dao.selectWithPage(query);
	//DO->DTO
	for (warehouseAreaDO sub : result)//DO携带的属性为:uint64_t location_id,string location_code,string location_name,uint64_t warehouse_id
	{//DTO属性:UInt64 area_id,String area_code,String area_name,Int32 area,String remark
		auto dto = warehouseAreaListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, area_id, AreaId, area_code, AreaCode, area_name, AreaName, area, Area, remark,Remark)
		pages->addData(dto);

	}
	return pages;
}

uint64_t warehouseAreaService::saveData(const warehouseAreaListDTO::Wrapper& dto)
{
	// 组装DO数据
	warehouseAreaDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AreaId, area_id, AreaCode, area_code, AreaName, area_name, WarehouseId, warehouse_id, Area, area, Remark, remark)
	// 执行数据添加
	warehouseAreaDAO dao;
	return dao.insert(data);
}

bool warehouseAreaService::updateData(const warehouseAreaListDTO::Wrapper& dto)
{
	// 组装DO数据
	warehouseAreaDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AreaId, area_id, AreaCode, area_code, AreaName, area_name, WarehouseId, warehouse_id, Area, area, Remark, remark)
		// 执行数据修改
	warehouseAreaDAO dao;
	return dao.update(data) == 1;
}

bool warehouseAreaService::removeData(uint64_t id)
{
	warehouseAreaDAO dao;
	return dao.deleteById(id) == 1;
}