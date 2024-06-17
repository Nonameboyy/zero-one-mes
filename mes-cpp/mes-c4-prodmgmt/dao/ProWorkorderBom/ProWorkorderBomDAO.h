#pragma once

#ifndef _PRODWORKORDERBOM_DAO_
#define _PRODWORKORDERBOM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"

/**
 * 生产工单表数据库操作实现
 */
class ProdWorkorderBomDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const ProWorkOrderBomDO& iObj);

	int deleteByItemId(uint64_t workorder_id);
};
#endif // !_PRODWORKORDERBOM_DAO_
