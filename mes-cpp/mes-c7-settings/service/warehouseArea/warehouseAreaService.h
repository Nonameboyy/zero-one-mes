#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _WAREHOUSE_AREA_SERVICE_
#define _WAREHOUSE_AREA_SERVICE_
#include <list>
#include "domain/vo/warehouseArea/warehouseAreaVO.h"
#include "domain/query/warehouseArea/warehouseAreaQuery.h"
#include "domain/dto/warehouseArea/warehouseAreaDTO.h"

/**
 * 库区服务实现，
 */
class warehouseAreaService
{
public:
	// 分页查询所有数据
	warehousePageDTO::Wrapper listAll(const WarehouseAreaQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const warehouseAreaListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const warehouseAreaListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_WAREHOUSE_AREA_SERVICE_