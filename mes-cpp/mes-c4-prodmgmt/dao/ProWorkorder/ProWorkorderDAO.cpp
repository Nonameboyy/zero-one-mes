
#include "stdafx.h"
#include "ProWorkorderDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}


uint64_t ProWorkorderDAO::selectByID(uint64_t workorder_id)
{
	string sql = "SELECT product_id FROM pro_workorder WHERE workorder_id=?";
	return sqlSession->executeQueryNumerical(sql, "%ull", workorder_id);
		
}

int ProWorkorderDAO::update(const ProdWorkorderDO & uObj)
{
	string sql = "UPDATE `pro_workorder` SET `workorder_code`=?, `workorder_name`=?, `order_source`=?, `source_code`=?, `workorder_type`=?, `product_id`=?, `product_code`=?, `product_name`=?, `product_spc`=?, `unit_of_measure`=?, `quantity`=?, `request_date`=?, `batch_code`=?, `client_id`=?, `client_code`=?, `client_name`=?, `remark`=?,`update_time`=? WHERE `workorder_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%ull%s%s%s%s%d%s%s%ull%s%s%s%s%ull", uObj.getWorkOrderCode(), uObj.getWorkOrderName(), uObj.getOrderSource(), uObj.getSourceCode(), uObj.getWorkOrderType(), uObj.getProductId(), uObj.getProductCode(), uObj.getProductName(), uObj.getProductSpc(), uObj.getUnitOfMeasure(), uObj.getQuantity(), uObj.getRequestDate(), uObj.getBatchCode(), uObj.getClientId(), uObj.getClientCode(), uObj.getClientName(), uObj.getRemark(), uObj.getUpdateTime(), uObj.getWorkOrderID());
}	


uint64_t ProWorkorderDAO::countById(ProdWorkorderDO iObj)
{
	SqlParams params;
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_workorder";
	sql << " WHERE 1=1";
	if (iObj.getWorkOrderID() > 0) {
		sql << " AND `workorder_id`=? "; 
		SQLPARAMS_PUSH(params, "ull", uint64_t, iObj.getWorkOrderID());
	}
	if (iObj.getParentId() > 0) {
		sql << " AND `parent_id`=? ";
		SQLPARAMS_PUSH(params, "ull", uint64_t, iObj.getParentId());
		sql << " AND `status`!=? ";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getStatus());
	}
	else if (iObj.getStatus() != "") {
		sql << " AND `status`=? ";
		SQLPARAMS_PUSH(params, "s", std::string, iObj.getStatus());
	}
	
	string sqlStr = sql.str();
	
	return sqlSession->executeQueryNumerical(sqlStr, params);

}

int ProWorkorderDAO::completeById(uint64_t id)
{
	
	string sql = "UPDATE `pro_workorder` SET `status`='FINISHED' WHERE `workorder_id`= ?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ProWorkorderDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pro_workorder` WHERE `workorder_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ProWorkorderDAO::comfirmById(uint64_t id)
{
	string sql = "UPDATE `pro_workorder` SET `status`='CONFIRMED' WHERE `workorder_id`= ? ";
	return sqlSession->executeUpdate(sql, "%ull", id);
	
}
