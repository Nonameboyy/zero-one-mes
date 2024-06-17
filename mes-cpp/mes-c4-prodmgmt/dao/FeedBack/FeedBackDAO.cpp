#include "stdafx.h"
#include "FeedBackDAO.h"
#include "FeedBackMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define FEEDBACK_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->feedback_type) { \
	sql << " AND `feedback_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->feedback_type.getValue("")); \
} \
if (query->workstation_name) { \
	sql << " AND `workstation_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workstation_name.getValue("")); \
} \
if (query->workorder_code) { \
	sql << " AND `workorder_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
} \
if (query->item_code) { \
	sql << " AND `item_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_code.getValue("")); \
} \
if (query->item_name) { \
	sql << " AND `item_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_name.getValue("")); \
} \
if (query->specification) { \
	sql << " AND `specification`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->specification.getValue("")); \
} \
if (query->quantity_feedback) { \
	sql << " AND `feedback_quantity`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->quantity_feedback.getValue(0)); \
} \
if (query->user_name) { \
	sql << " AND `user_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->user_name.getValue("")); \
} \
if (query->feedback_time) { \
	sql << " AND `feedback_time`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->feedback_time.getValue("")); \
} \
if (query->record_user) { \
	sql << " AND `record_user`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->record_user.getValue("")); \
} \
if (query->_status) { \
	sql << " AND `status`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->_status.getValue("")); \
}


uint64_t FeedBackDAO::count(const FeedBackQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_feedback";
	FEEDBACK_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<FeedBackDO> FeedBackDAO::selectWithPage(const FeedBackQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT feedbackType,feedbackName FROM pro_feedback";
	FEEDBACK_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FeedBackMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FeedBackDO, FeedBackMapper>(sqlStr, mapper, params);
}

std::list<FeedBackDO> FeedBackDAO::selectByName(const string& name)
{
	string sql = "SELECT feedback_type,feedback_name FROM pro_feedback WHERE `name` LIKE CONCAT('%',?,'%')";
	FeedBackMapper mapper;
	return sqlSession->executeQuery<FeedBackDO, FeedBackMapper>(sql, mapper, "%s", name);
}

