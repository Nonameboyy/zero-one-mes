#pragma once
#ifndef _DETECTIONTEMPLATE_CONTROLLER_
#define _DETECTIONTEMPLATE_CONTROLLER_

#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/DetectionTemplate/DetectionTemplateDTO.h"
#include "../../domain/query/DetectionTemplate/DetectionTemplateQuery.h"
#include "../../domain/vo/DetectionTemplate/DetectionTemplateVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �޸ļ��ģ�� ����
 */
class DetectionTemplateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DetectionTemplateController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ����� 
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("DetectionTemplate.modify.summary"), modifyDetectionTemplate, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/detection-template/modify", modifyDetectionTemplate, BODY_DTO(DetectionTemplateDTO::Wrapper, dto), execModifyDetectionTemplate(dto));

	//����ɾ�����ģ��ӿ�����
	ENDPOINT_INFO(removeDetectionTemplate) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("detection_template.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("detection_template.fields.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/detection-template/delete/{template_id}", removeDetectionTemplate, PATH(UInt64, template_id), execRemoveDetectionTemplate(template_id));

	ENDPOINT_INFO(queryDetectionTemplateList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.get.title"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionTemplatePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("DetectionTemplate.field.template_id"), 18, false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_code", ZH_WORDS_GETTER("DetectionTemplate.field.template_code"), "QCT2022040", false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_name", ZH_WORDS_GETTER("DetectionTemplate.field.template_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enable_flag", ZH_WORDS_GETTER("DetectionTemplate.field.enable_flag"), "Y", false);
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("DetectionTemplate.field.remark"), "", false);
	}

	ENDPOINT(API_M_GET, "/qc/detection-template/query-by-page", queryDetectionTemplateList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(templateListQuery, DetectionTemplateQuery, queryParams);
		// ����ִ�к���
		API_HANDLER_RESP_VO(execQueryDetectionTemplateList(templateListQuery, authObject->getPayload()));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addDetectionTemplate) {
		// ����ӿڱ��� ��Ӽ��ģ��
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/qc/detection-template/add", addDetectionTemplate, BODY_DTO(DetectionTemplateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDetectionTemplate(dto));
	}

	//  �����ȡ����ģ������ӿ�����
	ENDPOINT_INFO(queryDetecTempDetails) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.querydetectempdetails.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionTemplatePageJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "template_code", ZH_WORDS_GETTER("DetectionTemplate.field.template_code"), "", true);
	}
	//  �����ȡ����ģ������ӿڴ���
	ENDPOINT(API_M_GET, "/qc/detection-template/query-by-details", queryDetecTempDetails, QUERY(String, template_code), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDetecTempDetails(template_code, authObject->getPayload()));
	}

private:
	Uint64JsonVO::Wrapper execModifyDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto);

	//ɾ�����ģ��
	Uint64JsonVO::Wrapper execRemoveDetectionTemplate(const UInt64& template_id);

	DetectionTemplatePageJsonVO::Wrapper execQueryDetectionTemplateList(const DetectionTemplateQuery::Wrapper& query, const PayloadDTO& payload);
	// ��������
	Uint64JsonVO::Wrapper execAddDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto);
	//  ��ȡ����ģ������
	DetectionTemplatePageJsonVO::Wrapper execQueryDetecTempDetails(const String& template_code, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DETECTIONTEMPLATE_CONTROLLER_