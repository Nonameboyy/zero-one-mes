#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _WORKSTATION_MAPPER_
#define _WORKSTATION_MAPPER_

#include "Mapper.h"
#include "domain/do/workstation/WorkStationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class WorkStationMapper : public Mapper<WorkStationDO>
{
public:
	WorkStationDO mapper(ResultSet* resultSet) const override
	{
		WorkStationDO data;
		data.setWorkstationId(resultSet->getUInt64(1));
		data.setWorkstationCode(resultSet->getString(2));
		data.setWorkstationName(resultSet->getString(3));
		data.setWorkstationAddress(resultSet->getString(4));
		data.setWorkshopName(resultSet->getString(5));
		data.setProcessName(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		data.setEnableFlag(resultSet->getString(8));
		data.setWarehouseId(resultSet->getUInt64(9));
		data.setLocationId(resultSet->getUInt64(10));
		data.setAreaId(resultSet->getUInt64(11));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_