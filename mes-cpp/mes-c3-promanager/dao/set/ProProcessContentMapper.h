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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProProcessContentDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProProcessContentMapper : public Mapper<ProProcessContentDO>
{
public:
	ProProcessContentDO mapper(ResultSet* resultSet) const override
	{
		ProProcessContentDO data;
		data.setContentId(resultSet->getUInt64(1));
		data.setOrderNum(resultSet->getUInt(2));
		data.setContentText(resultSet->getString(3));
		data.setDevice(resultSet->getString(4));
		data.setMaterial(resultSet->getString(5));
		data.setDocUrl(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_