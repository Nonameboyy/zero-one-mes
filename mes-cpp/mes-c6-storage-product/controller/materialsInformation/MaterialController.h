#pragma once
#ifndef _MATERIAL_CONTROLLER_
#define _MATERIAL_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/materialsInformation/MaterialQuery.h"
#include "domain/dto/materialsInformation/MaterialDTO.h"
#include "domain/vo/materialsInformation/MaterialVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ������Ϣ�ӿڵ�ʹ��
 */
class MaterialController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(MaterialController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryMaterial) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Material.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(MaterialPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "issue_id", ZH_WORDS_GETTER("Material.field.issue_id"), 1, false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/incoming/search", queryMaterial, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, MaterialQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryMaterial(userQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addMaterial) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Material.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/incoming/add", addMaterial, BODY_DTO(MaterialDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddMaterial(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Material.put.summary"), modifyMaterial, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming/change", modifyMaterial, BODY_DTO(MaterialDTO::Wrapper, dto), execModifyMaterial(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeMaterial) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Material.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("Material.field.id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming/delete/{line_id}", removeMaterial, PATH(UInt64, line_id), execRemoveMaterial(line_id));

private:
	// 3.3 ��ҳ��ѯ����
	MaterialPageJsonVO::Wrapper execQueryMaterial(const MaterialQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddMaterial(const MaterialDTO::Wrapper& dto);
	// 3.3 �޸�����
	Uint64JsonVO::Wrapper execModifyMaterial(const MaterialDTO::Wrapper& dto);
	// 3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoveMaterial(const UInt64& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MATERIAL_CONTROLLER_