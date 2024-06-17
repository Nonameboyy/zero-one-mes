#pragma once
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductDO.h"
#include "../../domain/query/process/ProcessProductsQuery.h"

/**
 * 获取工艺关联产品列表（条件+分页）
 */

class ProcessProductsDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProcessProductsQuery::Wrapper& query);
	// 分页查询数据
	list<ProRouteProductDO> selectWithPage(const ProcessProductsQuery::Wrapper& query);
};