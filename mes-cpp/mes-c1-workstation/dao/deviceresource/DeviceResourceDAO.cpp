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
#include "DeviceResourceDAO.h"
#include "DeviceResourceMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define DEVICE_RESOURCE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->equipmentCode) { \
	sql << " AND `equipmentCode`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->equipmentCode.getValue("")); \
} \
if (query->equipmentName) { \
	sql << " AND equipmentName=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->equipmentName.getValue("")); \
} 

uint64_t DeviceResourceDAO::count(const DeviceResourceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM md_workstation_machine";
	//DEVICE_RESOURCE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}

std::list<DeviceResourceDO> DeviceResourceDAO::selectWithPage(const DeviceResourceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT machinery_id,machinery_code,machinery_name,quantity FROM md_workstation_machine";
	//EQUIPMENT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DeviceResourceMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DeviceResourceDO, DeviceResourceMapper>(sqlStr, mapper);
}

uint64_t DeviceResourceDAO::insert(const DeviceResourceDO& iObj)
{
	string sql = "INSERT INTO `md_workstation_machine` (`workstation_id`,`machinery_id`,`machinery_code`, `machinery_name`, `quantity`) VALUES (?, ?, ?, ?,  ?)";
	return sqlSession->executeInsert(sql, "%i%i%s%s%i", iObj.getWorkstationId(), iObj.getMachineryId(), iObj.getEquipmentCode(), iObj.getEquipmentName(), iObj.getQuantity());
}

int DeviceResourceDAO::update(const DeviceResourceDO& uObj)
{
	string sql = "UPDATE `dv_machinery` SET `machinery_code`=?, `machinery_name`=?, `count`=? WHERE `id`=?";
	//return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getEquipmentCode(), uObj.getEquipmentName(), uObj.getCount(), uObj.getDeviceResourceId());
	return 0;
}

int DeviceResourceDAO::deleteById(uint64_t deviceResourceId)
{
	string sql = "DELETE FROM `md_workstation_machine` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", deviceResourceId);
}