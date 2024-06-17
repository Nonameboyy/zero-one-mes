#pragma once
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
#ifndef _ADDDEVICE_CONTROLLER_
#define _ADDDEVICE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/adddevice/AddDeviceDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AddDeviceController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AddDeviceController);
	// 3 定义接口
public:
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("device-list.summary.add-proj"), addProj, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/equipment-ledger/inspe-matain/add-device", addProj, BODY_DTO(AddDeviceDTO::Wrapper, dto), execAddProj(dto, authObject->getPayload()));



private:

	Uint64JsonVO::Wrapper execAddProj(const AddDeviceDTO::Wrapper& dto, const PayloadDTO& payload);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEVICELIST_CONTROLLER_