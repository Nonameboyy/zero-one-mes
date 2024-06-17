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
#include "WorkStationDAO.h"
#include "WorkStationMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define WORKSTATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->workstationCode) { \
	sql << " AND `workstation_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workstationCode.getValue("")); \
} \
if (query->workstationName) { \
	sql << " AND workstation_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workstationName.getValue("")); \
} \
if (query->workshopName) { \
	sql << " AND workshop_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workshopName.getValue("")); \
} \
if (query->processName) { \
		sql << " AND process_name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->processName.getValue("")); \
}

//统计工作站表中有多少条数据
uint64_t WorkStationDAO::count(const GetWorkStationListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM md_workstation";
	WORKSTATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
list<WorkStationDO> WorkStationDAO::selectWithPage(const GetWorkStationListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT workstation_id,workstation_code,workstation_name,workstation_address,workshop_name,process_name,enable_flag,remark,warehouse_id,location_id,area_id FROM md_workstation";
	WORKSTATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WorkStationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sqlStr, mapper, params);
}

// 通过工作站编码查询数据
list<WorkStationDO> WorkStationDAO::selectByWorkstationCode(const string& code)
{
	string sql = "SELECT workstation_id,workstation_code,workstation_name,workshop_name,process_name FROM md_workstation WHERE workstation_code LIKE CONCAT('%',?,'%')";
	WorkStationMapper mapper;
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sql, mapper, "%s", "workstation_code");
}

//通过工作站名称查询数据
list<WorkStationDO> WorkStationDAO::selectByWorkstationName(const string& name)
{
	string sql = "SELECT workstation_id,workstation_code,workstation_name,workshop_name,process_name FROM md_workstation WHERE workstation_name LIKE CONCAT('%',?,'%')";
	WorkStationMapper mapper;
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sql, mapper, "%s", "workstation_name");
}

// 通过所在车间名称查询数据
list<WorkStationDO> WorkStationDAO::selectByWorkshopName(const string& name)
{
	string sql = "SELECT workstation_id,workstation_code,workstation_name,workshop_name,process_name FROM md_workstation WHERE workshop_name LIKE CONCAT('%',?,'%')";
	WorkStationMapper mapper;
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sql, mapper, "%s", "workshop_name");
}

// 通过所属工序查询数据
list<WorkStationDO> WorkStationDAO::selectByProcessName(const string& name)
{
	string sql = "SELECT workstation_id,workstation_code,workstation_name,workshop_name,process_name FROM md_workstation WHERE process_name LIKE CONCAT('%',?,'%')";
	WorkStationMapper mapper;
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sql, mapper, "%s", "process_name");
}

//添加新的工作站
uint64_t WorkStationDAO::insert(const WorkStationDO& iObj)
{
	string sql = "INSERT INTO `md_workstation` (`workstation_code`, `workstation_name`, `workstation_address`,`workshop_name`,`process_name`,`remark`,`enable_flag`, `warehouse_id`, `location_id`, `area_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%i%i%i", iObj.getWorkstationCode(), iObj.getWorkstationName(), iObj.getWorkstationAddress(), iObj.getWorkshopName(), iObj.getProcessName(), iObj.getRemark(), iObj.getEnableFlag(), iObj.getWarehouseId(), iObj.getLocationId(), iObj.getAreaId());
}

// 修改工作站数据
int WorkStationDAO::update(const WorkStationDO& uObj)
{
	string sql = "UPDATE `md_workstation` SET `workstation_code`=?, `workstation_name`=?, `workstation_address`=?, `workshop_name`=?, `process_name`=?, `remark`=?, `enable_flag`=? WHERE `workstation_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%ull", uObj.getWorkstationCode(), uObj.getWorkstationName(), uObj.getWorkstationAddress(), uObj.getWorkshopName(), uObj.getProcessName(), uObj.getRemark(), uObj.getEnableFlag(), uObj.getWorkstationId());
}

// 删除工作站
int WorkStationDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `md_workstation` WHERE `workstation_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

//批量删除工作站
int WorkStationDAO::deleteByIdList(list<uint64_t> id)
{
	string sql("DELETE FROM `md_workstation` WHERE 1=0 ");
	SqlParams params;
	for (auto& i : id)
	{
		sql += "OR `workstation_id`=? ";
		SQLPARAMS_PUSH(params, "ull", uint64_t, i);
	}
	return sqlSession->executeUpdate(sql, params);
}

list<WorkStationDO> WorkStationDAO::selectByIdList(const list<uint64_t>& id)
{
	string sql("SELECT `workstation_id`,`workstation_code`,`workstation_name`,`workstation_address`,`workshop_name`,`process_name`,`remark`,`enable_flag`,`warehouse_id`,`location_id`,`area_id` FROM `md_workstation` WHERE `workstation_id` IN (");
	SqlParams params;
	WorkStationMapper mapper;
	int k = 1;
	for (auto& i : id)
	{
		if (k == 1) {
			k = 0;
		}
		else {
			sql += ",";
		}
		sql += to_string(i);
	}
	sql += ")";
	return sqlSession->executeQuery<WorkStationDO, WorkStationMapper>(sql, mapper);
}

