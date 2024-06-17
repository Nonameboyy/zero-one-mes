#include "stdafx.h"
#include "WarehouseManagementDAO.h"
#include "WarehouseManagementMapper.h"
#include <sstream>

// 定义条件解析宏，减少重复代码
#define WAREHOUSEMANAGEMENT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->item_id) { \
	sql << " AND `item_id`=?"; \
	SQLPARAMS_PUSH(params, "i",int , query->item_id.getValue(0)); \
} \
if (query->item_code) { \
	sql << " AND item_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_code.getValue("")); \
} \
if (query->batch_code) { \
	sql << " AND batch_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->batch_code.getValue("")); \
}\
if (query->warehouse_name) {\
		sql << " AND `warehouse_name`=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
} \
if (query->vendor_code) {\
	\
		sql << " AND vendor_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->vendor_code.getValue("")); \
} \
if (query->vendor_name) {\
	\
		sql << " AND vendor_name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->vendor_name.getValue("")); \
}\
if (query->expire_date) {\
	\
		sql << " AND expire_date=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->expire_date.getValue("")); \
} \

#define WAREHOUSEMANAGEMENT_TERAM_PARSE_TO_EXPORT(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->item_id) { \
	sql << " AND `item_id`=?"; \
	SQLPARAMS_PUSH(params, "i",int , query->item_id.getValue(0)); \
} 


uint64_t WarehouseManagementDAO::count(const WarehouseManagementQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_transaction";
	WAREHOUSEMANAGEMENT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<WarehouseManagementDO> WarehouseManagementDAO::selectWithPage(const WarehouseManagementQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT item_id,item_code,batch_code,warehouse_name,vendor_code,vendor_name,expire_date FROM wm_transaction";
	WAREHOUSEMANAGEMENT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WarehouseManagementMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WarehouseManagementDO, WarehouseManagementMapper>(sqlStr, mapper, params);
}

std::list<WarehouseManagementDO> WarehouseManagementDAO::QueryByExport(const WarehouseManagementQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT item_id,item_code,item_name,specification,unit_Of_Measure,batch_code,warehouse_name,location_name,area_name,vendor_code,vendor_name,vendor_nick,workorder_code,recpt_date,expire_date FROM wm_transaction";
	WAREHOUSEMANAGEMENT_TERAM_PARSE_TO_EXPORT(query, sql);
	WarehouseManagementExportMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WarehouseManagementDO, WarehouseManagementExportMapper>(sqlStr, mapper, params);
}

