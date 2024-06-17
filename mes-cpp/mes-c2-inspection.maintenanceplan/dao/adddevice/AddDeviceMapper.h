#pragma once
#pragma once
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
#ifndef _ADDPROJECTMAPPER_H_
#define _ADDPROJECTMAPPER_H_

#include "Mapper.h"
#include"../../../mes-c2-equipmentledger/domain/do/dv_machinery/dvMachineryDO.h"


class AddMachineryMapper : public Mapper<dvMachineryDO>
{
public:
	dvMachineryDO mapper(ResultSet* resultSet) const override
	{

		//machinery_code,machinery_name,machinery_brand,machinery_spec,remark,create_time FROM dv_machinery
		dvMachineryDO data;
		data.setMachineryCode(resultSet->getString(1));
		data.setMachineryName(resultSet->getString(2));
		data.setMachineryBrand(resultSet->getString(3));
		data.setMachinerySpec(resultSet->getString(4));
		data.setRemark(resultSet->getString(5));
		data.setCreateTime(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_