#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _FEEDBACK_QUERY_
#define _FEEDBACK_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class FeedBackQuery : public PageQuery
{
	DTO_INIT(FeedBackQuery, PageQuery);
	// 报工类型
	API_DTO_FIELD_DEFAULT(String, feedback_type, ZH_WORDS_GETTER("prod1.query.summary.feedback_type"));
	// 工作站
	API_DTO_FIELD_DEFAULT(String, workstation_name, ZH_WORDS_GETTER("prod1.query.summary.workstation_name"));
	// 生产工单编号
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("prod1.query.summary.workorder_code"));
	// 产品物料编码
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("prod1.query.summary.item_code"));
	// 产品物料名
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("prod1.query.summary.item_name"));
	// 规格型号
	API_DTO_FIELD_DEFAULT(String, specification, ZH_WORDS_GETTER("prod1.query.summary.specification"));
	// 报工数量
	API_DTO_FIELD_DEFAULT(Int32, quantity_feedback, ZH_WORDS_GETTER("prod1.query.summary.quantity_feedback"));
	// 报工人
	API_DTO_FIELD_DEFAULT(String, user_name, ZH_WORDS_GETTER("prod1.query.summary.user_name"));
	// 报工时间
	API_DTO_FIELD_DEFAULT(String, feedback_time, ZH_WORDS_GETTER("prod1.query.summary.feedback_time"));
	// 审核人
	API_DTO_FIELD_DEFAULT(String, record_user, ZH_WORDS_GETTER("prod1.query.summary.record_user"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, _status, ZH_WORDS_GETTER("prod1.query.summary.status"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FEEDBACK_QUERY_