#pragma once
#ifndef _HUMANRESOURCELISTCONTROLLER_
#define _HUMANRESOURCELISTCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/humanresource/HumanResourceListQuery.h"
#include "domain/dto/humanresource/HumanResourceListDTO.h"
#include "domain/vo/humanresource/HumanResourceListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ������Դ������
 */
class HumanResourceListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(HumanResourceListController);
	// 3 ����ӿ�
public:

	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryHumanResource) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(HumanResourceListPageVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workstationId", ZH_WORDS_GETTER("post.fields.workstationid"), 1, false);

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/huamnresource/query-humanresource-list", queryHumanResource, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, HumanResourceListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryHumanResourceList(query));
	}


	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addHumanResource) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ws/humanresource/add-hunmanresource-list", addHumanResource, BODY_DTO(HumanResourceListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddHumanResourceList(dto));
	}
	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("modify.summary"), modifyHumanResource, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ws/humanresource/modify-hunmanresource", modifyHumanResource, BODY_DTO(HumanResourceListDTO::Wrapper, dto), execModifyHumanResource(dto));

	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeHumanResource) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("remove.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "recordId", ZH_WORDS_GETTER("post.fields.recordid"), 1, true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/humanresource/remove-hunmanresource/{recordId}", removeHumanResource, PATH(UInt64, recordId), execRemoveHumanResource(recordId));

private:
	// ��ҳ��ѯ����
	HumanResourceListPageVO::Wrapper execQueryHumanResourceList(const HumanResourceListQuery::Wrapper& query);
	// ��������
	Uint64JsonVO::Wrapper execAddHumanResourceList(const HumanResourceListDTO::Wrapper& dto);
	// �޸�����
	Uint64JsonVO::Wrapper execModifyHumanResource(const HumanResourceListDTO::Wrapper& dto);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveHumanResource(const UInt64& recordId);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 