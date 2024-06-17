#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _DEVICE_RESOURCE_DTO_
#define _DEVICE_RESOURCE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 设备传输对象
 */
class DeviceResourceDTO : public oatpp::DTO
{
	DTO_INIT(DeviceResourceDTO, DTO);
	// 工作站id
	DTO_FIELD(UInt64, workstationId);
	DTO_FIELD_INFO(workstationId) {
		info->description = ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.workstationId");
	}
	// 设备id
	DTO_FIELD(UInt64, machineryId);
	DTO_FIELD_INFO(machineryId) {
		info->description = ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.machineryId");
	}
	// 设备编号
	DTO_FIELD(String, equipmentCode);
	DTO_FIELD_INFO(equipmentCode) {
		info->description = ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.equipmentCode");
	}
	// 设备名称
	DTO_FIELD(String, equipmentName);
	DTO_FIELD_INFO(equipmentName) {
		info->description = ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.equipmentName");
	}
	// 数量
	DTO_FIELD(UInt64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.quantity");
	}
};

/**
 * 设备资源分页传输对象
 */
class DeviceResourcePageDTO : public PageDTO<DeviceResourceDTO::Wrapper>
{
	DTO_INIT(DeviceResourcePageDTO, PageDTO<DeviceResourceDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DEVICESOURCE_DTO_