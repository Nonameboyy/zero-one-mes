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
#include "AddDelModService.h"
#include "../../dao/add-del-mod/AddDelModDAO.h"

uint64_t AddDelModService::saveData(const AddDelModDTO::Wrapper& dto)
{
	// 组装DO数据
	AddDelModDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_code, warehouse_code, Warehouse_name, warehouse_name, Location, location, Area, area, Charge, charge, Remark, remark)
		// 执行数据添加
		AddDelModDAO dao;
	return dao.insert(data);
}

bool AddDelModService::updateData(const AddDelModDTO::Wrapper& dto)
{
	// 组装DO数据
	AddDelModDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_code, warehouse_code, Warehouse_name, warehouse_name, Location, location, Area, area, Charge, charge, Remark, remark, Warehouse_id, warehouse_id)
		// 执行数据修改
		AddDelModDAO dao;
	return dao.update(data) == 1;
}

bool AddDelModService::removeData(uint64_t warehouse_id)
{
	AddDelModDAO dao;
	return dao.deleteById(warehouse_id) == 1;
}
