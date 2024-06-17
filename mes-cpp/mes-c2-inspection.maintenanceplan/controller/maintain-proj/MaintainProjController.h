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
#ifndef _MAINTAINPROJ_CONTROLLER_
#define _MAINTAINPROJ_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/maintain-proj/MaintailProjDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class MaintainProjController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(MaintainProjController);
	// 3 ����ӿ�
public:


	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("maintain-proj.summary.add-proj"), addProj, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/equipment-ledger/inspe-matain/add-proj", addProj, BODY_DTO(MaintainProjDTO::Wrapper, dto), execAddProj(dto, authObject->getPayload()));

private:

	Uint64JsonVO::Wrapper execAddProj(const MaintainProjDTO::Wrapper& dto, const PayloadDTO& payload);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MAINTAINPROJ_CONTROLLER_