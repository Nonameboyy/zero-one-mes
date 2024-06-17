#pragma once

#ifndef _SINGLE_DEFECT_CONTROLLER_
#define _SINGLE_DEFECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Single_Defect/Single_Defect_Query.h"
#include "domain/dto/Single_Defect/Single_Defect_DTO.h"
#include "domain/vo/Single_Defect/Single_Defect_VO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 检测项模块控制器
 */
class Single_Defect_Controller : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(Single_Defect_Controller);
	// 3 定义接口
public:
	// 3.1 定义查询检测项接口描述
	ENDPOINT_INFO(querySingle) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.detail.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SinglePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "iqc_id", ZH_WORDS_GETTER("single.iqc_id"), 1, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/incoming-inspect/index-search", querySingle, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, SingleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySingle(userQuery, authObject->getPayload()));
	}

	// 3.1 定义查询缺陷接口描述
	ENDPOINT_INFO(queryDefect) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.defect.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DefectPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("single.line"), 1, false);
	}
	// 3.2 定义查询缺陷接口处理
	ENDPOINT(API_M_GET, "/incoming-inspect/defect-search", queryDefect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, DefectQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDefect(userQuery, authObject->getPayload()));
	}

	// 3.1 定义新增缺陷接口描述
	ENDPOINT_INFO(addDefect) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增缺陷接口处理
	ENDPOINT(API_M_POST, "/incoming-inspect/defect-add", addDefect, BODY_DTO(DefectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDefect(dto));
	}

	// 3.1 定义修改缺陷接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("single.change.summary"), modifyDefect, Uint64JsonVO::Wrapper);
	// 3.2 定义修改缺陷接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming-inspect/defect-change", modifyDefect, BODY_DTO(DefectDTO::Wrapper, dto), execModifyDefect(dto));

	// 3.1 定义删除缺陷接口描述
	ENDPOINT_INFO(removeDefect) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("single.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("single.record_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming-inspect/defect-delete/{record_id}", removeDefect, PATH(UInt64, record_id), execRemoveDefect(record_id));

	
private:
	// 3.3 分页查询检测项数据
	SinglePageJsonVO::Wrapper execQuerySingle(const SingleQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 分页查询缺陷数据
	DefectPageJsonVO::Wrapper execQueryDefect(const DefectQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增缺陷数据
	Uint64JsonVO::Wrapper execAddDefect(const DefectDTO::Wrapper& dto);
	// 3.3 演示修改缺陷数据
	Uint64JsonVO::Wrapper execModifyDefect(const DefectDTO::Wrapper& dto);
	// 3.3 演示删除缺陷数据
	Uint64JsonVO::Wrapper execRemoveDefect(const UInt64& record_id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SINGLE_DEFECT_CONTROLLER_
