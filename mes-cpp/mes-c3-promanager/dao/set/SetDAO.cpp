#include "stdafx.h"
#include "SetDAO.h"
#include "SetMapper.h"
#include <sstream>
#include "../../lib-common/include/SimpleDateTimeFormat.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->processId) { \
	sql << " AND `process_id`=?"; \
	SQLPARAMS_PUSH(params, "i",int, query->processId.getValue(1)); \
}

//定义条件解析宏，减少重复代码
#define XSL_TERM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->processCode) { \
	sql << " AND `process_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->processCode.getValue("")); \
} \
if (query->processName) { \
	sql << " AND process_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->processName.getValue("")); \
} \
if (query->enableFlag) { \
	sql << " AND enable_flag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->enableFlag.getValue("")); \
}


uint64_t SetDAO::insertSet(const ProProcessDO & iObj, const string username)
{
	string sql = "INSERT INTO pro_process (`process_code`,`process_name`, `enable_flag`, `attention`,`remark`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", iObj.getProcessCode(), iObj.getProcessName(), iObj.getEnableFlag(),
		iObj.getAttention(), iObj.getRemark(), username, SimpleDateTimeFormat::format());
}

int SetDAO::updateSet(const ProProcessDO & uObj, const string username)
{
	string sql = "UPDATE pro_process SET `process_code`= ?, `process_name`= ?, `enable_flag`= ?, `attention`= ?, `remark`= ?, `update_by`=?, `update_time`=? WHERE `process_id`= ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%ull", uObj.getProcessCode(), uObj.getProcessName(),
		uObj.getEnableFlag(), uObj.getAttention(), uObj.getRemark(), uObj.getProcessId(), username, SimpleDateTimeFormat::format());
}
uint64_t SetDAO::count(const SetProListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_process_content";
	SAMPLE_TERAM_PARSE(query, sql)
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
};

std::list<ProProcessContentDO> SetDAO::selectWithPage(const SetProListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `process_id`,`order_num`,`content_text`,`device`,`material`,`doc_url`,`remark` FROM pro_process_content";
	SAMPLE_TERAM_PARSE(query, sql)
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SetStepMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessContentDO, SetStepMapper>(sqlStr, mapper, params);
};

std::list<ProProcessContentDO> SetDAO::selectById(const uint64_t& id)
{
	string sql = "SELECT `order_num`,`content_text`,`material`,`device`,`remark` FROM pro_process_content WHERE `process_id` LIKE CONCAT('%',?,'%')";
	SetStepMapper mapper;
	return sqlSession->executeQuery<ProProcessContentDO, SetStepMapper>(sql, mapper, "%ull", id);
};

uint64_t SetDAO::insertstepSet(const ProProcessContentDO& iObj, const string username)
{
	string sql = "INSERT INTO `pro_process_content` (`process_id`,`order_num`,`content_text`, `device`, `material`,`doc_url`,`remark`,`create_by`,`create_time`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%i%s%s%s%s%s%s%s", iObj.getProcessId(), iObj.getOrderNum(), iObj.getContentText(), iObj.getDevice(),
		iObj.getMaterial(), iObj.getDocUrl(), iObj.getRemark(), username, SimpleDateTimeFormat::format());
}

uint64_t SetDAO::countForProcess(const ProListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_process";
	XSL_TERM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
std::list<ProProcessDO> SetDAO::selectWithPageForProcess(const ProListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT process_id,process_code, process_name, enable_flag, remark FROM pro_process";
	XSL_TERM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessDO, ProListMapper>(sqlStr, mapper, params);
}
std::list<ProProcessDO> SetDAO::selectProNameList()
{
	stringstream sql;
	sql << "SELECT `process_id`,`process_code`,`process_name` FROM pro_process";
	ProNameListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessDO, ProNameListMapper>(sqlStr, mapper);
}
std::list<ProProcessDO> SetDAO::selectByid(const ProDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select `process_id`,`process_code`, `process_name`, `attention`, `enable_flag`, `remark` from pro_process";
	SqlParams params; sql << " WHERE 1=1"; 
	if (query->processId) {
		sql << " AND `process_id`=?"; 
		params.emplace_back(SqlParam("ull", std::make_shared<uint64_t>(query->processId.getValue(1))));
	}
	ProDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessDO, ProDetailMapper>(sqlStr, mapper, params);
}

list<ProProcessContentDO> SetDAO::selectWithStepExport(const SetProListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `process_id`,`order_num`,`content_text`,`device`,`material`,`doc_url` FROM pro_process_content WHERE `process_id` =";
	sql << query->processId;
	SetStepExportMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessContentDO, SetStepExportMapper>(sqlStr, mapper);
}
