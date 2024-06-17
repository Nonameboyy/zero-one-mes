#pragma once
#ifndef _product_CONTROLLER_
#define _product_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/document/productVO.h"
#include "../../domain/query/document/productQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ProductController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProductController);
	// 3 ����ӿ�
public:
	// 1.3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProductTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.fields.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product.fields.recpt_code"), "recpt_code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_name", ZH_WORDS_GETTER("product.fields.recpt_name"), "recpt_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product.fields.warehouse_name"), "warehouse_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("product.fields.workorder_code"), "workorder_code", false);
	}
	// 1.3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/storage/query-documents-page", queryProductTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductPageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProduct(query, authObject->getPayload()));

	}


	//2. 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProductDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.fields.detail"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductJsonVO);

		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product.fields.recpt_code"), "RMO123456", false);

	}
	// 2.3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/storage/query-documents-details", queryProductDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProductDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProductDetail(query));
	}

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ProductPageJsonVO::Wrapper execQueryProduct(const ProductPageQuery::Wrapper& query, const PayloadDTO& payload);
	//detailQuery
	ProductJsonVO::Wrapper execQueryProductDetail(const ProductDetailQuery::Wrapper& query);

};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif 
