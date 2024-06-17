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
#ifndef _MODIFTYCONTROLLER_H_
#define _MODIFTYCONTROLLER_H_

#include "../../domain/vo/MaintenancePlan/MaintenancePlanVo.h"
#include "../../domain/dto/MaintenancePlan/MaintenancePlanDto.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �޸ı������ƻ�����
 */
class ModifyPlanController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyPlanController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����;
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("maintenanceplan.summary"), modifyplan, MaintenancePlanDto::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ModifyPlan/modify-plan", modifyplan, BODY_DTO(MaintenancePlanDto::Wrapper, dto), BODY_DTO(PayloadDTO, payload) execModifyPlan(dto,payload));

	// 4�����޸��豸�˵㴦��
	ENDPOINT(API_M_PUT, "/equipment-ledger/inspe-matain/modify-plan", modifyplan, BODY_DTO(MaintenancePlanDto::Wrapper, dto), API_HANDLER_AUTH_PARAME) {

		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyPlan(dto, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ�޸�����
	MaintenancePlanJsonVo::Wrapper execModifyPlan(const MaintenancePlanDto::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_