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
#ifndef _ADD_PLAN_MAPPER_
#define _ADD_PLAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"

/**
 * ????¡À¨ª¡Á???????????
 */
class AddPlanMapper : public Mapper<Dv_check_planDO>
{

public:
	Dv_check_planDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_planDO data;
		data.setPlan_code(resultSet->getString(1));
		data.setPlan_name(resultSet->getString(2));
		data.setPlan_type(resultSet->getString(3));
		data.setStart_date(resultSet->getString(4));
		data.setEnd_date(resultSet->getString(7));
		data.setCycle_type(resultSet->getString(8));
		data.setCycle_count(resultSet->getUInt64(9));
		data.setStatus(resultSet->getString(10));
		data.setRemark(resultSet->getString(11));
		data.setAttr1(resultSet->getString(12));
		data.setAttr2(resultSet->getString(13));
		data.setAttr3(resultSet->getUInt(14));
		data.setAttr4(resultSet->getUInt(15));
		data.setCreate_by(resultSet->getString(16));
		data.setCreate_time(resultSet->getString(17));
		data.setUpdate_by(resultSet->getString(18));
		data.setUpdate_time(resultSet->getString(19));
		/*/
		CC_SYNTHESIZE(string, plan_code, Plan_code);
	CC_SYNTHESIZE(string, plan_name, Plan_name);
	CC_SYNTHESIZE(string, plan_type, Plan_type);
	CC_SYNTHESIZE(string, start_date, Start_date);
	CC_SYNTHESIZE(string, end_date, End_date);
	CC_SYNTHESIZE(string, cycle_type, Cycle_type);
	CC_SYNTHESIZE(uint32_t, cycle_count, Cycle_count);
	CC_SYNTHESIZE(string, status, Status);
	CC_SYNTHESIZE(string, remark, Remark)
	CC_SYNTHESIZE(string, attr1, Attr1)
	CC_SYNTHESIZE(tring, attr2, Attr2
	CC_SYNTHESIZE(uint32_t, attr3, Attr3)
	CC_SYNTHESIZE(uint32_t, attr4, Att
	CC_SYNTHESIZE(string, create_by, Create_by
	CC_SYNTHESIZE(string, create_time, Create_t
	CC_SYNTHESIZE(string, update_by, Update_by)
	CC_SYNTHESIZE(string, update_time, Update_time);*/

		return data;
	}
};

#endif // _ADD_PLAN_MAPPER_