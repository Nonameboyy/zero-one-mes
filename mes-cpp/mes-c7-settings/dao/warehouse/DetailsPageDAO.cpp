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
#include "DetailsPageDAO.h"
#include "DetailsPageMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define DETAILSPAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->warehouse_code) { \
	sql << " AND `warehouse_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_code.getValue("")); \
} \
if (query->warehouse_name) { \
	sql << " AND warehouse_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
} \


uint64_t DetailsPageDAO::count(const DetailsPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_warehouse";
	DETAILSPAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Wm_WarehouseDO> DetailsPageDAO::selectWithPage(const DetailsPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT warehouse_id,warehouse_code,warehouse_name,location,area,charge,remark,create_by,create_time,update_by,update_time FROM wm_warehouse";
	DETAILSPAGE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DetailsPageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Wm_WarehouseDO, DetailsPageMapper>(sqlStr, mapper, params);
}

std::list<Wm_WarehouseDO> DetailsPageDAO::selectByName(const string& warehouse_name)
{
	string sql = "SELECT warehouse_id,warehouse_code,warehouse_name,location,area,charge,remark,attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM wm_warehouse WHERE `warehouse_name` LIKE CONCAT('%',?,'%')";
	DetailsPageMapper mapper;
	return sqlSession->executeQuery<Wm_WarehouseDO, DetailsPageMapper>(sql, mapper, "%s", warehouse_name);
}

std::list<Wm_WarehouseDO> DetailsPageDAO::selectByCode(const string& warehouse_code) {
	string sql = "SELECT warehouse_id,warehouse_code,warehouse_name,location,area,charge,remark,attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM wm_warehouse WHERE `warehouse_code` LIKE CONCAT('%',?,'%')";
	DetailsPageMapper mapper;
	return sqlSession->executeQuery<Wm_WarehouseDO, DetailsPageMapper>(sql, mapper, "%s", warehouse_code);
}
