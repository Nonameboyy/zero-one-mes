#include "stdafx.h"
#include "PlanSubjectDAO.h"
#include "PlanSubjectMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PLANSUBJECT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->subCode) { \
	sql << " AND `subject_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->subCode.getValue("")); \
} \
if (query->subName) { \
	sql << " AND subject_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->subName.getValue("")); \
} \
if (query->subType) { \
	sql << " AND subject_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->subType.getValue("")); \
} 

uint64_t PlanSubjectDAO::count(const PlanSubjectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_subject";
	PLANSUBJECT_TERAM_PARSE(query, sql);

	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PlanSubjectTableDO> PlanSubjectDAO::selectWithPage(const PlanSubjectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT id,name,sex,age FROM dv_subject";
	PLANSUBJECT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PlanSubjectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PlanSubjectTableDO, PlanSubjectMapper>(sqlStr, mapper, params);
}

//std::list<PlanSubjectTableDO> PlanSubjectDAO::selectByName(const string & name)
//{
//	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	PlanSubjectMapper mapper;
//	return sqlSession->executeQuery<PlanSubjectTableDO, PlanSubjectMapper>(sql, mapper, "%s", name);
//}
//
//uint64_t PlanSubjectDAO::insert(const PlanSubjectTableDO & iObj)
//{
//	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
//	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
//}
//
//int PlanSubjectDAO::update(const PlanSubjectTableDO & uObj)
//{
//	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}
//
//int PlanSubjectDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `sample` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}