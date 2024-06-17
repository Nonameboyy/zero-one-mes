#pragma once

#ifndef _GETWORKSTATIONLISTCONTROLLER_H_
#define _GETWORKSTATIONLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/get-wf-for-ws/GetWorkFixtureForWorkStationQuery.h"
#include "domain/dto/get-wf-for-ws/GetWorkFixtureForWorkStationDTO.h"
#include "domain/vo/get-wf-for-ws/GetWorkFixtureForWorkStationVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetWorkFixtureForWorkStationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(GetWorkFixtureForWorkStationController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkFixtureForWorkStation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("wf_for_ws.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetWorkFixtureForWorkStationJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "GetWFForWSTypeName", ZH_WORDS_GETTER("wf_for_ws.fields.typename"), "daoju", false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "GetWFForWSAccount", ZH_WORDS_GETTER("wf_for_ws.fields.account"), 1, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/query/wf_for_ws", queryWorkFixtureForWorkStation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, GetWorkFixtureForWorkStationQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetWorkFixtureForWorkStation(query));
	}

private:
	// 3.3 ��ҳ��ѯ����
	GetWorkFixtureForWorkStationPageJsonVO::Wrapper execGetWorkFixtureForWorkStation(const GetWorkFixtureForWorkStationQuery::Wrapper& query);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

