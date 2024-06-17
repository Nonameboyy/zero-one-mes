#pragma once

#ifndef _WAREHOUSEMANAGEMENT_SERVICE_
#define _WAREHOUSEMANAGEMENT_SERVICE_
#include <list>
#include "domain/vo/WarehouseManagement/WarehouseManagementVO.h"
#include "domain/query/WarehouseManagement/WarehouseManagementQuery.h"
#include "domain/dto/WarehouseManagement/WarehouseManagementDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class WarehouseManagementService
{
public:
	// 分页查询所有数据
	WarehouseManagementPageDTO::Wrapper listAll(const WarehouseManagementQuery::Wrapper& query);
	//生成ecxcel
	string creatExcel(const WarehouseManagementQuery::Wrapper& query);
};

#endif // !_WAREHOUSEMANAGEMENT_SERVICE_

