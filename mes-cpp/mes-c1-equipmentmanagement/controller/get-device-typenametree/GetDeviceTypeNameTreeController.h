#pragma once

#ifndef _GETDEVICETYPETREECONTROLLER_H_
#define _GETDEVICETYPETREECONTROLLER_H

#include"../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include"../../domain/vo/device-type-nametree/DeviceTypeNameTreeVo.h"
#include"../../domain/query/get-device-typenametree/GetDeviceTypeNameTreeQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 设备类型控制器
*/
class GetDeviceTypeNameTreeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(GetDeviceTypeNameTreeController);
public://定义接口
	// 定义获取设备类型名称树接口端点描述和接口端点处理
	ENDPOINT_INFO(queryDeviceNameTree) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("devicet.query.tree"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DeviceTypeNameTreeJsonVo);
		// 查询参数只有一个类型名称（可选）
		API_DEF_ADD_QUERY_PARAMS(String, "machineryTypeName", ZH_WORDS_GETTER("devicet.fields.tname"), {}, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/GetDeviceTypeTree/query-device-type-Tree", queryDeviceNameTree, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetDeviceTypeNameTreeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryNameTree(query));
	}

private: //定义接口执行函数
	DeviceTypeNameTreeJsonVo::Wrapper execQueryNameTree(const GetDeviceTypeNameTreeQuery::Wrapper &name);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETDEVICETYPECONTROLLER_H_