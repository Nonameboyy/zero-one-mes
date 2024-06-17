/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/18 19:50:23

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
#ifndef _REMOVEDEVICECONTROLLER_H_
#define _REMOVEDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/RemoveDeviceDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

// 删除数据不需要自定义JsonVO，只要返回true或false即可，直接使用学长在BaseJsonVO.h中定义的BooleanJsonVO即可
// 删除数据不需要Query参数，没有分页查询或者其它额外的参数，它的删除是通过前端由用户在基础表单数据项中勾选得到的

class RemoveDeviceController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveDeviceController)
public: // 定义接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipmentledger.remove-device.summary"), removeDevice, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/equip/remove-device", removeDevice, BODY_DTO(RemoveDeviceListDTO::Wrapper, dto), execRemoveDevice(dto))
private: // 定义接口执行函数

	// 前端发过来的dto由这个函数执行
	BooleanJsonVO::Wrapper execRemoveDevice(const RemoveDeviceListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVEDEVICECONTROLLER_H_