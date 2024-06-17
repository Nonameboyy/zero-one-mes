#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 独自
 @Date: 2024/06/7 18:51:36

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
#ifndef _EXPORTPLANDAO_H_
#define _EXPORTPLANDAO_H_

#include "BaseDAO.h"
#include "domain/query/ExportPlanQuery.h"
#include "domain/do/dv_check_plan/dv_check_planDO.h"
#include <list>
#include <vector>

class ExportPlanDAO : public BaseDAO
{
public:
	// 根据query查询数据，返回需要的行
	std::list<Dv_check_planDO> selectAll(const ExportPlanQuery::Wrapper& query);
};

#endif // !_EXPORTDEVICEDAO_H_