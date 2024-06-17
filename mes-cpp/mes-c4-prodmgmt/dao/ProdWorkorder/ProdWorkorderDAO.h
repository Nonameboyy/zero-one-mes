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
	// 统计数据条数
	uint64_t count(const GetProdWorkorderListQuery::Wrapper& query);
	// BOM统计数据条数
	uint64_t countBom(const ProdWorkorderBomListQuery::Wrapper& query);
	// 分页查询数据
	list<GetProdWorkorderListDO> selectWithPage(const GetProdWorkorderListQuery::Wrapper& query);
	// 通过BOM行ID查询数据
	list<ProdWorkorderBomListDO> selectByBomId(const ProdWorkorderBomListQuery::Wrapper& query);
	// 通过工单ID查询数据
	list<ProdWorkorderInfoDO> selectByWorkorderId(const uint64_t& workorder_id);
	// 插入数据
	uint64_t insert(const AddProdWorkorderDO& iObj);
};
#endif // !_PRODWORKORDER_DAO_