#pragma once
#ifndef _WAREHOUSE_INBOUND_SERVICE_
#define _WAREHOUSE_INBOUND_SERVICE_
#include <list>
#include "domain/dto/WarehouseInbound/WarehouseInboundDTO.h"

/**
	执行入库服务实现
 */
class WarehouseInboundService
{
public:
	//执行入库
	bool WarehouseInbound(const uint64_t& recpt_id);
};

#endif // !_WAREHOUSE_INBOUND_SERVICE_
