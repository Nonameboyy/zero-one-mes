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
#ifndef _BOM_CONTROLLER_
#define _BOM_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/productionorder/ExportBomOrderQuery.h"
#include "domain/vo/productionorder/ExportBomOrderVO.h"
#include "domain/query/productionorder/ExportOrderQuery.h"
#include "domain/vo/productionorder/ExportOrderVO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ProductionOrderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ProductionOrderController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("productionorder.query.summary-another"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportOrderPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "workOrderCode", ZH_WORDS_GETTER("productionorder.query.fields.workorder_code"),"", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workOrderName", ZH_WORDS_GETTER("productionorder.query.fields.workorder_name"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "workOrderType", ZH_WORDS_GETTER("productionorder.query.fields.workorder_type"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sourceCode", ZH_WORDS_GETTER("productionorder.query.fields.source_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productCode", ZH_WORDS_GETTER("productionorder.query.fields.product_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productName", ZH_WORDS_GETTER("productionorder.query.fields.product_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "clientCode", ZH_WORDS_GETTER("productionorder.query.fields.client_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "clientName", ZH_WORDS_GETTER("productionorder.query.fields.client_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "requestDate", ZH_WORDS_GETTER("productionorder.query.fields.request_date"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/prodmgmt/prodworkorder/export", queryOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ExportOrderQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOrder(query));
	}
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryBomOrderbyWorkCode) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("productionorder.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportBomOrderPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "workOrderCode", ZH_WORDS_GETTER("productionorder.query.fields.workorder_code"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/prodmgmt/prodworkorder/bom_export", queryBomOrderbyWorkCode, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ExportBomOrderQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBomOrderbyWorkCode(query));
	}
private:
	// 3.3 演示分页查询数据
	StringJsonVO::Wrapper execQueryOrder(const ExportOrderQuery::Wrapper& query);
	StringJsonVO::Wrapper execQueryBomOrderbyWorkCode(const ExportBomOrderQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _BOM_CONTROLLER_