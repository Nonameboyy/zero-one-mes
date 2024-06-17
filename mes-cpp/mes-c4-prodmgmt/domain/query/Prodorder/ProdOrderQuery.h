#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _PRODORDERQUERY_H_
#define _PRODORDERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "tree/TreeNode.h"
//#include "domain/do/ProdOrder/ProdOrderMenuDO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ���������б��������ݴ���ģ��
 */
class ProdOrderQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ProdOrderQuery, PageQuery);
	
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
};

class ProdOrderTreeQuery : public ProdOrderQuery, public TreeNode
{
	// �����ʼ��
	DTO_INIT(ProdOrderTreeQuery, ProdOrderQuery);
	
	/*
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
	*/

	// �Ӳ˵�
	API_DTO_FIELD(List<ProdOrderTreeQuery::Wrapper>, children, ZH_WORDS_GETTER("prod.field.menusub"), false, {});

public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ProdOrderTreeQuery>(child), Wrapper::Class::getType()));
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODORDERQUERY_H_