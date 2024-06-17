#pragma once
#ifndef _WAREHOUSE_INBOUND_DAO_
#define _WAREHOUSE_INBOUND_DAO_
#include "BaseDAO.h"

/**
 * 示例表数据库操作实现
 */
class WarehouseInboundDAO : public BaseDAO
{
public:
	// 执行入库
	int WarehouseInbound(const uint64_t& recpt_id);
};
#endif // !_WAREHOUSE_INBOUND_DAO_#pragma once
