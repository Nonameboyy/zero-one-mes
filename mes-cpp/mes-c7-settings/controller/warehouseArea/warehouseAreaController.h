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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehouseArea/warehouseAreaQuery.h"
#include "domain/dto/warehouseArea/warehouseAreaDTO.h"
#include "domain/vo/warehouseArea/warehouseAreaVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �������������
 */
class warehouseAreaController : public oatpp::web::server::api::ApiController //�̳п�����
{
	//����������������
	API_ACCESS_DECLARE(warehouseAreaController);
	//����ӿ�
public:
	// 1.1 �����ѯ�ӿ�����:�ӿ���ΪqueryWarehouseArea
	ENDPOINT_INFO(queryWarehouseArea) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse-area.query.summary"));//"��ҳ��ѯ��������"
		// ����Ĭ����Ȩ���������ʽӿ���Ҫ�����֤,����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(warehouseAreaPageJsonVO);
		// �����ҳ��ѯ��������:�˵�֧�ַ�ҳ��ѯ-�ṩ��ҳ��������ı�׼����
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ�������� ע�⣡��query�ﶨ���������ͬ,����Ϊ�Ǳ������,�����չʾ��ȫ������
		API_DEF_ADD_QUERY_PARAMS(String, "warehouseAreaName", ZH_WORDS_GETTER("warehouse-area.field.name"),"default name",false);
	}
	// 1.2 �����ѯ�ӿڴ���:·�ɵ�URL/warehouseArea�ҵ�queryWarehouseArea�˵�,������ѯ����queryParams
	ENDPOINT(API_M_GET, "/settings/location/query-warehouse_location-page", queryWarehouseArea, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪWarehouseAreaQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, WarehouseAreaQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryWarehouseArea(query));
	}

	//2.1�������������ӿ�����
	ENDPOINT_INFO(addWarehouseArea){
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse-area.post.summary"));//"����һ����������"
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 2.2 ���������ӿڴ��� ע�⣡��������������Ȼ���˿���id,������ʵ��û�д������id,���ǰ������ݿ�������ʽ���ɿ���id
	ENDPOINT(API_M_POST, "/settings/location/add-warehouse_location", addWarehouseArea, BODY_DTO(warehouseAreaListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddWarehouseArea(dto));
	}

	// 3.1 �����޸Ŀ����ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("warehouse-area.put.summary"), modifyWarehouseArea, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ŀ����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/location/mod-warehouse_location", modifyWarehouseArea, BODY_DTO(warehouseAreaListDTO::Wrapper, dto), execModifyWarehouseArea(dto));

	//// 4.1 ����ɾ���ӿ�����
	//ENDPOINT_INFO(removeWarehouseArea) {
	//	// �������ͷ��������Լ���Ȩ֧��
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("warehouse-area.delete.summary"), Uint64JsonVO::Wrapper);
	//	// ��������·������˵��:ע��˴�������Ҫ��DTO������ڶ�Ӧ,Ĭ��ֵ=1,require=true
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "area_id", ZH_WORDS_GETTER("warehouse-area.field.id"), 1, true);
	//}
	//// 4.2 ����ɾ���ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/warehouseArea-settings/del-warehouseArea-by/{area_id}", removeWarehouseArea, PATH(UInt64, area_id), execRemoveWarehouseArea(area_id));
	// 4.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeWarehouseArea) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("warehouse-area.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// 4.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/location/del-warehouse_location-by-location_id/{location_id}", removeWarehouseArea, BODY_DTO(List<UInt64>,ids), execRemoveWarehouseArea(ids));

	
private:
	// 1.3 ��ҳ��ѯ����
	warehouseAreaPageJsonVO::Wrapper execQueryWarehouseArea(const WarehouseAreaQuery::Wrapper& query);
	// 2.3������������
	Uint64JsonVO::Wrapper execAddWarehouseArea(const warehouseAreaListDTO::Wrapper& dto);
	// 3.3�޸Ŀ�������
	Uint64JsonVO::Wrapper execModifyWarehouseArea(const warehouseAreaListDTO::Wrapper& dto);
	// 4.3ɾ����������
	Uint64JsonVO::Wrapper execRemoveWarehouseArea(const List<UInt64>& ids);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_