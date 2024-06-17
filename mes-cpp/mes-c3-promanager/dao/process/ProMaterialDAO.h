#pragma once
#ifndef _PROMATERIAL_DAO_
#define _PROMATERIAL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductBomDO.h"
#include "../../domain/query/process/ProMaterialQuery.h"


/**
 * 产品制成物料表数据库操作实现
 */
class ProMaterialDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProMaterialQuery::Wrapper& query);
	// 分页查询数据
	list<ProRouteProductBomDO> selectWithPage(const ProMaterialQuery::Wrapper& query);
	// 通过产品物料编码查询数据
	list<ProRouteProductBomDO> selectByItemCode(const string& item_code);
	// 通过产品物料名称查询数据
	list<ProRouteProductBomDO> selectByItem_Name(const string& item_name);
	
};
#endif // !_PROMATERIAL_DAO_
