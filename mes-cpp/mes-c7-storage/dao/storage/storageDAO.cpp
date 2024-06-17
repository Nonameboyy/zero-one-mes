
#include "stdafx.h"
#include "storageDAO.h"
#include "storageMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define storage_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->re_code) { \
    sql << " AND `re_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->re_code.getValue("")); \
} \
if (query->re_name) { \
    sql << " AND `re_name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->re_name.getValue("")); \
} \
if (query->workorder_id) { \
    sql << " AND `workorder_id`=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->workorder_id.getValue(0)); \
} \
if (query->workorder_code) { \
    sql << " AND `workorder_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
} \
if (query->warehouse_id) { \
    sql << " AND `warehouse_id`=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->warehouse_id.getValue(0)); \
} \
if (query->warehouse_code) { \
    sql << " AND `warehouse_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_code.getValue("")); \
} \
if (query->warehouse_name) { \
    sql << " AND `warehouse_name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
} \
if (query->location_id) { \
    sql << " AND `location_id`=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->location_id.getValue(0)); \
} \
if (query->location_code) { \
    sql << " AND `location_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->location_code.getValue("")); \
} \
if (query->location_name) { \
    sql << " AND `location_name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->location_name.getValue("")); \
} \
if (query->area_id) { \
    sql << " AND `area_id`=?"; \
    SQLPARAMS_PUSH(params, "i", int, query->area_id.getValue(0)); \
} \
if (query->area_code) { \
    sql << " AND `area_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->area_code.getValue("")); \
} \
if (query->area_name) { \
    sql << " AND `area_name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->area_name.getValue("")); \
} \
if (query->re_date) { \
    sql << " AND `re_date`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->re_date.getValue("")); \
} \
if (query->remark) { \
    sql << " AND `remark`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->remark.getValue("")); \
} \
if (query->re_id) { \
    sql << " AND `re_id`=?"; \
    SQLPARAMS_PUSH(params, "llu", uint64_t, query->re_id.getValue(0)); \
}


int storageDAO::update(const storageDO & uObj)
{
	string sql = "UPDATE `wm_product_recpt` SET `recpt_code`=?, `recpt_name`=?,`workorder_id`=?, `workorder_code`=?, `warehouse_id`=?, `warehouse_code`=?, `warehouse_name`=?, `location_id`=?, `location_code`=?,`location_name`=?, `area_id`=?, `area_code`=?, `area_name`=?, `recpt_date`=?, `remark`=? WHERE `recpt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%ull%s%ull%s%s%ull%s%s%ull%s%s%s%s%ull", uObj.getRe_Code(), uObj.getRe_Name(),
		uObj.getWorkororder_Id(), uObj.getWorkororder_Code(), uObj.getWarehouse_Id(), uObj.getWarehouse_Code(), uObj.getWarehouse_Name(),
		uObj.getLocation_Id(), uObj.getLocation_Code(), uObj.getLocation_Name(),
		uObj.getArea_Id(), uObj.getArea_Code(), uObj.getArea_Name(),
		uObj.getRe_Date(), uObj.getRemark(), uObj.getRe_Id());
}


int storageDAO::deleteById(uint64_t id)
{
    string sql = "DELETE FROM `wm_product_recpt` WHERE `recpt_id`=?";
    return sqlSession->executeUpdate(sql, "%ull", id);
}

uint64_t storageDAO::count(const storageQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM wm_product_recpt";
    storage_TERAM_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<storageDO> storageDAO::selectWithPage(const storageQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT recpt_id,recpt_code,recpt_name,workorder_id,workorder_code,warehouse_id,warehouse_code,warehouse_name,location_id,location_code,location_name,area_id,area_code,area_name,recpt_date,remark FROM wm_product_recpt";
    storage_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    storageMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<storageDO, storageMapper>(sqlStr, mapper, params);
}


