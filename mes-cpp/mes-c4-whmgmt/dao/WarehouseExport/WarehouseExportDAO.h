#pragma once
#ifndef _WAREHOUSE_EXPORT_DAO_
#define _WAREHOUSE_EXPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/WarehouseExport/WarehouseExportDO.h"
/**
 * 示例表数据库操作实现
 */
class WarehouseExportDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count();
	// 分页查询数据
	list<WarehouseExportDO> WarehouseExport();
};

#endif // !_WAREHOUSE_EXPORT_DAO_