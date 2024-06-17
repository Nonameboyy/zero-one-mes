#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/26 10:40:38

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
#ifndef _EXPORTDEVICEMAPPER_H_
#define _EXPORTDEVICEMAPPER_H_

#include "Mapper.h"
#include "domain/do/dv_check_plan/dv_check_planDO.h"

class dvCheckPlanMapper : public Mapper<Dv_check_planDO>
{
public:
	Dv_check_planDO mapper(ResultSet* rs) const override
	{
		Dv_check_planDO data;
		
		// 映射需要用到的字段
		data.setPlan_code(rs->getString(2));
		data.setPlan_name(rs->getString(3));
		data.setPlan_type(rs->getString(4));
		data.setStart_date(rs->getString(5));
		data.setEnd_date(rs->getString(6));
		data.setCycle_type(rs->getString(7));
		data.setCycle_count(rs->getUInt(8));
		data.setStatus(rs->getString(9));
	
		return data;
	}
};

#endif // !_EXPORTDEVICEMAPPER_H_