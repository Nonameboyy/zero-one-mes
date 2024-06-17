#pragma once
#ifndef _ADD_CONTROLLER_H_
#define _ADD_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/addplan/AddPlanVO.h"
#include"./domain/dto/addplan/AddPlanDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��Ŀ�ƻ�������
 */
class AddPlanController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddPlanController);
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addplanTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add-mj.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/equipment-ledger/inspe-matain/add-plan", addplanTable, BODY_DTO(AddPlanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddplan(dto, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddplan(const AddPlanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_