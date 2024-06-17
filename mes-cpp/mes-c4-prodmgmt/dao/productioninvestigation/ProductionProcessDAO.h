#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 14:23:49

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
#ifndef _PROCESS_DAO_
#define _PROCESS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro_route_process/ProRouteProcessDO.h"
#include "../../domain/query/productioninvestigation/ProductionProcessQuery.h"
/**
 * 示例表数据库操作实现
 */
class ProductionProcessDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProductionProcessQuery::Wrapper& query);
	// 通过工单编号查询
	list<ProRouteProcessDO> query_by_workordercode(const ProductionProcessQuery::Wrapper& query);
};
#endif // !_PROCESS_DAO_
