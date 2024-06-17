/*
 Copyright Zero One Star. All rights reserved.

 @Author: ¶À×Ô
 @Date: 2024/06/7 18:52:15

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
#include "ExportPlanDAO.h"
#include "domain/query/ExportPlanQuery.h"
#include "domain/do/dv_check_plan/dv_check_planDO.h"
#include "dao/ExportPlan/ExportPlanMapper.h"

std::list<Dv_check_planDO> ExportPlanDAO::selectAll(const ExportPlanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT";
	sql << " `plan_code`, `plan_name`, `plan_type`, `start_date`,";
	sql << " `end_date`, `cycle_type`, `cycle_count`, `status`";
	//sql << " ``, `workshop_name`, `status`";
	sql << " FROM dv_check_plan WHERE 1 = 1";

	SqlParams params;
	if (query->plan_code) {
		sql << " AND (plan_code=?)";
		SQLPARAMS_PUSH(params, "s", std::string, query->plan_code.getValue(""));
	}
	if (query->plan_name) {
		sql << " AND (plan_name=?)";
		SQLPARAMS_PUSH(params, "s", std::string, query->plan_name.getValue(""));
	}

	dvCheckPlanMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_planDO, dvCheckPlanMapper>(sqlStr, mapper, params);
}