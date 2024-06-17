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
#ifndef _MODIFY_EQUIPMENT_TYPE_CONTROLLER_H_ 
#define _MODIFY_EQUIPMENT_TYPE_CONTROLLER_H_ 

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/modify-equipment-type/ModifyEquipmentTypeDTO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ModifyEquipmentTypeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyEquipmentTypeController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipment-type.put.summary"), modifyEquipmentType, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/equipment-ledger/equipmentmanagement/modify-type", modifyEquipmentType, BODY_DTO(ModifyEquipmentTypeDTO::Wrapper, dto), execModifyEquipmentType(dto));

private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyEquipmentType(const ModifyEquipmentTypeDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MODIFY_EQUIPMENT_TYPE_CONTROLLER_ 