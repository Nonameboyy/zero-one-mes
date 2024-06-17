/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/26 22:29:51

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

#include <sstream>
#include "stdafx.h"
#include "ImportDeviceDAO.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"

bool ImportDeviceDAO::insertOne(dvMachineryDO& Do)
{
	
	std::string sql = "SELECT COUNT(*) FROM dv_machinery WHERE `machinery_code`=";
	sql = sql + "'" + Do.getMachineryCode() + "'";
	
	// 若该设备编码存在，则该次导入失败
	if (sqlSession->executeQueryNumerical(sql)) {
		return false;
	}

	sql = "INSERT INTO `dv_machinery` (`machinery_code`, `machinery_name`,\
			`machinery_brand`, `machinery_spec`, `machinery_type_id`, `machinery_type_code`,\
			`machinery_type_name`, `workshop_id`, `workshop_name`, `status`)\
			VALUES(?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%i%s%s%i%s%s", \
		Do.getMachineryCode(), Do.getMachineryName(), Do.getMachineryBrand(), Do.getMachinerySpec(), \
		Do.getMachineryTypeId(), Do.getMachineryTypeCode(), Do.getMachineryTypeName(), \
		Do.getWorkshopId(), Do.getWorkshopName(), Do.getStatus());
}
