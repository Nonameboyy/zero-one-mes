#pragma once
#ifndef _storage_CONTROLLER_
#define _storage_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ServerInfo.h"
#include "domain/dto/storage/storageDTO.h"

#include "domain/query/storage/storageQuery.h"
#include "domain/vo/storage/storageVO.h"
//=======
#include "domain/query/storage/storageQuery.h"
#include "domain/vo/storage/storageVO.h"

#include "ExcelComponent.h"

//#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class storageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	//�������������
	API_ACCESS_DECLARE(storageController);
public:

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storage.put.summary"), modifystorage, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/storage/mod-storage", modifystorage, BODY_DTO(storageDTO::Wrapper, dto), execModifystorage(dto));

	// ����ɾ�����ݽӿ����� ֧������ɾ��
	ENDPOINT_INFO(removestorage)
	{
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("storage.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("storage.field.id"), 1, true);
	}

	//����ɾ�����ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/storage/del-storage-by-recpt_id/{recpt_id}", removestorage, PATH(UInt64, id), execRemovestorage(id));

	


	// �����ѯ�ӿ�����
	ENDPOINT_INFO(querystorage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storage.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(storageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("storage.field.id"), "RT20221115001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("storage.field.order"), "MO10023110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse", ZH_WORDS_GETTER("storage.field.warehouse"), "N", false);
	}

	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/storage/query-storage", querystorage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, storageQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerystorage(userQuery, authObject->getPayload()));

	}






private:
	// ɾ����Ʒ��ⵥ�ݵ����б�֧������ɾ����
	Uint64JsonVO::Wrapper execRemovestorage(const UInt64& id);

	//�޸Ĳ�Ʒ��ⵥ������
	Uint64JsonVO::Wrapper execModifystorage(const storageDTO::Wrapper& dto);

	//��ѯ���ݵ�������
	storagePageJsonVO::Wrapper execQuerystorage(const storageQuery::Wrapper& query, const PayloadDTO& payload);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End
#endif 