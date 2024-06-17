#include "stdafx.h"
#include "MachinerySubjectDAO.h"
#include "MachinerySubjectMapper.h"
#include <sstream>

#define MACHINERY_SUBJECT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_id) { \
	sql << " AND plan_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->plan_id.getValue(0)); \
} 

uint64_t MachinerySubjectDAO::count(const MachinerySubjectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_check_subject";
	MACHINERY_SUBJECT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<DvCheckSubjectDO> MachinerySubjectDAO::selectWithPage(const MachinerySubjectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id, subject_code, subject_name, subject_type, subject_content, subject_standard FROM dv_check_subject";
	MACHINERY_SUBJECT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MachinerySubjectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DvCheckSubjectDO, MachinerySubjectMapper>(sqlStr, mapper, params);
}