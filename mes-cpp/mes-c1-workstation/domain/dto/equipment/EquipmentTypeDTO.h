#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/04/11 15:00:21

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
#ifndef _EQUIPMENTTYPEDTO_H_
#define _EQUIPMENTTYPEDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例设备数据传输对象
 */
class EquipmentTypeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(EquipmentTypeDTO, DTO);
	// 设备类型id
	API_DTO_FIELD_DEFAULT(String, machineryTypeId, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.machineryTypeId"));
	// 设备类型编码
	API_DTO_FIELD_DEFAULT(String, machineryTypeCode, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.machineryTypeCode"));
	// 设备类型名称
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.machineryTypeName"));
	// 是否启用
	API_DTO_FIELD(Int32, enableFlag, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.enableFlag"),  false, 0);
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.remark"));
	// 设备类型父id
	API_DTO_FIELD_DEFAULT(String, parentTypeId, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.parentTypeId"));
	// 子设备列表
	API_DTO_FIELD(List<EquipmentTypeDTO::Wrapper>, children, ZH_WORDS_GETTER("equipment.equipmentTypeTreeDto.child"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<EquipmentTypeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUDTO_H_