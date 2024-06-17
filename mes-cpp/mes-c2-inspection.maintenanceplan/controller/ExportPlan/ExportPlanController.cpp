/*
 Copyright Zero One Star. All rights reserved.

 @Author: ¡£ºÃ
 @Date: 2024/05/20 16:24:24

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
#include "ExportPlanController.h"
#include "domain/query/ExportPlanQuery.h"
#include "../mes-c2-inspection.maintenanceplan/service/ExportPlan/ExportPlanService.h"

StringJsonVO::Wrapper ExportPlanController::
	execExportPlan(const ExportPlanQuery::Wrapper & query)
{
	auto res = StringJsonVO::createShared();

	ExportPlanService service;
	auto url = service.exportPlan(query);

	if (url != "")
		res->success(url);
	else
		res->fail("");
	return res;
}
