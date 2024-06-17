#pragma once

#ifndef _GETDEVICETYPECONTROLLER_H_
#define _GETDEVICETYPECONTROLLER_H

#include"../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include"../../domain/vo/device-type-detail/DeviceTypeDetailVo.h"
#include"../../domain/query/get-device-typedetail/GetDeviceTypeDetailQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 设备类型控制器
*/	
class GetDeviceTypeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(GetDeviceTypeController);
public://定义接口
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryDeviceSample) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("devicet.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DeviceTypeDetailJsonVo);
		//类型名称
		API_DEF_ADD_QUERY_PARAMS(String, "machineryTypeName", ZH_WORDS_GETTER("devicet.fields.tname"), {}, false);
		//是否启用
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("devicet.fields.status"), {}, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/GetDeviceType/query-device-type", queryDeviceSample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetDeviceTypeDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTypeNameDetail(query));
	}

private: //定义接口执行函数

	//查询单条详情数据
	DeviceTypeDetailJsonVo::Wrapper execQueryTypeNameDetail(const GetDeviceTypeDetailQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETDEVICETYPECONTROLLER_H_