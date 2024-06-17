#pragma once
#ifndef _WAREHOUSE_DELETE_DAO_
#define _WAREHOUSE_DELETE_DAO_
#include "BaseDAO.h"

/**
 * 示例表数据库操作实现
 */
class WarehouseDeleteDAO : public BaseDAO
{
public:
	//删除单据
	int deleteById(const std::vector<uint64_t> recpt_id);
};
#endif // !_WAREHOUSE_DELETE_DAO_