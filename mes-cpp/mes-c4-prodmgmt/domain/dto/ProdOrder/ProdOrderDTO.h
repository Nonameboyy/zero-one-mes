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
#ifndef _PRODORDER_DTO_
#define _PRODORDER_DTO_
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生产任务传输对象
 */
class ProdOrderDTO : public oatpp::DTO
{
	DTO_INIT(ProdOrderDTO, DTO);

	// 任务名
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod.field.task_name");
	}
	// 工作站
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod.field.workstationName");
	}
	// 工序
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod.field.processName");
	}
	// 开始时间
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod.field.startTime");
	}
	// 结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod.field.endTime");
	}
};

/**
 * 生产任务分页传输对象
 */
class ProdOrderQueryDTO : public PageDTO<ProdOrderDTO::Wrapper>
{
	DTO_INIT(ProdOrderQueryDTO, PageDTO<ProdOrderDTO::Wrapper>);

	// 任务名
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod.field.task_name");
	}
	// 工作站
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod.field.workstationName");
	}
	// 工序
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod.field.processName");
	}
	// 开始时间
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod.field.startTime");
	}
	// 结束时间
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod.field.endTime");
	}
};

/**
 * 查询生产任务列表树数据传输对象
 */
class ProdOrderQueryTreeDTO : public PageDTO<ProdOrderDTO::Wrapper>, public TreeNode
{
	DTO_INIT(ProdOrderQueryTreeDTO, PageDTO<ProdOrderDTO::Wrapper>);

	// 任务名
	API_DTO_FIELD_DEFAULT(String, task_name, ZH_WORDS_GETTER("prod.query.summary.taskName"));
	// 工作站
	API_DTO_FIELD_DEFAULT(String, workstation_name, ZH_WORDS_GETTER("prod.query.summary.workstationName"));
	// 工序
	API_DTO_FIELD_DEFAULT(String, process_name, ZH_WORDS_GETTER("prod.query.summary.processName"));
	// 开始时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("prod.query.summary.startTime"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("prod.query.summary.endTime"));

	// 子菜单
	API_DTO_FIELD(List<ProdOrderQueryTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("prod.field.menusub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ProdOrderQueryTreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODORDER_DTO_