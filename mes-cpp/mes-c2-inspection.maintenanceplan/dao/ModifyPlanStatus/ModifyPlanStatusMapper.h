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
#ifndef _MODIFY_PLAN_MAPPER_
#define _MODIFY_PLAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ModifyPlanStatus/ModifyPlanStatusDo.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class ModifyPlanStatusMapper : public Mapper<ModifyPlanStatusDo>
{
public:
	ModifyPlanStatusDo mapper(ResultSet* resultSet) const override
	{
		ModifyPlanStatusDo data;
		data.setId(resultSet->getUInt64(1));
		data.setStatus(resultSet->getString(9));
		data.setUpdateby(resultSet->getString(17));
		data.setUpdatetime(resultSet->getString(18));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_