/*
 * Copyright Zero One Star. All rights reserved.
 *
 * @Author: Heng_Xin
 * @Date: 2024/5/25 13:52:06
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *	  https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */
#include "stdafx.h"
#include "RepairorderDAO.h"
#include "RepairorderMapper.h"
#include <sstream>

// 定义 分页查询 条件解析宏，减少重复代码
#define REPAIRORDER_QUERY_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->repairCode) { \
	sql << " AND repair_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->repairCode.getValue("")); \
} \
if (query->repairName) { \
	sql << " AND repair_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->repairName.getValue("")); \
} \
if (query->machineryCode) { \
	sql << " AND machinery_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->machineryCode.getValue("")); \
} \
if (query->machineryName) { \
	sql << " AND machinery_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->machineryName.getValue("")); \
} \
if (query->repairResult) { \
	sql << " AND repair_result=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->repairResult.getValue("")); \
} \
if (query->status) { \
	sql << " AND status=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue("")); \
}

// 定义 详细信息查询 条件解析宏，减少重复代码
#define REPAIRORDER_DETAILS_QUERY_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->repairId) { \
	sql << " AND repair_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->repairId.getValue(0)); \
}

uint64_t RepairorderDAO::count(const RepairorderQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM dv_repair";
    REPAIRORDER_QUERY_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t RepairorderDAO::count(const RepairorderDetailsQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM dv_repair";
    REPAIRORDER_DETAILS_QUERY_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<DvRepairDO> RepairorderDAO::selectWithPage(const RepairorderQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT repair_id,repair_code,repair_name,machinery_id,machinery_code,machinery_name,machinery_brand,machinery_spec,machinery_type_id,require_date,finish_date,confirm_date,repair_result,accepted_by,confirm_by,status,remark,attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM dv_repair";
    REPAIRORDER_QUERY_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    RepairorderMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<DvRepairDO, RepairorderMapper>(sqlStr, mapper, params);
}

list<DvRepairDO> RepairorderDAO::selectById(const uint64_t& id)
{
    stringstream sql;
    SqlParams params;
    sql << "SELECT repair_id,repair_code,repair_name,machinery_id,machinery_code,machinery_name,machinery_brand,machinery_spec,machinery_type_id,require_date,finish_date,confirm_date,repair_result,accepted_by,confirm_by,status,remark,attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM dv_repair WHERE repair_id=?";
    SQLPARAMS_PUSH(params, "ull", uint64_t, id);
    RepairorderMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<DvRepairDO, RepairorderMapper>(sqlStr, mapper, params);
}

uint64_t RepairorderDAO::insert(const DvRepairDO& iObj)
{
    string sql = "INSERT INTO `dv_repair` (`repair_code`, `repair_name`, `machinery_id`, `machinery_code`, `machinery_name`, `machinery_brand`, `machinery_type_id`, `require_date`, `remark`, `create_by`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeInsert(sql, "%s%s%ull%s%s%s%ull%dt%s%s%s",
        iObj.getRepair_code(),
        iObj.getRepair_name(),
        iObj.getMachinery_id(),
        iObj.getMachinery_code(),
        iObj.getMachinery_name(),
        iObj.getMachinery_brand(),
        iObj.getMachinery_type_id(),
        iObj.getRequire_date(),
        iObj.getRemark(),
        iObj.getCreate_by(),
        iObj.getCreate_time());
}

int RepairorderDAO::update(const DvRepairDO& uObj)
{
    string sql = "UPDATE `dv_repair` SET `repair_code`=?, `repair_name`=?, `machinery_id`=?, `machinery_code`=?, `machinery_name`=?, `machinery_brand`=?, `machinery_type_id`=?, `require_date`=?, `remark`=?, `update_by`=?, `update_time`=? WHERE `repair_id`=?";
    return sqlSession->executeUpdate(sql, "%s%s%ull%s%s%s%ull%dt%s%s%s%ull",
        uObj.getRepair_code(),
        uObj.getRepair_name(),
        uObj.getMachinery_id(),
        uObj.getMachinery_code(),
        uObj.getMachinery_name(),
        uObj.getMachinery_brand(),
        uObj.getMachinery_type_id(),
        uObj.getRequire_date(),
        uObj.getRemark(),
        uObj.getUpdate_by(),
        uObj.getUpdate_time(),
        uObj.getRepair_id());
}

int RepairorderDAO::deleteById(uint64_t id)
{
    string sql = "DELETE FROM `dv_repair` WHERE `repair_id`=?";
    return sqlSession->executeUpdate(sql, "%ull", id);
}
