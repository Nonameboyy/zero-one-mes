#pragma once

#ifndef _WAREHOUSEMANAGEMENT_SERVICE_
#define _WAREHOUSEMANAGEMENT_SERVICE_
#include <list>
#include "domain/vo/WarehouseManagement/WarehouseManagementVO.h"
#include "domain/query/WarehouseManagement/WarehouseManagementQuery.h"
#include "domain/dto/WarehouseManagement/WarehouseManagementDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class WarehouseManagementService
{
public:
	// ��ҳ��ѯ��������
	WarehouseManagementPageDTO::Wrapper listAll(const WarehouseManagementQuery::Wrapper& query);
	//����ecxcel
	string creatExcel(const WarehouseManagementQuery::Wrapper& query);
};

#endif // !_WAREHOUSEMANAGEMENT_SERVICE_

