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
#ifndef _EQUIPMENT_CONTROLLER_
#define _EQUIPMENT_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/vo/equipment/EquipmentTypeTreeVO.h"
#include "../../domain/query/equipment/EquipmentQuery.h"
#include "../../domain/vo/equipment/EquipmentVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class EquipmentController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(EquipmentController);
	// 3 ����ӿ�
public:	
	// �����ѯ�豸���������б����ӿڶ˵�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipment.getEquipmentTypeTree.summary"), getEquipmentTypeTree, EquipmentTypeTreeVO::Wrapper);
	// �����ѯ�豸���������б����ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/ws/equipment/getEquipmentTypeTree", getEquipmentTypeTree, executeGetEquipmentTypeTree(authObject->getPayload()));

	//��ȡ�豸�б�(���� + ��ҳ)
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(getEquipmentList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.getEquipmentList.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentPageVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "equimentCode", ZH_WORDS_GETTER("equipmentQuery.equimentCode"), "M0024", false);
		API_DEF_ADD_QUERY_PARAMS(String, "equimentName", ZH_WORDS_GETTER("equipmentQuery.equimentName"), "������Ա", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/equipment/getEquipmentList", getEquipmentList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(equipmentQuery, EquipmentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetEquipmentList(equipmentQuery, authObject->getPayload()));
	}

private:
	//��ȡ�豸����������
	EquipmentTypeTreeVO::Wrapper executeGetEquipmentTypeTree(const PayloadDTO& payload);
	// 3.3 �豸��ҳ��ѯ����
	EquipmentPageVO::Wrapper execGetEquipmentList(const EquipmentQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // EquipmentController