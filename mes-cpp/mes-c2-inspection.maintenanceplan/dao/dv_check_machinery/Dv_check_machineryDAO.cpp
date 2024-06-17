/*
*
*/
#include "stdafx.h"
#include "Dv_check_machineryDAO.h"
#include "Dv_check_machineryMapper.h"
#include <sstream>


//先定义一个简化的宏
#define SAMPLE_TERAM_PARSE_ID_DELETE_PLAN_MACHINERY(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->record_id) { \
	sql << " AND `record_id`=?"; \
	SQLPARAMS_PUSH(params, "ll", int64_t, query->record_id.getValue(0)); \
} 


std::list<Dv_check_machineryDO> Dv_check_machineryDAO::selectWithPage(const DeletePlanMachineryQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT record_id,plan_id,subject_id,subject_code,subject_name FROM dv_check_subject";
	sql << "SELECT * FROM dv_check_machinery";
	SAMPLE_TERAM_PARSE_ID_DELETE_PLAN_MACHINERY(query, sql);
	Dv_check_machineryDeleteMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_machineryDO, Dv_check_machineryDeleteMapper>(sqlStr, mapper, params);
}


int Dv_check_machineryDAO::dv_check_machineryDeleteById(int64_t id)
{
	string sql = "DELETE FROM `dv_check_machinery` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ll", id);
}