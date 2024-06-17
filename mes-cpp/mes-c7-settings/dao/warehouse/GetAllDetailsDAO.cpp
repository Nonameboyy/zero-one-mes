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
#include "GetAllDetailsDAO.h"
#include "GetAllDetailsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define GETALLDETAILS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->warehouse_id) { \
	sql << " AND `warehouse_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int64_t, query->warehouse_id.getValue(0)); \
} \



std::list<Wm_WarehouseDO> GetAllDetailsDAO::selectdetails(const GetAllDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT warehouse_id,warehouse_code,warehouse_name,location,area,charge,remark,create_by,create_time,update_by,update_time FROM wm_warehouse";
	GETALLDETAILS_TERAM_PARSE(query, sql);
	GetAllDetailsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Wm_WarehouseDO, GetAllDetailsMapper>(sqlStr, mapper, params);
}

