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
#ifndef _MODIFY_EQUIPMENT_TYPE_DTO_H_
#define _MODIFY_EQUIPMENT_TYPE_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)




class ModifyEquipmentTypeDTO : public oatpp::DTO
{
	DTO_INIT(ModifyEquipmentTypeDTO, DTO);
	// 类型编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.id");
	}
	// 类型名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.name");
	}

	// 父类型编号  UInt64
	DTO_FIELD(UInt64, parentId);
	DTO_FIELD_INFO(parentId) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.parent-id");
	}

	// 备注			String
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.remark");
	}
	// 是否启用    Boolean   Y   N
	DTO_FIELD(Boolean, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.enable");
	}
	// 修改时间     String
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("equipment-type.field.update-time");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif