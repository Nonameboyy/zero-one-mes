#pragma once
#ifndef _WAREHOUSEMANAGEMENT_DAO_
#define _WAREHOUSEMANAGEMENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/WarehouseManagement/WarehouseManagementDO.h"
#include "../../domain/query/WarehouseManagement/WarehouseManagementQuery.h"

/**
 * �����ݿ����ʵ��
 */
class WarehouseManagementDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const WarehouseManagementQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<WarehouseManagementDO> selectWithPage(const WarehouseManagementQuery::Wrapper& query);
	//��ѯ�����Ա�����excel�ļ�
	list<WarehouseManagementDO> QueryByExport(const WarehouseManagementQuery::Wrapper& query);


};
#endif // !_WAREHOUSEMANAGEMENT_DAO_
