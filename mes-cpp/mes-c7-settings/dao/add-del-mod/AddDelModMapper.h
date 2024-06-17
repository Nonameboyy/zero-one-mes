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
#ifndef _ADDDELMOD_MAPPER_
#define _ADDDELMOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/add-del-mod/AddDelModDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AddDelModMapper : public Mapper<AddDelModDO>
{
public:
	AddDelModDO mapper(ResultSet* resultSet) const override
	{
		AddDelModDO data;
		data.setWarehouse_id(resultSet->getUInt64(1));
		data.setWarehouse_code(resultSet->getString(2));
		data.setWarehouse_name(resultSet->getString(3));
		data.setLocation(resultSet->getString(4));
		data.setArea(resultSet->getDouble(5));
		data.setCharge(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};

#endif // !_ADDDELMOD_MAPPER_