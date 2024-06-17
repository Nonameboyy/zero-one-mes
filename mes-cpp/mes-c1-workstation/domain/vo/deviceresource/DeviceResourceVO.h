#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under theLicense.
*/
#ifndef _DEVICE_RESOURCE_VO_
#define _DEVICE_RESOURCE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/deviceresource/DeviceResourceDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 设备资源显示VO，用于响应给客户端的Json对象
 */
class DeviceResourceVO : public JsonVO<DeviceResourceDTO::Wrapper> {
	DTO_INIT(DeviceResourceVO, JsonVO<DeviceResourceDTO::Wrapper>);
};

/**
 * 设备资源分页显示JsonVO，用于响应给客户端的Json对象
 */
class DeviceResourcePageVO : public JsonVO<DeviceResourcePageDTO::Wrapper> {
	DTO_INIT(DeviceResourcePageVO, JsonVO<DeviceResourcePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DEVICE_RESOURCE_VO_