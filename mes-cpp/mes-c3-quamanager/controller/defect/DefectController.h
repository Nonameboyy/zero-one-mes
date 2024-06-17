#pragma once
#ifndef _DEFECT_CONTROLLER_
#define _DEFECT_CONTROLLER_

#include "domain/dto/defect/DefectDTO.h"
#include "domain/dto/defect/DefectModifyDTO.h"
#include "domain/query/defect/QcDefectQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/defect/DefectVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����ȱ�ݿ�����
 */
class DefectController : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(DefectController);

public:
	// 1 ��ȡȱ���б�����+��ҳ��
	ENDPOINT_INFO(queryDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DefectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "defect_name", ZH_WORDS_GETTER("defect.field.defect_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "index_type", ZH_WORDS_GETTER("defect.field.index_type"), "APPEARANCE", false);
		API_DEF_ADD_QUERY_PARAMS(String, "defect_level", ZH_WORDS_GETTER("defect.field.defect_level"), "MIN", false);
	}
	ENDPOINT(API_M_GET, "/defect/get-list", queryDefect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, QcDefectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDefect(userQuery, authObject->getPayload()));
	}

	// 2 ���ȱ��
	ENDPOINT_INFO(addDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/defect/add-defect", addDefect, BODY_DTO(DefectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDefect(dto, authObject->getPayload()));
	}

	// 3 �޸�ȱ��
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("defect.modify.summary"), modifyDefect, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(					 //
		API_M_PUT,								 //
		"/defect/modify-defect",				 //
		modifyDefect,							 //
		BODY_DTO(DefectModifyDTO::Wrapper, dto), //
		execModifyDefect(dto, authObject->getPayload())					 //
	);

	// 4 ɾ��ȱ��
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("defect.remove.summary"), removeDefect, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(			   //
		API_M_DEL,						   //
		"/defect/remove-defect/{id-list}", //
		removeDefect,					   //
		PATH(String, ids, "id-list"),	   //
		execRemoveDefect(ids)			   //
	);
	// ����ȱ��
	ENDPOINT_INFO(exportDefect)
	{
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("defect.export.summary"), Void);
	}
	ENDPOINT(												//
		API_M_POST,											//
		"/defect/export-defect",							//
		exportDefect,										//
		REQUEST(std::shared_ptr<IncomingRequest>, request), //
		API_HANDLER_AUTH_PARAME)
	{
		return execExportDefect(request);
	}
private:
	// 1 ��ȡȱ���б�����+��ҳ��
	DefectPageJsonVO::Wrapper execQueryDefect(const QcDefectQuery::Wrapper& query, const PayloadDTO& payload);
	// 2 ���ȱ��
	Uint64JsonVO::Wrapper execAddDefect(const DefectDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3 �޸�ȱ��
	Uint64JsonVO::Wrapper execModifyDefect(const DefectModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// 4 ɾ��ȱ��
	Uint64JsonVO::Wrapper execRemoveDefect(const String& ids);
	// 5 ����ȱ�ݡ�
	std::shared_ptr<OutgoingResponse> execExportDefect(std::shared_ptr<IncomingRequest> request);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_