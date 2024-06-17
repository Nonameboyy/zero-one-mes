#pragma once
#ifndef _DETECTIONITEMSETTINGS_CONTROLLER_
#define _DETECTIONITEMSETTINGS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/DetectionItemSettings/DetectionItemSettingsQuery.h"
#include "domain/dto/DetectionItemSettings/DetectionItemSettingsDTO.h"
#include "domain/vo/DetectionItemSettings/DetectionItemSettingsJsonVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class DetectionItemSettingsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DetectionItemSettingsController);
public:
	//��ҳ��ѯ�ӿ�
	ENDPOINT_INFO(QueryqcSettings) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionItemSettingsPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.type"), "", false);
	}
	ENDPOINT(API_M_GET, "/qc/detection-item-settings/query-by-page", QueryqcSettings, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(qcsettingsQuery, DetectionItemSettingsQuery, queryParams);
		//API_HANDLER_RESP_VO(execQueryqc(qcsettingsQuery,authObject->getPayload()));
		API_HANDLER_RESP_VO(execQueryqc(qcsettingsQuery));
	}

	//��Ӽ����ӿ�
	ENDPOINT_INFO(addDetectionItemSettings) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/qc/detection-item-settings/adds", addDetectionItemSettings, BODY_DTO(DetectionItemSettingsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddqc(dto));
	}

	//�޸ļ����ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.modify.summary"), modifyDetectionItemSettings, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/detection-item-settings/modify", modifyDetectionItemSettings, BODY_DTO(DetectionItemSettingsDTO::Wrapper, dto), execModifyqc(dto));

	ENDPOINT_INFO(removeTheDetection) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("detectionitemsettings.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("detectionitemsettings.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/detection-item-settings/remove", removeTheDetection, BODY_DTO(oatpp::List<UInt64>, id), execRemoveTheDetection(id));

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportDetectionItemSettings) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("detectionitemsettings.export.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.controller.query.type"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/qc/detection-item-settings/export", exportDetectionItemSettings, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DetectionItemSettingsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execExportDetectionItemSettings(userQuery, authObject->getPayload()));
	}
private:
	//DetectionItemSettingsPageJsonVO::Wrapper execQueryqc(const DetectionItemSettingsQuery::Wrapper& query, const PayloadDTO& payload);
	DetectionItemSettingsPageJsonVO::Wrapper execQueryqc(const DetectionItemSettingsQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execAddqc(const DetectionItemSettingsDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyqc(const DetectionItemSettingsDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveTheDetection(const oatpp::List<UInt64>& id);
	// ִ���ļ����ش���
	StringJsonVO::Wrapper execExportDetectionItemSettings(const DetectionItemSettingsQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DETECTIONITEMSETTINGS_CONTROLLER_