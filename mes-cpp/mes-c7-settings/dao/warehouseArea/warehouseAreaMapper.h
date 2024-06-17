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
#ifndef _WAREHOUSE_AREA_MAPPER_
#define WAREHOUSE_AREA_MAPPER_

#include "Mapper.h"
#include "domain/do/warehouseArea/warehouseAreaDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class warehouseAreaMapper : public Mapper<warehouseAreaDO>
{
public:
	warehouseAreaDO mapper(ResultSet* resultSet) const override
	{
		warehouseAreaDO data;
		data.setAreaId(resultSet->getUInt64(1));
		data.setAreaCode(resultSet->getString(2));
		data.setAreaName(resultSet->getString(3));
		data.setArea(resultSet->getInt(4));
		data.setRemark(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_