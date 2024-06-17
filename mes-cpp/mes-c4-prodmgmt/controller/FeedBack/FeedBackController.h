#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _FEEDBACKCONTROLLER_
#define _FEEDBACKCONTROLLER_

#include "domain/query/FeedBack/FeedBackQuery.h"
#include "domain/vo/FeedBack/FeedBackVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*
* 报工控制器
* 
*/

class FeedBackController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(FeedBackController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryFeedBackTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod1.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FeedBackPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查Q
		API_DEF_ADD_QUERY_PARAMS(String, "feedback_type", ZH_WORDS_GETTER("prod1.field.feedback_type"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workstation_name", ZH_WORDS_GETTER("prod1.field.workstation_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("prod1.field.workorder_code"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("prod1.field.item_code"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("prod1.field.item_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "specification", ZH_WORDS_GETTER("prod1.field.specification"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "quantity_feedback", ZH_WORDS_GETTER("prod1.field.quantity_feedback"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "user_name", ZH_WORDS_GETTER("prod1.field.user_name"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feedback_time", ZH_WORDS_GETTER("prod1.field.feedback_time"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "record_user", ZH_WORDS_GETTER("prod1.field.record_user"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("prod1.field.status"), "N", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/prodmgmt/prodreport/querylist", queryFeedBackTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, FeedBackQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFeedBack(query));
	}
	
private:
	// 3.3 演示分页查询数据
	FeedBackPageJsonVO::Wrapper execQueryFeedBack(const FeedBackQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _FEEDBACKCONTROLLER_