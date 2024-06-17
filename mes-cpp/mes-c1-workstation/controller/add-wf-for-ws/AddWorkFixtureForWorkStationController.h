#pragma once

#ifndef _WORKFIXTUREFORWORKSTATION_CONTROLLER_H_
#define _WORKFIXTUREFORWORKSTATION_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/add-wf-for-ws/AddWorkFixtureForWorkStationDTO.h"
#include "domain/vo/add-wf-for-ws/AddWorkFixtureForWorkStationVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AddWorkFixtureForWorkStationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddWorkFixtureForWorkStationController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addWorkFixtureForWorkStation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("wf_for_ws.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ws/add/wf_for_ws", addWorkFixtureForWorkStation, BODY_DTO(AddWorkFixtureForWorkStationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddWorkFixtureForWorkStation(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddWorkFixtureForWorkStation(const AddWorkFixtureForWorkStationDTO::Wrapper& dto);
};


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
