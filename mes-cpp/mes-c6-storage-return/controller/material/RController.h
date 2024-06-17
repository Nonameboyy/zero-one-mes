#pragma once
#pragma once

#ifndef _GETRETURNLISTCONTROLLER_H_
#define _GETRETURNLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/material/GetReturnListQuery.h"
#include "domain/dto/material/GetReturnListDTO.h"
#include "domain/vo/material/GetReturnListVO.h"

#include "domain/dto/material/AddReturnDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��Ӧ���˻����б��������
 */
class RController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(returnlist) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("material.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetReturnListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "rtcode", ZH_WORDS_GETTER("material.rtcode"), "RTV20221115001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rtname", ZH_WORDS_GETTER("material.rtname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pocode", ZH_WORDS_GETTER("material.pocode"), " ", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorname", ZH_WORDS_GETTER("material.vendorname"), " ", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/return/get-returnlist", returnlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, GetReturnListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryList(Query));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addreturnline) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("material.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/return/add-returnline", addreturnline, BODY_DTO(AddReturnDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddReturnLine(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("material.alter.summary"), modifyReturnline, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/return/alter-returnline", modifyReturnline, BODY_DTO(AddReturnDTO::Wrapper, dto), execModifyReturnline(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeReturnline) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("material.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "lineid", ZH_WORDS_GETTER("material.lineid"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/delete1/{lineid}", removeReturnline, PATH(UInt64, lineid), execRemoveReturnline(lineid));
	
private:
	GetReturnListPageJsonVO::Wrapper execQueryList(const GetReturnListQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execAddReturnLine(const AddReturnDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyReturnline(const AddReturnDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveReturnline(const UInt64& lineid);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GETRETURNLISTCONTROLLER_H_