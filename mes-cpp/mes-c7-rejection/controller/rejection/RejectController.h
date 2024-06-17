#pragma once
#ifndef _REJECT_CONTROLLER_
#define _REJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/rejection/RejectVo.h"
#include "../../domain/query/rejection/RejectQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
	class RejectController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RejectController);
	// 3 定义接口
public:
	// 1.3.1 定义查询接口描述
	ENDPOINT_INFO(queryRejectTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RejectPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("reject.fields.rt_code"), "code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_id", ZH_WORDS_GETTER("reject.fields.workorder_id"), "workorder_id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("reject.fields.warehouse_name"), "warehouse_name", false);
	}
	// 1.3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/rejection/query-documents-page", queryRejectTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RejectQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryReject(query, authObject->getPayload()));

	}


	//2. 3.1 定义查询接口描述
	ENDPOINT_INFO(queryRejectDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.detail"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RejectDetailJsonVO);

		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("reject.fields.rt_code"), "RMO123456", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "mo", ZH_WORDS_GETTER("reject.fields.mo"), "N", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sname", ZH_WORDS_GETTER("reject.fields.sname"), "N", false);
	}
	// 2.3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/rejection/query-documents-details", queryRejectDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, RejectDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRejectDetail(query));
	}



	// 3.3.1 定义新增接口描述
	ENDPOINT_INFO(addOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/rejection/add-documents", addOrder, BODY_DTO(RejectDetailDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddReject(dto));
	}

	// 4.3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("reject.fields.modify"), modifyReject, Uint64JsonVO::Wrapper);
	// 4.3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/mod-documents", modifyReject, BODY_DTO(RejectDetailDTO::Wrapper, dto), execModifyReject(dto));

	
private:
	// 3.3 演示分页查询数据
	RejectPageJsonVO::Wrapper execQueryReject(const RejectQuery::Wrapper& query, const PayloadDTO& payload);
	//detailQuery
	RejectDetailJsonVO::Wrapper execQueryRejectDetail(const RejectDetailQuery::Wrapper& query);
	//// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddReject(const RejectDetailDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyReject(const RejectDetailDTO::Wrapper& dto);
	//// 3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveSample(const UInt64& id);
	//// 3.3 测试声明式服务调用1
	//SampleJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	//// 3.3 测试声明式服务调用2
	//SamplePageJsonVO::Wrapper execQueryAll(const SampleQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif 
