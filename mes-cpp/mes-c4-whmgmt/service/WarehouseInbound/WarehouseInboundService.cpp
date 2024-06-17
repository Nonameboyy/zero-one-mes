#include "stdafx.h"
#include "WarehouseInboundService.h"
#include "../../dao/WarehouseInbound/WarehouseInboundDAO.h"

bool WarehouseInboundService::WarehouseInbound(const uint64_t& recpt_id)
{
	WarehouseInboundDAO dao;
	return dao.WarehouseInbound(recpt_id) == 1;
}