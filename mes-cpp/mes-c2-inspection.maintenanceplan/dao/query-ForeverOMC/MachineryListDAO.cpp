#include "stdafx.h"
#include "MachineryListDAO.h"
#include "MachineryListMapper.h"
#include <sstream>

#define MACHINERY_LIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_id) { \
	sql << " AND plan_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->plan_id.getValue(0)); \
} 

uint64_t MachineryListDAO::count(const MachineryListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_check_machinery";
	MACHINERY_LIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Dv_check_machineryDO> MachineryListDAO::selectWithPage(const MachineryListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id, machinery_code, machinery_name, machinery_brand, machinery_spec, remark FROM dv_check_machinery";
	MACHINERY_LIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MachineryListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_machineryDO, MachineryListMapper>(sqlStr, mapper, params);
}