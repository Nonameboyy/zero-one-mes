#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _PRODORDER1_DTO_
#define _PRODORDER1_DTO_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生产任务传输对象
 */
class ProdTaskModifyDTO : public oatpp::DTO
{
	DTO_INIT(ProdTaskModifyDTO, DTO);

	// 任务id
	DTO_FIELD(Int64, task_id);
	DTO_FIELD_INFO(task_id) {
		info->description = ZH_WORDS_GETTER("prod1.field.task_id");
	}
	// 任务名
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.task_name");
	}
	// 工作站
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.workstationName");
	}
	// 工序
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.processName");
	}
	// 开始时间
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.startTime");
	}
	// 结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.endTime");
	}
};


/*
*修改生产任务传输对象
*/
class ProdTaskRemoveDTO : public oatpp::DTO
{
	DTO_INIT(ProdTaskRemoveDTO, DTO);
	
	// 任务id
	DTO_FIELD(Int64, task_id);
	DTO_FIELD_INFO(task_id) {
		info->description = ZH_WORDS_GETTER("prod1.field.task_id");
	}
	// 任务名
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.task_name");
	}
	// 工作站
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.workstationName");
	}
	// 工序
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.processName");
	}
	// 开始时间
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.startTime");
	}
	// 结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.endTime");
	}
};
	
#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODORDER1_DTO_