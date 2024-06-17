#pragma once
#ifndef _TEMPLATEDETECTITEM_CONTROLLER_
#define _TEMPLATEDETECTITEM_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/DetectionTemplate/TemplateDetectItemJsonVO.h"
#include "../../../domain/dto/DetectionTemplate/TemplateDetectItemDTO.h"
#include "../../../domain/query/DetectionTemplate/TemplateDetectItemQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DetectionItemsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DetectionItemsController); // �������������
public:
	ENDPOINT_INFO(queryTemplateDetectItem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templatedetectitem.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TemplateDetectItemPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("templatedetectitem.field.template_id"), 1, true);
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/qc/templatedetect-item/query-by-page", queryTemplateDetectItem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, TemplateDetectItemQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryTemplateDetectItem(query));
	}

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("templatedetectitem.put.summary"), modifyTemplateDetectItem, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/templatedetect-item/modify", modifyTemplateDetectItem, BODY_DTO(TemplateDetectItemDTO::Wrapper, dto), execModifyTemplateDetectItem(dto));

	// ���������ӿ�����
	ENDPOINT_INFO(addTemplateDetectItem) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templatedetectitem.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/qc/templatedetect-item/add", addTemplateDetectItem, BODY_DTO(TemplateDetectItemDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddTemplateDetectItem(dto));
	}

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeTemplateDetectItem) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("templatedetectitem.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		//API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("templatedetectitem.field.record_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/templatedetect-item/remove", removeTemplateDetectItem, BODY_DTO(oatpp::List<UInt64>, record_ids), execRemoveTemplateDetectItem(record_ids));

private: // ����ӿڵ�ִ�к���
	TemplateDetectItemPageJsonVO::Wrapper execQueryTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query); // ��ҳ��ѯִ�к���
	Uint64JsonVO::Wrapper execModifyTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execAddTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveTemplateDetectItem(const oatpp::List<UInt64>& record_ids);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_TEMPLATEDETECTITEM_CONTROLLER_
