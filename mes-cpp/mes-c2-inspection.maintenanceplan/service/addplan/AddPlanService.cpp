/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "AddPlanService.h"
#include"./dao/AddPlan/AddPlanDAO.h"
#include"../lib-common/include/SimpleDateTimeFormat.h"
uint64_t AddPlanService::saveData(const AddPlanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	Dv_check_planDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	//(`plan_code`,`plan_name`, `plan_type`, `cycle_count`, `cycle_type`, `start_date`, `end_date`, `status`, `remark`)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Plan_code, planCode, Plan_name, planName, Plan_type, planType, Cycle_count, cycleCount, Cycle_type, cycleType, Start_date, startDate, End_date, endDate, Status, status, Remark, remark);
	data.setCreate_by(payload.getUsername());
	data.setCreate_time(SimpleDateTimeFormat::format());
	// 执行数据添加
	AddPlanDAO dao;
	return dao.insert(data);
}


