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
#ifndef _PRODORDER1_CONTROLLER_
#define _PRODORDER1_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ProdTask/ProdTaskDTO.h"
#include "domain/vo/ProdTask/ProdTaskVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���������ѯ�������������ӿڵ�ʹ��
 */
class ProdTaskController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProdTaskController);
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("prod1.put.summary"), modifyProdTask, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodschedule/modify", modifyProdTask, BODY_DTO(ProdTaskModifyDTO::Wrapper, dto), execModifyProdTask(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeProdTask) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod1.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("prod1.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/prodmgmt/prodschedule/delete/{id}", removeProdTask, PATH(UInt64, id), execRemoveProdTask(id));

private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProdTask(const ProdTaskModifyDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveProdTask(const UInt64& id);
	// 3.3 ��������ʽ�������1
	//ProdOrderJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 ��������ʽ�������2
	//ProdOrderPageJsonVO::Wrapper execQueryAll(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRODORDER1_CONTROLLER