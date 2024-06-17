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
#ifndef _PRODUCEWORK_CONTROLLER_
#define _PRODUCEWORK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ProduceWork/ProduceWorkDTO.h"
#include "domain/vo/ProduceWork/ProduceWorkJsonVO.h"

/*
������Ա��������
*/

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������������
 */
class ProController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//  2 ����������������
	API_ACCESS_DECLARE(ProController);
	//  3 ����ӿ�
public:
	 //3.1 �����ȡ��������
	ENDPOINT_INFO(queryProduceWorkFeedbackDetail) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProduceWork.query.summary"), ProduceWorkJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/prodmgmt/prodreport/querydetail/{record_id}", queryProduceWorkFeedbackDetail, PATH(UInt64, record_id), execProduceWorkDetail(record_id));

	// ������ӱ����ӿ�
	ENDPOINT_INFO(addProduceWork) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("ProduceWork.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/prodmgmt/prodreport/add", addProduceWork, BODY_DTO(ProduceWorkDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProduceWork(dto));
	}

	// �޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ProduceWork.put.summary"), modifyProduceWork, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodreport/modify", modifyProduceWork, BODY_DTO(ProduceWorkDTO::Wrapper, dto), execModifyProduceWork(dto));
private:
	// 
	ProduceWorkJsonVO::Wrapper execProduceWorkDetail(const UInt64& record_id);

	
	Uint64JsonVO::Wrapper execAddProduceWork(const ProduceWorkDTO::Wrapper& dto);

	
	Uint64JsonVO::Wrapper execModifyProduceWork(const ProduceWorkDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_SAMPLE_CONTROLLER_