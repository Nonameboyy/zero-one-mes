#pragma once

#ifndef _ADDDEVICETYPECONTROLLER_H_
#define _ADDDEVICETYPECONTROLLER_H

#include"domain/vo/BaseJsonVO.h"
#include"domain/dto/adddevice-type/AddDeviceTypeListDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 设备类型控制器
*/

class AddDeviceTypeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(AddDeviceTypeController);
public://定义接口
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(AddDeviceSample) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("devicet.query.type"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/equipment-ledger/AddDeviceType/Add-device-type", AddDeviceSample, BODY_DTO(AddDeviceTypeListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDeviceType(dto, authObject->getPayload()));
	}
private: //定义接口执行函数
	// 新增设备类型
	Uint64JsonVO::Wrapper execAddDeviceType(const AddDeviceTypeListDTO::Wrapper& dto, const PayloadDTO &payload);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDDEVICETYPECONTROLLER_H_