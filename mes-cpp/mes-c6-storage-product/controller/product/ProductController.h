#pragma once
#ifndef _PRODUCTCONTROLLER_H_
#define _PRODUCTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/product/ProductVO.h"
#include "domain/dto/product/ProductDTO.h"
#include "domain/query/product/ProductQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ProductController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ProductController);
public:
	//分页查询
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryProductTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductTableJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "issue_code", ZH_WORDS_GETTER("product.fields.issue_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "issue_name", ZH_WORDS_GETTER("product.fields.issue_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product.fields.warehouse_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "issue_date", ZH_WORDS_GETTER("product.fields.issue_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("product.fields.status"), "", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/incoming/query-product-table", queryProductTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ProductQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execProductTable(query, authObject->getPayload()));
	}
	//详情查询
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryProductDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductDetailJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "issue_id", ZH_WORDS_GETTER("product.fields.issue_id"), 1, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/incoming/query-product-detail", queryProductDetail, QUERY(UInt64, issue_id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execProductDetail(issue_id));
	}

private:
	// 查询数据
	ProductTableJsonVO::Wrapper execProductTable(const ProductQuery::Wrapper& query,const PayloadDTO& payload);
	ProductDetailJsonVO::Wrapper execProductDetail(const int& issue_id);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif