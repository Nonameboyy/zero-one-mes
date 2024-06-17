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
#include "EquipmentDAO.h"
#include "EquipmentMapper.h"
#include "EquipmentTypeMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define EQUIPMENT_TERAM_PARSE(query, sql) \
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

uint64_t EquipmentDAO::count(const EquipmentQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_machinery";
	EQUIPMENT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<EquipmentDO> EquipmentDAO::selectWithPage(const EquipmentQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT machinery_id,machinery_code,machinery_name,machinery_brand,machinery_spec,workshop_name,status,create_time FROM dv_machinery";
	EQUIPMENT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EquipmentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EquipmentDO, EquipmentMapper>(sqlStr, mapper);
}

std::list<EquipmentTypeDO> EquipmentDAO::selectTypeList()
{
	stringstream sql;
	sql << "SELECT machinery_type_id,machinery_type_code,machinery_type_name,enable_flag,remark,parent_type_id FROM dv_machinery_type where 1 = 1";
	//EQUIPMENT_TERAM_PARSE(query, sql);
	EquipmentTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EquipmentTypeDO, EquipmentTypeMapper>(sqlStr, mapper);
}