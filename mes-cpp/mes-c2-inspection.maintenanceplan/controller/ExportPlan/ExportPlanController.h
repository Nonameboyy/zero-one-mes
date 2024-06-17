/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/20 16:08:05

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
#ifndef _EXPORTPLANCONTROLLER_H_
#define _EXPORTPLANCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/ExportPlanQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExportPlanController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportPlanController)
public: // ����ӿ�
	
	ENDPOINT_INFO(exportPlan) {
		// ����ӿ���������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("plan.export-plan.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();

		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "plan_code",
			ZH_WORDS_GETTER("plan.export-plan.plan-code"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "plan_name",
			ZH_WORDS_GETTER("plan.export-plan.plan-name"), {}, false);
		/*API_DEF_ADD_QUERY_PARAMS(String, "plan_type",
			ZH_WORDS_GETTER("plan.export-plan.plan-type"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "state",
			ZH_WORDS_GETTER("plan.export-plan.state"), {}, false);*/
	}

	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/export-plan", exportPlan,
		QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, ExportPlanQuery, queryParams);
		// ����ִ�к���
		API_HANDLER_RESP_VO(execExportPlan(query));
	}
	
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execExportPlan(const ExportPlanQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTPLANCONTROLLER_H_