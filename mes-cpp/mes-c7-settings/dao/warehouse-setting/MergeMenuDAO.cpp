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
#include "MergeMenuMapper.h"
#include "MergeMenuDAO.h"
#include <sstream>


std::list<WarehouseMenuDO> MergeMenuDAO::selectallwarehouse() {
	stringstream sql;
	sql << "SELECT warehouse_id,warehouse_code,warehouse_name FROM wm_warehouse";
	WarehouseMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WarehouseMenuDO, WarehouseMapper>(sqlStr,mapper);
}

std::list<LocationMenuDO> MergeMenuDAO::selectlocation(const string& warehouse_id) {
	stringstream sql;
	sql << "SELECT location_id,location_code,location_name,warehouse_id FROM wm_storage_location WHERE `warehouse_id`=?";
	LocationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LocationMenuDO, LocationMapper>(sqlStr,mapper,"%s",warehouse_id);
}

std::list<AreaMenuDO> MergeMenuDAO::selectarea(const string& location_id) {
	stringstream sql;
	sql << "SELECT area_id,area_code,area_name,location_id FROM wm_storage_area WHERE `location_id`= ?";
	AreaMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AreaMenuDO,AreaMapper>(sqlStr, mapper,"%s",location_id);
}