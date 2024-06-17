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

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
*
* ����������
* 
*/

class FeedBackController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(FeedBackController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryFeedBackTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod1.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FeedBackPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������Q
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
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/prodmgmt/prodreport/querylist", queryFeedBackTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, FeedBackQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryFeedBack(query));
	}
	
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	FeedBackPageJsonVO::Wrapper execQueryFeedBack(const FeedBackQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _FEEDBACKCONTROLLER_