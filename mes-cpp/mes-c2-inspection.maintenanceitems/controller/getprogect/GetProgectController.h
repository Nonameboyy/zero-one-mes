#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ksw12355
 @Date: 2024/5/20

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
#ifndef _GETPROGECTCONTROLLER_H_
#define _GETPROGECTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include"../../domain/vo/getprogect/GetProgectVO.h"
#include"../../domain/query/getprogect/GetProgectQuery.h"
#include "domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class GetProgectController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(GetProgectController);
public:
	// 1.1 ������Ŀ�б��ѯ�ӿ�����
	ENDPOINT_INFO(queryProgectList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("project.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetProgectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		//��Ŀ����
		API_DEF_ADD_QUERY_PARAMS(String, "pCode", ZH_WORDS_GETTER("project.fields.pcode"),  "01star",false);
		//��Ŀ����
		API_DEF_ADD_QUERY_PARAMS(String, "pName", ZH_WORDS_GETTER("project.fields.pname"),  "QQQQQ",false);
		//��Ŀ����
		API_DEF_ADD_QUERY_PARAMS(String, "pType", ZH_WORDS_GETTER("project.fields.ptype"), "QW",false);
	}
	// 1.2 ������Ŀ�б��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/equipment-ledger/device-manage/query-progectList", queryProgectList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, GetProgectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetProgect(query));
	}

	// 2.1 ������Ŀ�����ѯ�ӿ�����
	ENDPOINT_INFO(queryProgectDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("project.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetProgectDetailJsonVO);
		// ����������ѯ��������

		//�豸����
		API_DEF_ADD_QUERY_PARAMS(UInt64, "pId", ZH_WORDS_GETTER("project.fields.pid"), 1, true);
	}
	// 2.2 �����豸�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/equipment-ledger/device-manage/query-progectdetail", queryProgectDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, GetProgectDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProgectDetail(query));
	}

	



private:
	//��ȡ�豸�б�����+��ҳ��
	GetProgectPageJsonVO::Wrapper execGetProgect(const GetProgectQuery::Wrapper& query);
	//��ȡ�豸����
	GetProgectDetailJsonVO::Wrapper execProgectDetail(const GetProgectDetailQuery::Wrapper& query);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 

