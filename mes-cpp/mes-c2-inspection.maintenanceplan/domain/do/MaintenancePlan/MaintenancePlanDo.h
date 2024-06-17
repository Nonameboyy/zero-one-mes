#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _MAINTENANCEPLAN_DO_
#define _MAINTENANCEPLAN_DO_
#include "../DoInclude.h"
#include "../../GlobalInclude.h"

/**
 * 示例数据库实体类
 */
class MaintenancePlanDo
{
	//计划ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 计划编号
	CC_SYNTHESIZE(string, code, Code);
	// 计划名称
	CC_SYNTHESIZE(string, name, Name);
	// 计划类型
	CC_SYNTHESIZE(string, type, Type);
	// 频率类型
	CC_SYNTHESIZE(string, cycletype, Cycletype);
	// 频率次数
	CC_SYNTHESIZE(int32_t, cyclecount, Cyclecount);
	// 计划开始时间
	CC_SYNTHESIZE(string, startdate, Startdate);
	// 计划结束时间
	CC_SYNTHESIZE(string, enddate, Enddate);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 更新者
	CC_SYNTHESIZE(string, updateby, Updateby);
	// 更新时间
	CC_SYNTHESIZE(string, updatetime, Updatetime);
public:
	MaintenancePlanDo() {
		id = 0;
		code = "";
		name = "";
		type = "";
		cycletype = "";
		cyclecount = 0;
		startdate = "";
		enddate = "";
		//status = "";
		remark = "";
		updateby = "";
		updatetime = "";
	}
};

#endif // !_SAMPLE_DO_
