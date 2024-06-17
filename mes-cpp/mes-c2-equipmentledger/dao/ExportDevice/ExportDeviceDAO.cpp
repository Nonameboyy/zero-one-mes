/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/05/26 10:39:15

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
#include "ExportDeviceDAO.h"
#include "domain/query/ExportDeviceQuery.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"
#include "dao/ExportDevice/ExportDeviceMapper.h"

std::list<dvMachineryDO> ExportDeviceDAO::selectAll(const ExportDeviceQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT";
	sql << " `machinery_code`, `machinery_name`, `machinery_brand`, `machinery_spec`,";
	sql << " `machinery_type_id`, `machinery_type_code`, `machinery_type_name`,";
	sql << " `workshop_id`, `workshop_name`, `status`";
	sql << " FROM dv_machinery WHERE 1 = 1";

	SqlParams params;
	if (query->device_code) {
		sql << " AND (machinery_code=?)";
		SQLPARAMS_PUSH(params, "s", std::string, query->device_code.getValue(""));
	}
	if (query->device_name) {
		sql << " AND (machinery_name=?)";
		SQLPARAMS_PUSH(params, "s", std::string, query->device_name.getValue(""));
	}

	dvMachineryMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<dvMachineryDO, dvMachineryMapper>(sqlStr, mapper, params);
}