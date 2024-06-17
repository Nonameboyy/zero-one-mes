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
#ifndef _ADDRECPT_CONTROLLER_
#define _ADDRECPT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/document/AddrecptDTO.h"
#include "domain/vo/document/AddrecptVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AddrecptController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddrecptController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addrecpt) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("recpt.post.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ:�����ظ�ǰ�˵Ľ��Ϊjson��ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/storage/add-documents", addrecpt, BODY_DTO(AddrecptDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���:���������ݷ�װ��dto�д���������
		API_HANDLER_RESP_VO(execAddrecpt(dto));
	}

	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddrecpt(const AddrecptDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_