/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#include "ProductRecptDAO.h"
#include "ProductRecptMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PRODUCT_RECPT_TERAM_PARSE(query,sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->recpt_code) { \
	sql << " AND `recpt_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recpt_code.getValue("")); \
} \
if (query->recpt_name) { \
	sql << " AND recpt_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recpt_name.getValue("")); \
} \
if (query->workorder_code) { \
	sql << " AND workorder_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
} \
if (query->warehouse_name) { \
	sql << " AND warehouse_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
}

uint64_t ProductRecptDAO::count(const ProductRecptQuery::Wrapper & query)
{//query包含(recpt_code,recpt_name,workorder_code,warehouse_name)
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_product_recpt";
	PRODUCT_RECPT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ProductRecptDO> ProductRecptDAO::selectWithPage(const ProductRecptQuery::Wrapper& query)
{//query包含(recpt_code,recpt_name,workorder_code,warehouse_name)
	stringstream sql;
	sql << "SELECT recpt_code,recpt_name,workorder_code,workorder_name,recpt_date,remark,item_id FROM wm_product_recpt";
	PRODUCT_RECPT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProductRecptMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProductRecptDO, ProductRecptMapper>(sqlStr, mapper, params);
}
uint64_t ProductRecptDAO::insert(const ProductRecptDO& iObj)
{
	string sql = "INSERT INTO `wm_product_recpt` (`recpt_code`, `recpt_name`, `workorder_code`, `workorder_name`, `recpt_date`, `remark`, `item_id`) VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%dt%s%ull", iObj.getRecptCode(), iObj.getRecptName(), iObj.getWorkorderCode(), iObj.getWorkorderName(), iObj.getRecptDate(), iObj.getRemark(), iObj.getItemId());
}

int ProductRecptDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `wm_product_recpt` WHERE `recpt_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ProductRecptDAO::update(const ProductRecptDO& uObj)
{
	string sql = "UPDATE `wm_product_recpt` SET `recpt_name`=?, `workorder_code`=?, `workorder_name`=?, `recpt_date`=?, `remark`=?, `item_id`=? WHERE `recpt_code`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%dt%s%ull%s", uObj.getRecptName(), uObj.getWorkorderCode(), uObj.getWorkorderName(), uObj.getRecptDate(), uObj.getRemark(), uObj.getItemId(), uObj.getRecptCode());
}
