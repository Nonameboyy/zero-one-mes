#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/26 10:40:38

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
#ifndef _EXPORTDEVICEMAPPER_H_
#define _EXPORTDEVICEMAPPER_H_

#include "Mapper.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"

class dvMachineryMapper : public Mapper<dvMachineryDO>
{
public:
	dvMachineryDO mapper(ResultSet* rs) const override
	{
		dvMachineryDO data;
		
		// 映射需要用到的字段
		data.setMachineryCode(rs->getString(1));
		data.setMachineryName(rs->getString(2));
		data.setMachineryBrand(rs->getString(3));
		data.setMachinerySpec(rs->getString(4));
		data.setMachineryTypeId(rs->getUInt64(5));
		data.setMachineryTypeCode(rs->getString(6));
		data.setMachineryTypeName(rs->getString(7));
		data.setWorkshopId(rs->getUInt64(8));
		data.setWorkshopName(rs->getString(9));
		data.setStatus(rs->getString(10));
		return data;
	}
};

#endif // !_EXPORTDEVICEMAPPER_H_