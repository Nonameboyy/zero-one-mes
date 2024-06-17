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
#ifndef _ADDRECPT_MAPPER_
#define _ADDRECPT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/document/Wm_product_recptDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AddrecptMapper : public Mapper<Wm_product_recptDO>
{
public:
	Wm_product_recptDO mapper(ResultSet* resultSet) const override
	{
		Wm_product_recptDO data;
		data.setRecpt_code(resultSet->getString(1));
		data.setRecpt_date(resultSet->getString(2));
		data.setRecpt_id(resultSet->getUInt64(3));
		data.setRecpt_name(resultSet->getString(4));
		data.setRemark(resultSet->getString(5));
		data.setWorkorder_code(resultSet->getString(6));
		data.setWorkorder_id(resultSet->getUInt64(7));
		data.setWorkorder_name(resultSet->getString(8));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_