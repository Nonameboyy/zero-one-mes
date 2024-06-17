﻿#pragma once
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
#ifndef _ORDER_DAO_
#define _ORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro_workorder/ProWorkOrderDO.h"
#include "../../domain/query/productionorder/ExportOrderQuery.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
#include "../../domain/query/productionorder/ExportBomOrderQuery.h"
/**
 * 示例表数据库操作实现
 */
class ProWorkOrderDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ExportOrderQuery::Wrapper& query);
	// 分页查询数据
	list<ProWorkOrderDO> selectWithPage(const ExportOrderQuery::Wrapper& query);
};
class ProWorkOrderBomDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ExportBomOrderQuery::Wrapper& query);
	// 分页查询数据
	list<ProWorkOrderBomDO> selectWithPage(const ExportBomOrderQuery::Wrapper& query);
};
#endif // !_ORDER_DAO_