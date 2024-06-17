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
 * �������������
 */
class ProdOrderDTO : public oatpp::DTO
{
	DTO_INIT(ProdOrderDTO, DTO);

	// ������
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod.field.task_name");
	}
	// ����վ
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod.field.workstationName");
	}
	// ����
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod.field.processName");
	}
	// ��ʼʱ��
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod.field.startTime");
	}
	// ����ʱ��
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod.field.endTime");
	}
};

/**
 * ���������ҳ�������
 */
class ProdOrderQueryDTO : public PageDTO<ProdOrderDTO::Wrapper>
{
	DTO_INIT(ProdOrderQueryDTO, PageDTO<ProdOrderDTO::Wrapper>);

	// ������
	DTO_FIELD(String, task_name);
	DTO_FIELD_INFO(task_name) {
		info->description = ZH_WORDS_GETTER("prod.field.task_name");
	}
	// ����վ
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod.field.workstationName");
	}
	// ����
	DTO_FIELD(String, process_name);
	DTO_FIELD_INFO(process_name) {
		info->description = ZH_WORDS_GETTER("prod.field.processName");
	}
	// ��ʼʱ��
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("prod.field.startTime");
	}
	// ����ʱ��
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("prod.field.endTime");
	}
};

/**
 * ��ѯ���������б������ݴ������
 */
class ProdOrderQueryTreeDTO : public PageDTO<ProdOrderDTO::Wrapper>, public TreeNode
{
	DTO_INIT(ProdOrderQueryTreeDTO, PageDTO<ProdOrderDTO::Wrapper>);

	// ������
	API_DTO_FIELD_DEFAULT(String, task_name, ZH_WORDS_GETTER("prod.query.summary.taskName"));
	// ����վ
	API_DTO_FIELD_DEFAULT(String, workstation_name, ZH_WORDS_GETTER("prod.query.summary.workstationName"));
	// ����
	API_DTO_FIELD_DEFAULT(String, process_name, ZH_WORDS_GETTER("prod.query.summary.processName"));
	// ��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("prod.query.summary.startTime"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("prod.query.summary.endTime"));

	// �Ӳ˵�
	API_DTO_FIELD(List<ProdOrderQueryTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("prod.field.menusub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ProdOrderQueryTreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODORDER_DTO_