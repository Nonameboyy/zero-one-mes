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
#ifndef _ADDDELMOD_CONTROLLER_
#define _ADDDELMOD_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/add-del-mod/AddDelModQuery.h"
#include "domain/dto/add-del-mod/AddDelModDTO.h"
#include "domain/vo/add-del-mod/AddDelModVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AddDelModController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddDelModController);
	// 3 ����ӿ�
public:
	
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addWarehouse) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add-del-mod.controller.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/settings/add-warehouse", addWarehouse, BODY_DTO(AddDelModDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddWarehouse(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("add-del-mod.controller.put.summary"), modifyWarehouse, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/mod-warehouse", modifyWarehouse, BODY_DTO(AddDelModDTO::Wrapper, dto), execModifyWarehouse(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeWarehouse) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("add-del-mod.controller.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "warehouse_id", ZH_WORDS_GETTER("add-del-mod.controller.delete.warehouse_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/del-warehouse-by-warehouse_id/{warehouse_id}", removeWarehouse, PATH(UInt64, warehouse_id), execRemoveWarehouse(warehouse_id));

private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddWarehouse(const AddDelModDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyWarehouse(const AddDelModDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveWarehouse(const UInt64& warehouse_id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDDELMOD_CONTROLLER_