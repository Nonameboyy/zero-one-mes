#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _EQUIPMENTVO_H_
#define _EQUIPMENTVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/equipment/EquipmentDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 设备列表显示VO
 */
class EquipmentJsonVO : public JsonVO< EquipmentDTO::Wrapper>
{
	DTO_INIT(EquipmentJsonVO, JsonVO< EquipmentDTO::Wrapper>);
public:
	EquipmentJsonVO(){
		this->data = {};
	}
};
/**
 * 定义一个设备列表分页显示JsonVO对象
 */
class EquipmentPageJsonVO : public JsonVO<EquipmentPageDTO::Wrapper>
{
	DTO_INIT(EquipmentPageJsonVO, JsonVO<EquipmentPageDTO::Wrapper>);
};
/**
 * 定义一个设备详情显示JsonVO对象
 */
class EquipmentDetailJsonVO : public JsonVO<EquipmentDetailDTO::Wrapper>
{
	DTO_INIT(EquipmentDetailJsonVO, JsonVO<EquipmentDetailDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif 

