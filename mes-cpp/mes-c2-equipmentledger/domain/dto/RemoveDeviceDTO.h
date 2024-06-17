#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/18 20:34:02

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
#ifndef _REMOVEDEVICEDTO_H_
#define _REMOVEDEVICEDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 列表DTO，可以将DTO分装成List
 * 负责人：。好
 */

// 利用列表DTO，来支持批量删除，如果其他人也需要的话，可以把这个类放成公共的
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, oatpp::DTO)
	// 数据列表
	API_DTO_FIELD(List<T>, item, ZH_WORDS_GETTER("list_dto"), false, {});
public:
	// 添加一条数据
	void addItem(const T& item) {
		this->item->push_back(item);
	}
};

/**
 * 删除设备DTO
 * 负责人：。好
 */
class RemoveDeviceDTO : public oatpp::DTO
{
	DTO_INIT(RemoveDeviceDTO, DTO)
	API_DTO_FIELD_DEFAULT(UInt64, device_id, 
		ZH_WORDS_GETTER("equipmentledger.remove-device.device-id"))
};

/**
 * 删除设备ListDTO
 * 负责人：。好
 */

// 继承自ListDTO
class RemoveDeviceListDTO : public ListDTO<RemoveDeviceDTO::Wrapper>
{
	DTO_INIT(RemoveDeviceListDTO, ListDTO<RemoveDeviceDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REMOVEDEVICEDTO_H_