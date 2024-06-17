#pragma once
#ifndef _WAREHOUSE_DELETE_SERVICE_
#define _WAREHOUSE_DELETE_SERVICE_
#include <list>
#include "domain/dto/WarehouseDelete/WarehouseDeleteDTO.h"

/**
	删除单据服务实现
 */
class WarehouseDeleteService
{
public:
	//删除单据
	bool WarehouseDelete(const WarehouseDeleteDTO::Wrapper& dto);
};

#endif // !_WAREHOUSE_DELETE_SERVICE_
