#pragma once
#ifndef _ADDPRODWORKORDER_CONTROLLER_
#define _ADDPRODWORKORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/AddProdWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/AddProdWorkorderVO.h"

#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/GetProdWorkorderListVO.h"
#include "../mes-c4-prodmgmt/domain/query/ProdWorkorder/GetProdWorkorderListQuery.h"
#include "../mes-c4-prodmgmt/domain/query/ProdWorkorder/ProdWorkorderBomListQuery.h"
#include "../mes-c4-prodmgmt/domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/GetProdWorkorderListDTO.h"

#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ProdWorkorderInfoVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ProdWorkorderInfoDTO.h"


#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ProdWorkorderBomListVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ProdWorkorderBomListDTO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������������
 */
class ProdWorkorderController : public oatpp::web::server::api::ApiController {// 1 �̳п�����
	// 2 ����������������
	API_ACCESS_DECLARE(ProdWorkorderController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addProdWorkorder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addprodworkorder.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/prodmgmt/prodworkorder/add", addProdWorkorder, BODY_DTO(AddProdWorkorderDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProdWorkorder(dto));
	}
	



	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryGetProdWorkorderList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("getprodworkorderlist.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(GetProdWorkorderListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workorder_id", ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_id"), 9999, false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_code", ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_code"), "8888", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_name", ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_name"), "7777", false);
		API_DEF_ADD_QUERY_PARAMS(String, "source_code", ZH_WORDS_GETTER("addprodworkorder.workorder.source_code"), "6666", false);
		API_DEF_ADD_QUERY_PARAMS(String, "product_code", ZH_WORDS_GETTER("addprodworkorder.workorder.product_code"), "5555", false);
		API_DEF_ADD_QUERY_PARAMS(String, "product_name", ZH_WORDS_GETTER("addprodworkorder.workorder.product_name"), "4444", false);
		API_DEF_ADD_QUERY_PARAMS(String, "client_code", ZH_WORDS_GETTER("addprodworkorder.workorder.client_code"), "3333", false);
		API_DEF_ADD_QUERY_PARAMS(String, "client_name", ZH_WORDS_GETTER("addprodworkorder.workorder.client_name"), "2222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_type", ZH_WORDS_GETTER("addprodworkorder.workorder.workorder_type"), "1111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "request_date", ZH_WORDS_GETTER("addprodworkorder.workorder.request_date"), "0000", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/prodmgmt/prodworkorder/query", queryGetProdWorkorderList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, GetProdWorkorderListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGetProdWorkorderList(userQuery, authObject->getPayload()));
	}


	// 3.1 �����ȡ������������ӿ�����
	ENDPOINT_INFO(prodWorkorderInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prodworkorderinfo.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdWorkorderInfoJsonVO);
	}
	// 3.2 �����ȡ������������ӿڴ���
	ENDPOINT(API_M_GET, "/prodmgmt/prodworkorder/query/{workorder_id}", prodWorkorderInfo, PATH(UInt64, workorder_id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetProdWorkorderInfo(workorder_id));
	}


	// 3.1 �����ȡ��������BOM�б�ӿ�����
	ENDPOINT_INFO(queryProdWorkorderBomList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bom.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdWorkorderBomListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("bom.field.line_id"), 9999, false);

	}
	// 3.2 �����ȡ��������BOM�б�ӿڴ���
	ENDPOINT(API_M_GET, "/prodmgmt/prodworkorder/bom_query", queryProdWorkorderBomList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProdWorkorderBomListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetProdWorkorderBomList(userQuery, authObject->getPayload()));
	}


	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddProdWorkorder(const AddProdWorkorderDTO::Wrapper& dto);
	// 3.3 ��ʾ��ҳ��ѯ����
	GetProdWorkorderListPageJsonVO::Wrapper execQueryGetProdWorkorderList(const GetProdWorkorderListQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��ȡ�б���������
	ProdWorkorderInfoJsonVO::Wrapper execGetProdWorkorderInfo(const UInt64& workorder_id);
	// 3.3 ��ʾ��ȡBOM�б�����
	ProdWorkorderBomListPageJsonVO::Wrapper execGetProdWorkorderBomList(const ProdWorkorderBomListQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDPRODWORKORDER_CONTROLLER_