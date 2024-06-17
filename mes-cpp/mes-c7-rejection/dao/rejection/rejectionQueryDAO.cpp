#include "stdafx.h"
#include "rejectionQueryDAO.h"
#include "rejectionMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rt_code) { \
	sql << " AND rt_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rt_code.getValue("")); \
} \
if (query->workorder_code) {	\
		sql << " AND workorder_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
}\
if (query->warehouse_name) { \
	sql << " AND warehouse_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
}
//if (query->rt_id) { \
//	sql << " AND `rt_id`=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->rt_id.getValue(1)); \
//} \
//if (query->workorder_id) {\
//		sql << " AND workorder_id=?"; \
//		SQLPARAMS_PUSH(params, "i", int, query->workorder_id.getValue(1)); \
//}\
//if (query->location_name) { \
//	sql << " AND location_name=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->location_name.getValue("")); \
//}\
//if (query->area_name ) { \
//	sql << " AND larea_name =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->area_name .getValue("")); \
//}\
//if (query->rt_date ) { \
//	sql << " AND rt_date =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->rt_date .getValue("")); \
//}\
//if (query->status) { \
//	sql << " AND status =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->status .getValue("")); \
//}

#define DETAIL_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rt_code) { \
	sql << " AND rt_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rt_code.getValue("")); \
} \
if (query->rt_id) { \
	sql << " AND `rt_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->rt_id.getValue(1)); \
} 


uint64_t RejectDAO::count(const RejectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_rt_issue";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//detailQuery
std::list<RejectQueryDO> RejectDAO::detailmes(const RejectDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT rt_code FROM wm_rt_issue";
	DETAIL_TERAM_PARSE(query, sql);
	RejectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RejectQueryDO, RejectMapper>(sqlStr, mapper, params);
}

std::list<RejectQueryDO> RejectDAO::selectWithPage(const RejectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT rt_code,workorder_code,warehouse_name FROM wm_rt_issue";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RejectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RejectQueryDO, RejectMapper>(sqlStr, mapper, params);
}

// 通过退料单单号查询数据
std::list<RejectQueryDO> RejectDAO::selectByRt_code(const string& rt_code)
{
	string sql = "SELECT rt_code,workorder_code,warehouse_name FROM wm_rt_issue WHERE `rt_code` LIKE CONCAT('%',?,'%')";
	RejectMapper mapper;
	return sqlSession->executeQuery<RejectQueryDO, RejectMapper>(sql, mapper, "%s", rt_code);
}
// 通过生产工单查询数据
std::list<RejectQueryDO> RejectDAO::selectByWorkorder_code(const string& workorder_code)
{
	string sql = "SELECT rt_code,workorder_code,warehouse_name FROM wm_rt_issue WHERE `workorder_code` LIKE CONCAT('%',?,'%')";
	RejectMapper mapper;
	return sqlSession->executeQuery<RejectQueryDO, RejectMapper>(sql, mapper, "%s", workorder_code);
}
// 通过仓库名称查询数据
std::list<RejectQueryDO> RejectDAO::selectByWarehouse_name(const string& warehouse_name)
{
	string sql = "SELECT rt_code,workorder_code,warehouse_name FROM wm_rt_issue WHERE `warehouse_name` LIKE CONCAT('%',?,'%')";
	RejectMapper mapper;
	return sqlSession->executeQuery<RejectQueryDO, RejectMapper>(sql, mapper, "%s", warehouse_name);
}


// 插入数据
uint64_t RejectDAO::insert(const RejectQueryDO& iObj)
{
	string sql = "INSERT INTO `wm_rt_issue` (`rt_code`, `rt_name`,`workorder_id`, `location_name`,`area_name`,`rt_date`,`status`,`workorder_code`,`warehouse_id`,`warehouse_code`,`location_id`,`location_code`,`area_id`,`area_code`,`warehouse_name`) VALUES ( ?, ?,?, ?,?, ?,?, ?, ?,?, ?, ?,?, ?,  ?)";
	return sqlSession->executeInsert(sql, "%s%s%i%s%s%s%s%s%i%s%i%s%i%s%s", iObj.getRt_code(), iObj.getRt_name(), iObj.getWorkorder_id(),iObj.getLocation_name(),iObj.getArea_name(), iObj.getRt_date(), iObj.getStatus(),iObj.getWorkorder_code(),    iObj.getWarehouse_id(), iObj.getWarehouse_code(), iObj.getLocation_id(), iObj.getLocation_code(), iObj.getArea_id(), iObj.getArea_code(),iObj.getWarehouse_name());
}


//修改数据
int RejectDAO::update(const RejectQueryDO& uObj)
{
	string sql = "UPDATE `wm_rt_issue` SET `rt_code`=?, `rt_name`=?,`workorder_id`=?, `location_name`=?,`area_name`=?,`rt_date`=?,`status`=?,`workorder_code`=?,`warehouse_id`=?,`warehouse_code`=?,`location_id`=?,`location_code`=?,`area_id`=?,`area_code`=?,`warehouse_name`=? WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s%s%i%s%i%s%i%s%s%ull", uObj.getRt_code(), uObj.getRt_name(), uObj.getWorkorder_id(), uObj.getLocation_name(), uObj.getArea_name(), uObj.getRt_date(), uObj.getStatus(),uObj.getWorkorder_code(), uObj.getWarehouse_id(), uObj.getWarehouse_code(), uObj.getLocation_id(), uObj.getLocation_code(), uObj.getArea_id(), uObj.getArea_code(), uObj.getWarehouse_name(),uObj.getRt_id());
}




//int SampleDAO::deleteById(uint64_t id)
//{
//	string sql = "DELETE FROM `sample` WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%ull", id);
//}