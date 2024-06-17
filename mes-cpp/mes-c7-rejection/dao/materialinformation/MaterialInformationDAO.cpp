/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/27 14:26:52

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
#include "MateriaInformationDAO.h"
#include "MaterialInformationMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->rt_code) { \
    sql << " AND `rt_code`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->rt_code.getValue("")); \
} \
if (query->rt_name) { \
    sql << " AND `rt_name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->rt_name.getValue("")); \
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
if (query->rt_date) { \
    sql << " AND `rt_date`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->rt_date.getValue("")); \
} \
if (query->remark) { \
    sql << " AND `remark`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->remark.getValue("")); \
} \
if (query->rt_id) { \
    sql << " AND `rt_id`=?"; \
    SQLPARAMS_PUSH(params, "llu", uint64_t, query->rt_id.getValue(0)); \
}


uint64_t MaterialinformationDAO::insert(const MaterialInformationDO & iObj)
{
	string sql = "INSERT INTO `wm_rt_issue` (`rt_id`, `rt_code`, `rt_name`,`workorder_id`, `workorder_code`, `warehouse_id`, `warehouse_code`, `warehouse_name`, `location_id`, `location_code`,`location_name`, `area_id`, `area_code`, `area_name`, `rt_date`, `remark`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%i%s%s%i%s%i%s%s%i%s%s%i%s%s%s%s", iObj.getRt_Id(), iObj.getRt_Code(), iObj.getRt_Name(),
		iObj.getWorkororder_Id(), iObj.getWorkororder_Code(), iObj.getWarehouse_Id(), iObj.getWarehouse_Code(), iObj.getWarehouse_Name(),
		iObj.getLocation_Id(), iObj.getLocation_Code(), iObj.getLocation_Name(),
		iObj.getArea_Id(), iObj.getArea_Code(), iObj.getArea_Name(),
		iObj.getRt_Date(), iObj.getRemark());
}

int MaterialinformationDAO::update(const MaterialInformationDO& uObj)
{
	string sql = "UPDATE `wm_rt_issue` SET `rt_code`=?, `rt_name`=?,`workorder_id`=?, `workorder_code`=?, `warehouse_id`=?, `warehouse_code`=?, `warehouse_name`=?, `location_id`=?, `location_code`=?,`location_name`=?, `area_id`=?, `area_code`=?, `area_name`=?, `rt_date`=?, `remark`=? WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%ull%s%ull%s%s%ull%s%s%ull%s%s%s%s%ull",  uObj.getRt_Code(), uObj.getRt_Name(),
		uObj.getWorkororder_Id(), uObj.getWorkororder_Code(), uObj.getWarehouse_Id(), uObj.getWarehouse_Code(), uObj.getWarehouse_Name(),
		uObj.getLocation_Id(), uObj.getLocation_Code(), uObj.getLocation_Name(),
		uObj.getArea_Id(), uObj.getArea_Code(), uObj.getArea_Name(),
		uObj.getRt_Date(), uObj.getRemark(), uObj.getRt_Id());
}

int MaterialinformationDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `wm_rt_issue` WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

uint64_t MaterialinformationDAO::count(const MaterialInformationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_rt_issue";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<MaterialInformationDO> MaterialinformationDAO::selectWithPage(const MaterialInformationQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT rt_id,rt_code,rt_name,workorder_id,workorder_code,warehouse_id,warehouse_code,warehouse_name,location_id,location_code,location_name,area_id,area_code,area_name,rt_date,remark FROM wm_rt_issue";
    SAMPLE_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    MaterianInformationMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<MaterialInformationDO, MaterianInformationMapper>(sqlStr, mapper, params);
}


