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
#ifndef _PRODUCT_RECPT_CONTROLLER_
#define _PRODUCT_RECPT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/item-information/ProductRecptQuery.h"
#include "domain/dto/item-information/ProductRecptDTO.h"
#include "domain/vo/item-information/ProductRecptVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��Ʒ�����������
 */
class ProductRecptController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//����������������
	API_ACCESS_DECLARE(ProductRecptController);
	//����ӿ�
public:
	// 1.1 �����ҳ��ѯ�ӿ�����,�ӿ���ΪqueryProductRecpt
	ENDPOINT_INFO(queryProductRecpt) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product-recpt.query.summary")); //��ҳ��ѯ��Ʒ�������
		//������Ҫ��Ȩ
		API_DEF_ADD_AUTH();
		//���������������
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductRecptPageJsonVO);
		//�����ҳ��ѯ����
		API_DEF_ADD_PAGE_PARAMS();
		//������������
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product-recpt.field.recpt_code"), "recpt_code", false);//��ⵥ���,�������Ϊ��
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_name", ZH_WORDS_GETTER("product-recpt.field.recpt_name"), "recpt_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("product-recpt.field.workorder_code"), "workorder_code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product-recpt.field.warehouse_name"), "warehouse_name", false);
	}
	//1.2�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/storage/material/query-product_recpt-page", queryProductRecpt, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪProductRecptQuery����ģ��,������ѯ��Ϣ(recpt_code,recpt_name,workorder_code,warehouse_name)
		API_HANDLER_QUERY_PARAM(query, ProductRecptQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProductRecpt(query));
	}

	//2.1����������Ʒ���ӿ�����
	ENDPOINT_INFO(addProductRecpt) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product-recpt.post.summary"));//"����һ����Ʒ�������"
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//2.2������Ʒ���ӿڴ���
	ENDPOINT(API_M_POST, "/storage/material/add-product_recpt", addProductRecpt, BODY_DTO(ProductRecptDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProductRecpt(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("product-recpt.put.summary"), modifyProductRecpt, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/storage/material/mod-product_recpt", modifyProductRecpt, BODY_DTO(ProductRecptDTO::Wrapper, dto), execModifyProductRecpt(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeProductRecpt) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("product-recpt.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "recpt_id", ZH_WORDS_GETTER("product-recpt.field.recpt_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/storage/material/del-product_recpt-by-recpt_id/{recpt_id}", removeProductRecpt, PATH(UInt64, recpt_id), execRemoveProductRecpt(recpt_id));


private:
	// 1.3 ��ҳ��ѯ��Ʒ���
	ProductRecptPageJsonVO::Wrapper execQueryProductRecpt(const ProductRecptQuery::Wrapper& query);
	//2.3������Ʒ���
	Uint64JsonVO::Wrapper execAddProductRecpt(const ProductRecptDTO::Wrapper& dto);
	// 3.3 ɾ����ⵥ��
	Uint64JsonVO::Wrapper execRemoveProductRecpt(const UInt64& recpt_id);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProductRecpt(const ProductRecptDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_PRODUCT_RECPT_CONTROLLER_