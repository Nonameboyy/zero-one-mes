#include "stdafx.h"
#include "MatDAO.h"
#include "MatMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rtcode) { \
	sql << " AND `rt_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rtcode.getValue("")); \
} \
if (query->rtname) { \
	sql << " AND `rt_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rtname.getValue("")); \
} \
if (query->pocode) { \
	sql << " AND `po_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pocode.getValue("")); \
} \
if (query->vendorname) { \
	sql << " AND `vendor_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendorname.getValue("")); \
}
uint64_t MatDAO::count1(const GetReturnListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_rt_vendor";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<MatlistDO> MatDAO::selectWithPage1(const GetReturnListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT rt_code,rt_name,po_code,vendor_code,vendor_name,rt_date,statuss FROM wm_rt_vendor";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MatlistMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MatlistDO, MatlistMapper>(sqlStr, mapper, params);
}

list<MatlistDO> MatDAO::selectByName1(const string& name)
{
	return list<MatlistDO>();
}

uint64_t MatDAO::insert1(const MatlistDO& iObj)
{
	string sql = "INSERT INTO `wm_rt_vendor` (`rt_code`, `rt_name`, `po_code`,`vendor_name`, `batch_code`, `rt_date`, `status`, `remark`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", iObj.getRtcode(), iObj.getRtname(), iObj.getPocode(),
		iObj.getVendorname(), iObj.getBatchcode(), date,
		iObj.getStatuss(), iObj.getRemark());
}

uint64_t MatDAO::insert2(const MatlineDO& iObj)
{
	string sql = "INSERT INTO `wm_rt_vendor_line` (`item_code`, `item_name`, `quantity_rted`,`specification`, `unit_of_measure`, `batch_code`, `warehouse_name`, `location_name`,`area_name`,`remark`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%d%s%s%s%s%s%s%s", iObj.getItemcode(), iObj.getItemname(), iObj.getQuantityrted(),
		iObj.getSpecification(), iObj.getUnitofmeasure(), iObj.getBatchcode(),
		iObj.getWarehousename(), iObj.getLocationname(), iObj.getAreaname(),
		iObj.getRemark());
}

int MatDAO::update1(const MatlistDO& uObj)
{
	string sql = "UPDATE `wm_rt_vendor` SET `rt_code`=?, `rt_name`=?, `po_code`=?,`vendor_name`=?, `batch_code`=?, `rt_date`=?, `status`=?, `remark`=? WHERE `rt_id`=?";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%ull", uObj.getRtcode(), uObj.getRtname(), uObj.getPocode(),
		uObj.getVendorname(), uObj.getBatchcode(), date,
		uObj.getStatuss(), uObj.getRemark(),uObj.getRtid());
}

int MatDAO::deleteById1(uint64_t id)
{
	string sql = "DELETE FROM `wm_rt_vendor` WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
