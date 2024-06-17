#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _EQUIPMENTCONTROLLER_H_
#define _EQUIPMENTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/equipment/EquipmentVO.h"
#include "domain/query/equipment/EquipmentQuery.h"
#include "domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class EquipmentController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(EquipmentController);
public:
	// 1 �����豸�б��ѯ�ӿ�����
	ENDPOINT_INFO(queryEquipment) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
	
		//�豸����
		API_DEF_ADD_QUERY_PARAMS(String, "eCode", ZH_WORDS_GETTER("equipment.fields.ecode"), "M0066", false);
		//�豸����
		API_DEF_ADD_QUERY_PARAMS(String, "eName", ZH_WORDS_GETTER("equipment.fields.ename"), "TextileMachinery", false);
	}
	// 1 �����豸�б��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/query-equipment", queryEquipment, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, EquipmentQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execEquipment(query));
	}

	// 2 �����豸�����ѯ�ӿ�����
	ENDPOINT_INFO(queryEquipmentDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentDetailJsonVO);
		// ����������ѯ��������
		
		//�豸ID
		API_DEF_ADD_QUERY_PARAMS(UInt64, "eId", ZH_WORDS_GETTER("equipment.fields.id"),217, true);
	}
	// 2 �����豸�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/query-detail", queryEquipmentDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, EquipmentDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execEquipmentDetail(query));
	}

	// 3 ���������ӿ�����
	ENDPOINT_INFO(addEquipment) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/equipment-ledger/equip/add-equipment", addEquipment, BODY_DTO(addEquipmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddEquipment(dto, authObject->getPayload()));
	}

	//4 �����޸��豸�˵�����
	ENDPOINT_INFO(modifyEquipment) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary3"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 4�����޸��豸�˵㴦��
	ENDPOINT(API_M_PUT, "/equipment-ledger/equip/modify-equipment", modifyEquipment, BODY_DTO(modifyEquipmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {

		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeModifyEquipment(dto, authObject->getPayload()));
	}

	
	
	

private:
	//��ȡ�豸�б�����+��ҳ��
	EquipmentPageJsonVO::Wrapper execEquipment(const EquipmentQuery::Wrapper& query);
	//��ȡ�豸����
	EquipmentDetailJsonVO::Wrapper execEquipmentDetail(const EquipmentDetailQuery::Wrapper& query);
	//�����豸
	Uint64JsonVO::Wrapper execAddEquipment(const addEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	//�޸��豸
	Uint64JsonVO::Wrapper executeModifyEquipment(const modifyEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 

