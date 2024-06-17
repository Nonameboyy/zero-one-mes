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
#ifndef _MATERIALPRODUCTS_CONTROLLER_
#define _MATERIALPRODUCTS_CONTROLLER_

#include "domain/dto/ProcessInspection/ProcessInspectionDTO.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "ServerInfo.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/DetectionTemplate/MaterialProductsVO.h"
#include "domain/query/DetectionTemplate/MaterialProductsQuery.h"
#include "domain/vo/DetectionTemplate/DetectionTemplateVO.h"
#include "domain/query/DetectionTemplate/DetectionTemplateQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class MaterialProductsController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(MaterialProductsController);

public: // ����ӿ�

	ENDPOINT_INFO(queryMaterialProducts) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialproducts.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MaterialProductsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("materialproducts.field.template_id"), , true);


	}

	ENDPOINT(API_M_GET, "/qc/detection-template/material-products/query-by-item_code", queryMaterialProducts, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, MaterialProductsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execMaterialProducts(userQuery, authObject->getPayload()));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addMaterialProducts) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialproducts.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/qc/detection-template/material-products/add", addMaterialProducts, BODY_DTO(MaterialProductsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMaterialProducts(dto));
	}

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeMaterialProducts) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("materialproducts.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		/*API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("materialproducts.field.record_id"), 1, true);*/
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/detection-template/material-products/delete/{record_id}", removeMaterialProducts, BODY_DTO(oatpp::List<oatpp::UInt64>, record_id), execRemoveMaterialProduct(record_id));

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("materialproducts.put.summary"), modifyMaterialProducts, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/detection-template/material-products/modify", modifyMaterialProducts, BODY_DTO(MaterialProductsDTO::Wrapper, dto), execModifyMaterialProducts(dto));

	

private: // ����ӿڵ�ִ�к���

	// ��ҳ��ѯ����
	MaterialProductsPageJsonVO::Wrapper execMaterialProducts(const MaterialProductsQuery::Wrapper& query, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execModifyMaterialProducts(const MaterialProductsDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveMaterialProduct(const oatpp::List<oatpp::UInt64>& record_ids);
	Uint64JsonVO::Wrapper execAddMaterialProducts(const MaterialProductsDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) 
#endif