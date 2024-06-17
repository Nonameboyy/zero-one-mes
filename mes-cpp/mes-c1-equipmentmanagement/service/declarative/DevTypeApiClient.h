#pragma once

#include"oatpp/web/client/ApiClient.hpp"
#include"ApiHelper.h"
class DevTypeApiClient : public oatpp::web::client::ApiClient
{
	// 3 定义ApiClient控制器使用宏---开始
#include OATPP_CODEGEN_BEGIN(ApiClient)

	// 4 初始化定义
	API_CLIENT_INIT(DevTypeApiClient);

	// 5 使用API_CALL或API_CALL_ASYNC声明调用服务接口

	// 获取设备类型编码
	API_CALL(API_M_GET, "/deviceType/getCode", getDevTypeCode, API_HANDLER_AUTN_HEADER, QUERY(String, type));

#include OATPP_CODEGEN_END(ApiClient)
	// 3 取消ApiClient控制器使用宏---结束
};