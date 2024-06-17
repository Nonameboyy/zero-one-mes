#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/5/18/21:38

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
#ifndef _REPAIRCONTENT_CONTROLLER_
#define _REPAIRCONTENT_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repaircontent/RepaircontentQuery.h"
#include "domain/dto/repaircontent/RepaircontentDTO.h"
#include "domain/dto/repaircontent/DeleteMultiRepaircontentDTO.h"
#include "domain/vo/repaircontent/RepaircontentVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ά�޵����ݿ���������ʾ�����ӿڵ�ʹ��
 */
class RepaircontentController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RepaircontentController);
	// 3 ����ӿ�
public:
	//ά�޵����ݲ�ѯ �ӿ�����
	ENDPOINT_INFO(queryRepaircontent) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.query_repaircontent"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RepaircontentPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "repair_id", ZH_WORDS_GETTER("repaircontent.get.repair_id"), , false);
		API_DEF_ADD_QUERY_PARAMS(String, "subject_name", ZH_WORDS_GETTER("repaircontent.get.repair_name")," ", false);
	}
	//ά�޵����ݲ�ѯ �ӿڴ���
	ENDPOINT(API_M_GET, "/equipment-ledger/repairorder/query-repaircontent", queryRepaircontent, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(repair_id, RepaircontentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRepaircontent(repair_id));
	}


	// ����豸ά�޵��� �ӿ�����
	ENDPOINT_INFO(addRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.add_repaircontent"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���ά�޵� �ӿڴ���
	ENDPOINT(API_M_POST, "/equipment-ledger/repairorder/add-repaircontent", addRepaircontent, BODY_DTO(AddRepaircontentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRepaircontent(dto, authObject->getPayload()));
	}

	// �޸�ά�޵� �ӿ�����
	ENDPOINT_INFO(modifyRepaircontent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repaircontent.get.modify_repaircontent"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// �޸�ά�޵� �ӿڴ���
	ENDPOINT(API_M_PUT, "/equipment-ledger/repairorder/modify-repaircontent", modifyRepaircontent, BODY_DTO(ModifyRepaircontentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execModifyRepaircontent(dto, authObject->getPayload()));
	}

	// ɾ��ά�޵� �ӿ�����
	ENDPOINT_INFO(removeRepaircontent) {
		// ����ӿڱ���
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repaircontent.get.remove_repaircontent"), StringJsonVO::Wrapper);

		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}
	// ɾ��ά�޵� �ӿڴ���
	ENDPOINT(API_M_DEL, "/equipment-ledger/repairorder/del-repaircontent", removeRepaircontent, BODY_DTO(DeleteMultiRepaircontentDTO::Wrapper, line_idList), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execRemoveRepaircontent(line_idList));
	}

	
private:
	//ά�޵���ҳ���ݲ�ѯ
	RepaircontentPageJsonVO::Wrapper execQueryRepaircontent(const RepaircontentQuery::Wrapper& id);

	// 3.3 ά�޵�������������
	RepaircontentJsonVO::Wrapper execDetailsRepaircontent(const RepaircontentQuery::Wrapper& id);	
	// 3.3 ���ά�޵�����
	Uint64JsonVO::Wrapper execAddRepaircontent(const AddRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 �޸�ά�޵�����
	Uint64JsonVO::Wrapper execModifyRepaircontent(const ModifyRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ɾ��ά�޵�����
	Uint64JsonVO::Wrapper execRemoveRepaircontent(const DeleteMultiRepaircontentDTO::Wrapper& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _REPAIRCONTENT_CONTROLLER_