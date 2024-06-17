#pragma once
#ifndef _PRODWORKORDER_DAO_
#define _PRODWORKORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../../domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderBomListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderInfoDO.h"

#include "../../domain/query/ProdWorkorder/GetProdWorkorderListQuery.h"
#include "../../domain/query/ProdWorkorder/ProdWorkorderBomListQuery.h"

class ProdWorkorderDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const GetProdWorkorderListQuery::Wrapper& query);
	// BOMͳ����������
	uint64_t countBom(const ProdWorkorderBomListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetProdWorkorderListDO> selectWithPage(const GetProdWorkorderListQuery::Wrapper& query);
	// ͨ��BOM��ID��ѯ����
	list<ProdWorkorderBomListDO> selectByBomId(const ProdWorkorderBomListQuery::Wrapper& query);
	// ͨ������ID��ѯ����
	list<ProdWorkorderInfoDO> selectByWorkorderId(const uint64_t& workorder_id);
	// ��������
	uint64_t insert(const AddProdWorkorderDO& iObj);
};
#endif // !_PRODWORKORDER_DAO_