#pragma once
#ifndef _WAREHOUSE_EXPORT_SERVICE_
#define _WAREHOUSE_EXPORT_SERVICE_
#include <list>
#include "domain/dto/WarehouseExport/WarehouseExportDTO.h"

/**
	删除单据服务实现
 */
class WarehouseExportService
{
public:
	//删除单据
	string WarehouseExport();
};

#endif // !_WAREHOUSE_EXPORT_SERVICE_
