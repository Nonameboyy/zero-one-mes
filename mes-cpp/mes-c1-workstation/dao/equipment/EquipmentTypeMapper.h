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
#ifndef _EQUIPMENT_TYPE_MAPPER_
#define _EQUIPMENT_TYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/equipment/EquipmentTypeDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class EquipmentTypeMapper : public Mapper<EquipmentTypeDO>
{
public:
	EquipmentTypeDO mapper(ResultSet* resultSet) const override
	{
		EquipmentTypeDO data;
		data.setMachineryTypeId(resultSet->getString(1));
		data.setMachineryTypeCode(resultSet->getString(2));
		data.setMachineryTypeName(resultSet->getString(3));
		data.setEnableFlag(resultSet->getInt(4));
		data.setRemark(resultSet->getString(5));
		data.setParentTypeId(resultSet->getString(6));
		return data;
	}
};

#endif // !_EQUIPMENT_TYPE_MAPPER_