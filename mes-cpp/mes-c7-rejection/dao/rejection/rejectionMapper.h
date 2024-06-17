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
#ifndef _rejection_MAPPER_
#define _rejection_MAPPER_

#include "Mapper.h"
#include "../../domain/do/rejection/rejectionQueryDO.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RejectMapper : public Mapper<RejectQueryDO> 
{
public:
	RejectQueryDO mapper(ResultSet* resultSet) const override
	{
		RejectQueryDO data;
		data.setRt_id(resultSet->getUInt64(1));
		data.setRt_code(resultSet->getString(2));
		data.setRt_name(resultSet->getString(3));
		data.setWorkorder_id(resultSet->getString(4));
		data.setWarehouse_name(resultSet->getString(5));
		data.setLocation_name(resultSet->getString(6));
		data.setArea_name( resultSet->getString(7));
		data.setRt_date(resultSet->getString(8));
		data.setStatus(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_