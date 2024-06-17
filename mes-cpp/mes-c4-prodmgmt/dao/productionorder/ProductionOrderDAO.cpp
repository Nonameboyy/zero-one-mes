/*
 Copyright Zero One Star. All rights reserved.
 @Author: amie
 @Date: 2022/10/25 14:26:52
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
	  https://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ProductionOrderDAO.h"
#include "ProductionOrderMapper.h"
#include <sstream> 

//定义条件解析宏，减少重复代码
#define ORDER_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->workOrderCode) { \
	sql << " AND `workorder_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workOrderCode.getValue("")); \
} \
if (query->workOrderName) { \
	sql << " AND workorder_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workOrderName.getValue("")); \
} \
if (query->workOrderType) { \
	sql << " AND workorder_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workOrderType.getValue("")); \
}\
if (query->productCode) { \
	sql << " AND product_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->productCode.getValue("")); \
}\
if (query->productName) { \
	sql << " AND product_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->productName.getValue("")); \
}\
if (query->clientCode) {\
		sql << " AND client_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->clientCode.getValue("")); \
}\
if (query->clientName) {\
		sql << " AND client_name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->clientName.getValue("")); \
}\
if (query->requestDate) {\
		sql << " AND request_date=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->requestDate.getValue("")); \
}\
if (query->sourceCode) {\
		sql << " AND source_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->sourceCode.getValue("")); \
}


uint64_t ProWorkOrderDAO::count(const ExportOrderQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_workorder";
	ORDER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ProWorkOrderDO> ProWorkOrderDAO::selectWithPage(const ExportOrderQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT workorder_code,workorder_name,workorder_type,order_source,source_code,product_id,product_code,product_name,product_spc,unit_of_measure,batch_code,quantity,quantity_produced,quantity_changed,quantity_scheduled,client_id,client_code,client_name,vendor_id,vendor_code,vendor_name,DATE_FORMAT(finish_date, '%Y-%m-%d'),DATE_FORMAT(request_date, '%Y-%m-%d'),status FROM pro_workorder";
	ORDER_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProWorkOrderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProWorkOrderDO, ProWorkOrderMapper>(sqlStr, mapper, params);
}
uint64_t ProWorkOrderBomDAO::count(const ExportBomOrderQuery::Wrapper& query)
{
	string sql;
	if (query->workOrderCode)
	{
		sql = "SELECT COUNT(*) FROM pro_workorder as w join pro_workorder_bom as b on w.workorder_id=b.workorder_id where w.workorder_code=?";
		return sqlSession->executeQueryNumerical(sql, "%s", query->workOrderCode.getValue(""));
	}
	else
	{
		sql ="SELECT COUNT(*) FROM pro_workorder_bom";
	}
	return sqlSession->executeQueryNumerical(sql);
}
std::list<ProWorkOrderBomDO> ProWorkOrderBomDAO::selectWithPage(const ExportBomOrderQuery::Wrapper& query)
{
	stringstream sql;
	if (query->workOrderCode)
	{
		sql<< "SELECT b.item_code, b.item_name, b.item_spc, b.unit_of_measure, b.item_or_product, b.quantity, b.item_id, b.workorder_id FROM pro_workorder as w join pro_workorder_bom as b on w.workorder_id = b.workorder_id where w.workorder_code = ? ";
		sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
		ProWorkOrderBomMapper mapper;
		string sqlStr = sql.str();
		return sqlSession->executeQuery<ProWorkOrderBomDO, ProWorkOrderBomMapper>(sqlStr, mapper, "%s", query->workOrderCode.getValue(""));
	}
	else
	{
		sql << "SELECT item_code,item_name,item_spc,unit_of_measure,item_or_product,quantity,item_id,workorder_id FROM pro_workorder_bom";
	}
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProWorkOrderBomMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProWorkOrderBomDO, ProWorkOrderBomMapper>(sqlStr, mapper);
}
