/*
*
*/
#include "stdafx.h"
#include "Dv_check_subjectDAO.h"
#include "Dv_check_subjectMapper.h"
#include <sstream>


//---正式开始

//先定义一个简化的宏
#define SAMPLE_TERAM_PARSE_ID_DELETE_PLAN_SUBJECT(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->record_id) { \
	sql << " AND `record_id`=?"; \
	SQLPARAMS_PUSH(params, "ll", int64_t, query->record_id.getValue(0)); \
} 


std::list<DvCheckSubjectDO> Dv_check_subjectDAO::selectWithPage(const DeletePlanSubjectQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT record_id,plan_id,subject_id,subject_code,subject_name FROM dv_check_subject";
	sql << "SELECT * FROM dv_check_subject";
	SAMPLE_TERAM_PARSE_ID_DELETE_PLAN_SUBJECT(query, sql);
	Dv_check_subjectDeleteMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DvCheckSubjectDO, Dv_check_subjectDeleteMapper>(sqlStr, mapper, params);
}


int Dv_check_subjectDAO::dv_check_subjectDeleteById(int64_t id)
{
	string sql = "DELETE FROM `dv_check_subject` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ll", id);
}

