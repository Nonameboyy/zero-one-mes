﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
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
#ifndef _PROCESS_MAPPER_
#define _PROCESS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro_route_process/ProRouteProcessDO.h"
/**
 * 示例表字段匹配映射
 */
class ProProcessDOMapper :public Mapper<ProRouteProcessDO>
{
public:
	ProRouteProcessDO mapper(ResultSet* resultSet)const override
	{
		ProRouteProcessDO data;
		data.setprocessName(resultSet->getString(1));
		data.setnextProcessName(resultSet->getString(2));
		return data;
	}
};
#endif // !_PROCESS_MAPPER_