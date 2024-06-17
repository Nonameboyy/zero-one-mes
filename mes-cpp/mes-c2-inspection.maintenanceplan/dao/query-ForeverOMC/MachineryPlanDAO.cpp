#include "stdafx.h"
#include "MachineryPlanDAO.h"
#include "MachineryPlanMapper.h"
#include <sstream>

#define MACHINERY_PLAN_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_code) { \
	sql << " AND plan_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_code.getValue("")); \
} \
if (query->plan_name) { \
	sql << " AND plan_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_name.getValue("")); \
} \
if (query->plan_type) { \
	sql << " AND plan_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_type.getValue("")); \
} \
if (query->status) { \
	sql << " AND status=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue("")); \
}

uint64_t MachineryPlanDAO::count(const MachineryPlanQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_check_plan";
	MACHINERY_PLAN_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Dv_check_planDO> MachineryPlanDAO::selectWithPage(const MachineryPlanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT plan_id, plan_code, plan_name, plan_type, start_date, end_date, cycle_type, cycle_count, status FROM dv_check_plan";
	MACHINERY_PLAN_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MachineryPlanMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_planDO, MachineryPlanMapper>(sqlStr, mapper, params);
}

std::list<Dv_check_planDO> MachineryPlanDAO::selectByPlanId(const MachineryPlanDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT plan_id, plan_code, plan_name, plan_type, start_date, end_date, cycle_type, cycle_count, status, remark FROM dv_check_plan WHERE plan_id=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->plan_id.getValue(0));
	MachineryPlanDetailsMapper mapper;
	string sqlStr = sql.str();
	std::list<Dv_check_planDO> res = sqlSession->executeQuery<Dv_check_planDO, MachineryPlanDetailsMapper>(sqlStr, mapper, params);
	return res;
}