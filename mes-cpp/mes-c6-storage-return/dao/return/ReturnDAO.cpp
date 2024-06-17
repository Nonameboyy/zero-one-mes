#include "stdafx.h"
#include "ReturnDAO.h"
#include "ReturnMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define RETURN_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->returnCode) { \
	sql << " AND `rt_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->returnCode.getValue("")); \
} \
if (query->returnName) { \
	sql << " AND rt_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->returnName.getValue("")); \
} \
if (query->purchaseCode) { \
	sql << " AND po_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->purchaseCode.getValue("")); \
} \
if (query->vendorName) { \
	sql << " AND vendor_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendorName.getValue("")); \
}
uint64_t ReturnDAO::count(const ReturnQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_rt_vendor";
	RETURN_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
std::list<ReturnDO> ReturnDAO::selectWithPage(const ReturnQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT rt_code,rt_name,po_code,vendor_code,vendor_name,rt_date,`status` FROM wm_rt_vendor";
	RETURN_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReturnMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReturnDO, ReturnMapper>(sqlStr, mapper, params);
}

std::list<ReturnDO> ReturnDAO::selectByRtCode(const string& rtCode)
{
	string sql = "SELECT rt_code,rt_name,po_code,vendor_code,vendor_name,rt_date,`status`,batch_code,remark FROM wm_rt_vendor WHERE rt_code='"+rtCode+"'";
	SqlParams params;
	ReturnDetailMapper mapper;
	return sqlSession->executeQuery<ReturnDO, ReturnDetailMapper>(sql, mapper,params);
}

uint64_t ReturnDAO::insert(const ReturnDO& iObj)
{
	string sql = "INSERT INTO `wm_rt_vendor` (`rt_code`, `rt_name`, `po_code`, `vendor_code`, `vendor_name`, `rt_date`, `status`, `batch_code`, `remark`, `create_time`,`update_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s", iObj.getreturncode(), iObj.getreturnname(), iObj.getpurchasecode(),iObj.getvendorcode(),iObj.getvendorname(),iObj.getreturndate(),iObj.getstatus(),iObj.getbatchcode(),iObj.getremark(),date,date);
}