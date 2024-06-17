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
#include "ProductionProcessDAO.h"
#include "ProductionProcessMapper.h"
#include <sstream> 
uint64_t ProductionProcessDAO::count(const ProductionProcessQuery::Wrapper& query)
{
	string sql;
	if (query->itemCode)
	{
		sql = "SELECT COUNT(*) FROM pro_route_process as p1 join pro_route_product as p2 on p1.route_id = p2.route_id where p2.item_code = ? ";
		return sqlSession->executeQueryNumerical(sql, "%s", query->itemCode.getValue(""));
	}
	else
	{
		sql = "SELECT COUNT(*) FROM pro_route_process ";
	}
	return sqlSession->executeQueryNumerical(sql);
}
list<ProRouteProcessDO> ProductionProcessDAO::query_by_workordercode(const ProductionProcessQuery::Wrapper& query)
{
	stringstream sql;
	if (query->itemCode)
	{
		sql << "select p1.process_name, p1.next_process_name from pro_route_process as p1 join pro_route_product as p2 on p1.route_id = p2.route_id where p2.item_code = ? ";
		sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
		ProProcessDOMapper mapper;
		string sqlStr = sql.str();
		return sqlSession->executeQuery<ProRouteProcessDO, ProProcessDOMapper>(sqlStr, mapper, "%s", query->itemCode.getValue(""));
	}
	else
	{
		sql << "SELECT process_name,next_process_name FROM pro_route_process order by record_id ";
	}
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProProcessDOMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProRouteProcessDO, ProProcessDOMapper>(sqlStr, mapper);
}