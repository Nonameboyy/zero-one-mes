#include "stdafx.h"
#include "PickDAO.h"
#include "PickMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PICK_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->issueCode) { \
	sql << " AND `issue_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->issueCode.getValue("")); \
} \
if (query->issueName) { \
	sql << " AND issue_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->issueName.getValue("")); \
} \
if (query->workorderCode) { \
	sql << " AND workorder_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorderCode.getValue("")); \
} 

//uint64_t PickDAO::count(const PickQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM wm_issue_header";
//	PICK_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

//std::list<PickDO> PickDAO::selectWithPage(const PickQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT issue_code,issue_name,workorder_code FROM wm_issue_header";
//	PICK_TERAM_PARSE(query, sql);
//	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
//	PickMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<PickDO, PickMapper>(sqlStr, mapper, params);
//}



uint64_t PickDAO::insert(const PickDO& iObj)
{
	string sql = "INSERT INTO `wm_issue_header` (`issue_code`, `issue_name`, `workorder_code`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s", iObj.getIcode(), iObj.getIname(), iObj.getWcode());
}

int PickDAO::update(const PickDO& uObj)
{
	string sql = "UPDATE `wm_issue_header` SET `issue_code`=?, `issue_name`=?, `workorder_code`=? WHERE `issue_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%ll", uObj.getIcode(), uObj.getIname(), uObj.getWcode(), uObj.getId());
}

