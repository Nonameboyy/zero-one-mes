#pragma once

#ifndef _SINGLE_DEFECT_CONTROLLER_
#define _SINGLE_DEFECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Single_Defect/Single_Defect_Query.h"
#include "domain/dto/Single_Defect/Single_Defect_DTO.h"
#include "domain/vo/Single_Defect/Single_Defect_VO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �����ģ�������
 */
class Single_Defect_Controller : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(Single_Defect_Controller);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�����ӿ�����
	ENDPOINT_INFO(querySingle) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.detail.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SinglePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "iqc_id", ZH_WORDS_GETTER("single.iqc_id"), 1, true);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/incoming-inspect/index-search", querySingle, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, SingleQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySingle(userQuery, authObject->getPayload()));
	}

	// 3.1 �����ѯȱ�ݽӿ�����
	ENDPOINT_INFO(queryDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.defect.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DefectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("single.line"), 1, false);
	}
	// 3.2 �����ѯȱ�ݽӿڴ���
	ENDPOINT(API_M_GET, "/incoming-inspect/defect-search", queryDefect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DefectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDefect(userQuery, authObject->getPayload()));
	}

	// 3.1 ��������ȱ�ݽӿ�����
	ENDPOINT_INFO(addDefect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("single.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ��������ȱ�ݽӿڴ���
	ENDPOINT(API_M_POST, "/incoming-inspect/defect-add", addDefect, BODY_DTO(DefectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDefect(dto));
	}

	// 3.1 �����޸�ȱ�ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("single.change.summary"), modifyDefect, Uint64JsonVO::Wrapper);
	// 3.2 �����޸�ȱ�ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming-inspect/defect-change", modifyDefect, BODY_DTO(DefectDTO::Wrapper, dto), execModifyDefect(dto));

	// 3.1 ����ɾ��ȱ�ݽӿ�����
	ENDPOINT_INFO(removeDefect) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("single.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("single.record_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming-inspect/defect-delete/{record_id}", removeDefect, PATH(UInt64, record_id), execRemoveDefect(record_id));

	
private:
	// 3.3 ��ҳ��ѯ���������
	SinglePageJsonVO::Wrapper execQuerySingle(const SingleQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ҳ��ѯȱ������
	DefectPageJsonVO::Wrapper execQueryDefect(const DefectQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ����ȱ������
	Uint64JsonVO::Wrapper execAddDefect(const DefectDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�ȱ������
	Uint64JsonVO::Wrapper execModifyDefect(const DefectDTO::Wrapper& dto);
	// 3.3 ��ʾɾ��ȱ������
	Uint64JsonVO::Wrapper execRemoveDefect(const UInt64& record_id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SINGLE_DEFECT_CONTROLLER_
