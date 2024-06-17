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
#ifndef _DEVICERESOURCE_CONTROLLER_
#define _DEVICERESOURCE_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c1-workstation/domain/query/deviceresource/DeviceResourceQuery.h"
#include "../mes-c1-workstation/domain/vo/deviceresource/DeviceResourceVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 设备资源控制器，演示基础接口的使用
 */
class DeviceResourceController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeviceResourceController);
	// 3 定义接口
public:
	//获取设备列表(条件 + 分页)
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(getDeviceResourcetList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deviceResource.getDeviceResourcetList.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DeviceResourcePageVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/ws/deviceResource/getDeviceResourcetList", getDeviceResourcetList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(deviceResourceQuery, DeviceResourceQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetDeviceResourceList(deviceResourceQuery, authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addDeviceResource) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deviceResource.addDeviceResource.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ws/deviceResource/addDeviceResource", addDeviceResource, BODY_DTO(DeviceResourceDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDeviceResource(dto));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("deviceResource.modifyDeviceResource.summary"), modifyDeviceResource, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ws/deviceResource/modifyDeviceResource", modifyDeviceResource, BODY_DTO(DeviceResourceDTO::Wrapper, dto), execModifyDeviceResource(dto));
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deleteDeviceResource) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("deviceResource.deleteDeviceResource.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "deviceResourceId", ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.deviceResourceId"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/deviceResource/removeDeviceResource/{deviceResourceId}", deleteDeviceResource, PATH(UInt64, deviceResourceId), execDeleteDeviceResource(deviceResourceId));

private:
	// 3.3 设备资源分页查询数据
	DeviceResourcePageVO::Wrapper execGetDeviceResourceList(const DeviceResourceQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 设备资源新增数据
	Uint64JsonVO::Wrapper execAddDeviceResource(const DeviceResourceDTO::Wrapper& dto);
	// 3.3 设备资源修改数据
	Uint64JsonVO::Wrapper execModifyDeviceResource(const DeviceResourceDTO::Wrapper& dto);
	// 3.3 设备资源删除数据
	Uint64JsonVO::Wrapper execDeleteDeviceResource(const UInt64& deviceResourceId);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEVICERESOURCE_CONTROLLER_