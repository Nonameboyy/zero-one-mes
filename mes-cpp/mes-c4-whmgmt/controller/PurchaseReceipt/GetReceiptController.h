#pragma once

#ifndef _GETRECEIPT_CONTROLLER_H
#define _GETRECEIPT_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/Receipt/ReceiptVO.h"
#include "../../domain/query/Receipt/ReceiptQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetReceiptController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetReceiptController);

public: // 定义接口
	// 获取单据列表接口描述
	ENDPOINT_INFO(queryReceiptPageTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("receipt.describe.query1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReceiptPageTableJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recptCode", ZH_WORDS_GETTER("receipt.query.fields.recptCode"), "R20231019001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recptName", ZH_WORDS_GETTER("receipt.query.fields.recptName"), "Procurement test", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("receipt.query.fields.vendorName"), "Jiangsu test", false);
		API_DEF_ADD_QUERY_PARAMS(String, "poCode", ZH_WORDS_GETTER("receipt.query.fields.poCode"), "343434343", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recptDate", ZH_WORDS_GETTER("receipt.query.fields.recptDate"), "2023-06-15", false);
	}
	// 获取单据列表接口
	ENDPOINT(API_M_GET, "/whmgmt/purchase/querylist", queryReceiptPageTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ReceiptTableQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReceiptPageTable(query));
	}

	// 获取单据详情接口描述
	ENDPOINT_INFO(queryReceiptDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("receipt.describe.query2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReceiptDetailJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "recptCode", ZH_WORDS_GETTER("receipt.query.fields.recptCode"), "R20231019001", false);
	}
	// 获取单据详情接口
	ENDPOINT(API_M_GET, "/whmgmt/purchase/querydetail", queryReceiptDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ReceiptDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReceiptDetail(query));
	}

private: // 定义接口执行函数
	ReceiptPageTableJsonVO::Wrapper execQueryReceiptPageTable(const ReceiptTableQuery::Wrapper& query);
	ReceiptDetailJsonVO::Wrapper execQueryReceiptDetail(const ReceiptDetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _GETRECEIPT_CONTROLLER_H