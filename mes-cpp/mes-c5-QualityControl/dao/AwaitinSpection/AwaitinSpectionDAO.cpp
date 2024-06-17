#include "stdafx.h"
#include <sstream>
#include "AwaitinSpectionDAO.h"
#include "AwaitinSpectionMapper.h"

#define AwaitinSpection_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->feedback_code) { \
		sql << " AND feedback_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->feedback_code.getValue("")); \
} \
if (query->item_name) { \
		sql << " AND item_name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->item_name.getValue("")); \
} \
if (query->feedback_type) { \
		sql << " AND feedback_type=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->feedback_type.getValue("")); \
}

uint64_t AwaitinSpectionDAO::count(const AwaitinSpectionQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `pro_feedback`";
	AwaitinSpection_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<AwaitinSpectionDO> AwaitinSpectionDAO::selectAwaitinSpectionWithPage(const AwaitinSpectionQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id,feedback_type,feedback_code,item_code,item_name,quantity_uncheck,workstation_name FROM `pro_feedback`";
	AwaitinSpection_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AwaitinSpectionMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AwaitinSpectionDO, AwaitinSpectionMapper>(sqlStr, mapper, params);
}