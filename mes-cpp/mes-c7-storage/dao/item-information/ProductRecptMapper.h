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
#ifndef _PRODUCT_RECPT_MAPPER_
#define _PRODUCT_RECPT_MAPPER_

#include "Mapper.h"
#include "domain/do/item-information/ProductRecptDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProductRecptMapper : public Mapper<ProductRecptDO>
{
public:
	ProductRecptDO mapper(ResultSet* resultSet) const override
	{
		ProductRecptDO data;
		data.setRecptCode(resultSet->getString(1));
		data.setRecptName(resultSet->getString(2));
		data.setWorkorderCode(resultSet->getString(3));
		data.setWorkorderName(resultSet->getString(4));
		data.setRecptDate(resultSet->getString(5));
		data.setRemark(resultSet->getString(6));
		data.setItemId(resultSet->getUInt64(7));
		return data;
	}
};

#endif // !ProductRecptMapper