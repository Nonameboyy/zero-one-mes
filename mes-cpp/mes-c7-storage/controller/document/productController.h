#pragma once
#ifndef _product_CONTROLLER_
#define _product_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/document/productVO.h"
#include "../../domain/query/document/productQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ProductController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ProductController);
	// 3 定义接口
public:
	// 1.3.1 定义查询接口描述
	ENDPOINT_INFO(queryProductTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.fields.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product.fields.recpt_code"), "recpt_code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_name", ZH_WORDS_GETTER("product.fields.recpt_name"), "recpt_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("product.fields.warehouse_name"), "warehouse_name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("product.fields.workorder_code"), "workorder_code", false);
	}
	// 1.3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/storage/query-documents-page", queryProductTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ProductPageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProduct(query, authObject->getPayload()));

	}


	//2. 3.1 定义查询接口描述
	ENDPOINT_INFO(queryProductDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("product.fields.detail"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductJsonVO);

		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recpt_code", ZH_WORDS_GETTER("product.fields.recpt_code"), "RMO123456", false);

	}
	// 2.3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/storage/query-documents-details", queryProductDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ProductDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProductDetail(query));
	}

private:
	// 3.3 演示分页查询数据
	ProductPageJsonVO::Wrapper execQueryProduct(const ProductPageQuery::Wrapper& query, const PayloadDTO& payload);
	//detailQuery
	ProductJsonVO::Wrapper execQueryProductDetail(const ProductDetailQuery::Wrapper& query);

};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif 
