#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ������
 @Date: 2024/05/19 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/materialinformation/MaterialInformationDTO.h"
#include "domain/query/materialinformation/MaterialInformationQuery.h"
#include "domain/vo/materialinformation/MaterialInformationVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MaterialInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(MaterialInformationController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryMaterialInformation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialinformation.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MaterialInformationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/rejection/material/query-product_reject-page", queryMaterialInformation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, MaterialInformationQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addMaterialInformation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialinformation.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/rejection/material/add-product_reject", addMaterialInformation, BODY_DTO(MaterialInformationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMaterialInformation(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("materialinformation.put.summary"), modifyMaterialInformation, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/material/mod-product_reject", modifyMaterialInformation, BODY_DTO(MaterialInformationDTO::Wrapper, dto), execModifyMaterialInformation(dto));


	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeMaterialInformation) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("materialinformation.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("materialinformation.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rejection/material/del-product_reject-by-rt_id/{rt_id}", removeMaterialInformation, PATH(UInt64, id), execRemoveMaterialInformation(id));
	
private:
	// 3.3 �����������ϵ�������
	Uint64JsonVO::Wrapper execAddMaterialInformation(const MaterialInformationDTO::Wrapper& dto);
	// 3.3 �޸��������ϵ�������
	Uint64JsonVO::Wrapper execModifyMaterialInformation(const MaterialInformationDTO::Wrapper& dto);

	// 3.3 ��ҳ��ѯ�������ϵ���
	MaterialInformationPageJsonVO::Wrapper execQuerySample(const MaterialInformationQuery::Wrapper& query, const PayloadDTO& payload);

	// 3.3 ɾ���������ϵ����б�֧������ɾ����
	Uint64JsonVO::Wrapper execRemoveMaterialInformation(const UInt64& id);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_