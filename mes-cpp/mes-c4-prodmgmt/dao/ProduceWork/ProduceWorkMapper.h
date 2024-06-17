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
#ifndef _PWORK_MAPPER_
#define _PWORK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ProduceWork/ProduceWorkDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProduceWorkMapper : public Mapper<ProduceWorkDO>
{
public:
	ProduceWorkDO mapper(ResultSet* resultSet) const override
	{
		ProduceWorkDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setFeedback_type(resultSet->getString(2));
		data.setWorkorder_code(resultSet->getString(3));
		data.setTask_code(resultSet->getString(4));
		data.setItem_code(resultSet->getString(5));
		data.setItem_name(resultSet->getString(6));
		data.setUnit_of_measure(resultSet->getString(7));
		data.setSpecification(resultSet->getString(8));
		data.setQuantity_feedback(resultSet->getDouble(9));
		data.setQuantity_uncheck(resultSet->getDouble(10));
		data.setNick_name(resultSet->getString(11));
		data.setRecord_nick(resultSet->getString(12));
		data.setFeedback_time(resultSet->getString(13));
		data.setRemark(resultSet->getString(14));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_