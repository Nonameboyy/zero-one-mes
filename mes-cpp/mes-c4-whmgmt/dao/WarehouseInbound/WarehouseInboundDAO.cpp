#include "stdafx.h"
#include "WarehouseInboundDAO.h"
#include <sstream>

//删除单据
int WarehouseInboundDAO::WarehouseInbound(const uint64_t& recpt_id)
{
	string sql = "UPDATE `wm_item_recpt` SET `status`='FINISHED', `update_time`=CURRENT_TIMESTAMP WHERE `recpt_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", recpt_id);
}

