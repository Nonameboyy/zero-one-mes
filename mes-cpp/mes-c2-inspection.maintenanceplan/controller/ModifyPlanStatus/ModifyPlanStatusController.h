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
#ifndef _MODIFTY_PLAN_STATUS_CONTROLLER_H_
#define _MODIFTY_PLAN_STATUS_CONTROLLER_H_

#include "../../domain/vo/ModifyPlanStatus/ModifyPlanStatusVo.h"
#include "../../domain/dto/ModifyPlanStatus/ModifyPlanStatusDto.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 修改保养点检计划状态控制
 */
class ModifyPlanStatusController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyPlanStatusController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述;
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("modifyplanstatus.summary"), modifyplanstatus, ModifyPlanStatusDto::Wrapper);
	//// 3.2 定义修改接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ModifyPlanStatus/modify-plan-status", modifyplanstatus, BODY_DTO(ModifyPlanStatusDto::Wrapper, dto), execModifyPlanStatus(dto));
	
	// 4定义修改设备端点处理
	ENDPOINT(API_M_PUT, "/equipment-ledger/inspe-matain/modify-plan-status", modifyplanstatus, BODY_DTO(ModifyPlanStatusDto::Wrapper, dto), API_HANDLER_AUTH_PARAME) {

		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyPlanStatus(dto, authObject->getPayload()));
	}
private:
	// 3.3 演示修改数据
	ModifyPlanStatusJsonVo::Wrapper execModifyPlanStatus(const ModifyPlanStatusDto::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_