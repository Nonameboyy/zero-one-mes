#pragma once
#ifndef __AREACONTROLLER_H__
#define __AREACONTROLLER_H__

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/storagearea/AreaDTO.h"
#include "domain/query/storagearea/AreaQuery.h"
#include "domain/vo/storagearea/AreaJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)
class AreaController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(AreaController)
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryArea) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagearea.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AreaPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������	
		API_DEF_ADD_QUERY_PARAMS(Int64, "location_id", ZH_WORDS_GETTER("storagearea.fields.locationId"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_code", ZH_WORDS_GETTER("storagearea.fields.areacode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("storagearea.fields.areaname"), "", false);	
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_x", ZH_WORDS_GETTER("storagearea.fields.positionx"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_y", ZH_WORDS_GETTER("storagearea.fields.positiony"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_z", ZH_WORDS_GETTER("storagearea.fields.positionz"), 0, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/settings/area/query-warehouse_area-page", queryArea, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, AreaQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryArea(userQuery,authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addArea) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagearea.add.insert"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
		
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/settings/area/add-warehouse_area", addArea, BODY_DTO(AreaDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddArea(dto, authObject->getPayload()));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storagearea.modify.update"), modifyArea, Uint64JsonVO::Wrapper)
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/area/mod-warehouse_area", modifyArea, BODY_DTO(AreaDTO::Wrapper, dto), execModifyArea(dto, authObject->getPayload()));

	// 3.1 ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storagearea.remove.delete"), removeArea, Uint64JsonVO::Wrapper)
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/area/del-warehouse_area-by-area_id/{area_id}", removeArea, BODY_DTO(List<Int32>, idsdto), execRemoveArea(idsdto));

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	AreaPageJsonVO::Wrapper execQueryArea(const AreaQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveArea( const oatpp::List<Int32>& idsdto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif //__AREACONTROLLER_H__