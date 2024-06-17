#pragma once

#ifndef _PRODWORKORDERBOM_DAO_
#define _PRODWORKORDERBOM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"

/**
 * �������������ݿ����ʵ��
 */
class ProdWorkorderBomDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const ProWorkOrderBomDO& iObj);

	int deleteByItemId(uint64_t workorder_id);
};
#endif // !_PRODWORKORDERBOM_DAO_
