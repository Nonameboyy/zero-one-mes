#include "stdafx.h"
#include "MaterialDAO.h"
#include "MaterialMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->issue_id) { \
	sql << " AND `issue_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->issue_id.getValue("")); \
} 


uint64_t MaterialDAO::count(const MaterialQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_issue_line ";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<MaterialDO> MaterialDAO::selectWithPage(const MaterialQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT line_id,issue_id,item_id,item_code,item_name,specification,unit_of_measure,quantity_issued,batch_code,warehouse_name,location_name,area_name,remark FROM  wm_issue_line";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MaterialMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MaterialDO, MaterialMapper>(sqlStr, mapper, params);
}

uint64_t MaterialDAO::insert(const MaterialDO& iObj)
{
	string sql = "INSERT INTO `wm_issue_line` ( `issue_id`,`item_id`,`item_code`,`item_name`, `specification`, `unit_of_measure`,`quantity_issued`,`batch_code`,`warehouse_name`,`location_name`,`area_name`,`remark` ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%ull%s%s%s%s%d%s%s%s%s%s",
		iObj.getIssue_id(), 
		iObj.getItem_id(),
		iObj.getItem_code(),
		iObj.getItem_name(),
		iObj.getSpecification(),
		iObj.getUnit_of_measure(),
		iObj.getQuantity_issued(),
		iObj.getBatch_code(), 
		iObj.getWarehouse_name(),
		iObj.getLocation_name(), 
		iObj.getArea_name(), 
		iObj.getRemark());
}

int MaterialDAO::update(const MaterialDO& uObj)
{
	string sql = "UPDATE `wm_issue_line` SET `issue_id` = ?, `item_id` = ?, `item_code`= ?, `item_name`= ?, `specification`= ? , `unit_of_measure`= ?, `quantity_issued`= ?, `batch_code`= ?, `warehouse_name`= ?, `location_name`= ?, `area_name`= ?, `remark`= ? WHERE `line_id` = ?;";
	return sqlSession->executeUpdate(sql, "%ull%ull%s%s%s%s%d%s%s%s%s%s%ull", 
		uObj.getIssue_id(), 
		uObj.getItem_id(),
		uObj.getItem_code(), 
		uObj.getItem_name(), 
		uObj.getSpecification(), 
		uObj.getUnit_of_measure(), 
		uObj.getQuantity_issued(), 
		uObj.getBatch_code(), 
		uObj.getWarehouse_name(),
		uObj.getLocation_name(),
		uObj.getArea_name(), 
		uObj.getRemark(), 
		uObj.getLine_id());
}

int MaterialDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `wm_issue_line` WHERE `line_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}