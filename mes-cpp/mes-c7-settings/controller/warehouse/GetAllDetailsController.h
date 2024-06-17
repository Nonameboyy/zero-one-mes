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
#ifndef _GETALLDETAILS_CONTROLLER_
#define _GETALLDETAILS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehouse/GetAllDetailsQuery.h"
#include "domain/dto/warehouse/GetAllDetailsDTO.h"
#include "domain/vo/warehouse/GetAllDetailsVO.h"
#include"ServerInfo.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetAllDetailsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetAllDetailsController);
	// 3 ����ӿ�
public:
	// //3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetAllDetails) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse.get.details"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetAllDetailsJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "warehouse_id", ZH_WORDS_GETTER("warehouse.field.warehouse_id"),, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/settings/query-warehouse-deatils", queryGetAllDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetAllDetailsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetAllDetails(userQuery, authObject->getPayload()));
	}
	 //3.3 ��ʾ��ҳ��ѯ����

	GetAllDetailsJsonVO::Wrapper execQueryGetAllDetails(const GetAllDetailsQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_