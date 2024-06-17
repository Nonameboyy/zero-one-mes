#pragma once

#ifndef _GETWORKSTATIONLISTCONTROLLER_H_
#define _GETWORKSTATIONLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/get-wf-for-ws/GetWorkFixtureForWorkStationQuery.h"
#include "domain/dto/get-wf-for-ws/GetWorkFixtureForWorkStationDTO.h"
#include "domain/vo/get-wf-for-ws/GetWorkFixtureForWorkStationVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GetWorkFixtureForWorkStationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GetWorkFixtureForWorkStationController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryWorkFixtureForWorkStation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("wf_for_ws.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetWorkFixtureForWorkStationJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "GetWFForWSTypeName", ZH_WORDS_GETTER("wf_for_ws.fields.typename"), "daoju", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "GetWFForWSAccount", ZH_WORDS_GETTER("wf_for_ws.fields.account"), 1, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/ws/query/wf_for_ws", queryWorkFixtureForWorkStation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetWorkFixtureForWorkStationQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetWorkFixtureForWorkStation(query));
	}

private:
	// 3.3 分页查询数据
	GetWorkFixtureForWorkStationPageJsonVO::Wrapper execGetWorkFixtureForWorkStation(const GetWorkFixtureForWorkStationQuery::Wrapper& query);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

