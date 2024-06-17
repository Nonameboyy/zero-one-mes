#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/17 16:25:30

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
#ifndef _PRODUCEWORKDO_H_
#define _PRODUCEWORKDO_H_

#include "../DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class ProduceWorkDO
{	// 纪录
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 生产工单编号
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	// 报工类型
	CC_SYNTHESIZE(string, feedback_type, Feedback_type);
	//生产任务编号
	CC_SYNTHESIZE(string, task_code, Task_code);
	//产号编码
	CC_SYNTHESIZE(string, item_code, Item_code);
	//产品名称
	CC_SYNTHESIZE(string, item_name, Item_name);
	//单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//规格类型
	CC_SYNTHESIZE(string, specification, Specification);
	//报工数量
	CC_SYNTHESIZE(v_float32, quantity_feedback, Quantity_feedback);
	//待检测数量
	CC_SYNTHESIZE(v_float32, quantity_uncheck, Quantity_uncheck);
	//报工人
	CC_SYNTHESIZE(string, nick_name, Nick_name);
	//报工时间
	CC_SYNTHESIZE(string, feedback_time, Feedback_time);
	//审核人 -昵称
	CC_SYNTHESIZE(string, record_nick, Record_nick);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

	// 工作站id
	CC_SYNTHESIZE(uint64_t, workstation_id, Workstation_id);
	// 
	CC_SYNTHESIZE(uint64_t, workorder_id, Workorder_id);
	// 
	CC_SYNTHESIZE(uint64_t, route_id, Route_id);
	// 
	CC_SYNTHESIZE(uint64_t, process_id, Process_id);

	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
public:
	ProduceWorkDO() {
		record_id = 0;
		feedback_type = "";
		workorder_code = "";
		task_code = "";
		item_code = "";
		item_name = "";
		unit_of_measure = "";
		specification = "";
		quantity_feedback = 0;
		quantity_uncheck = 0;
		nick_name = "";
		feedback_time = "";
		record_nick = "";
		remark = "";

		workstation_id = 0;
		workorder_id = 0;
		route_id = 0;
		process_id = 0;
		item_id = 0;
	}
	
};

#endif // !_AddPRODUCEWORKDO_H_