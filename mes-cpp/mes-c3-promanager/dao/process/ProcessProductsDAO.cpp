#include "stdafx.h"
#include "ProcessProductsDAO.h"
#include "../../dao/process/ProcessProductsMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->routeid) { \
	sql << " AND `route_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->routeid.getValue("")); \
} 

uint64_t ProcessProductsDAO::count(const ProcessProductsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_route_product";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ProRouteProductDO> ProcessProductsDAO::selectWithPage(const ProcessProductsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT route_id,item_code,item_name,specification,unit_of_measure FROM pro_route_product";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProcessProductsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProRouteProductDO, ProcessProductsMapper>(sqlStr, mapper, params);
}