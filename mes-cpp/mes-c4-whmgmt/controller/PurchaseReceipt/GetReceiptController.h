#pragma once

#ifndef _GETRECEIPT_CONTROLLER_H
#define _GETRECEIPT_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/Receipt/ReceiptVO.h"
#include "../../domain/query/Receipt/ReceiptQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetReceiptController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(GetReceiptController);

public: // ����ӿ�
	// ��ȡ�����б�ӿ�����
	ENDPOINT_INFO(queryReceiptPageTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("receipt.describe.query1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReceiptPageTableJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recptCode", ZH_WORDS_GETTER("receipt.query.fields.recptCode"), "R20231019001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recptName", ZH_WORDS_GETTER("receipt.query.fields.recptName"), "Procurement test", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("receipt.query.fields.vendorName"), "Jiangsu test", false);
		API_DEF_ADD_QUERY_PARAMS(String, "poCode", ZH_WORDS_GETTER("receipt.query.fields.poCode"), "343434343", false);
		API_DEF_ADD_QUERY_PARAMS(String, "recptDate", ZH_WORDS_GETTER("receipt.query.fields.recptDate"), "2023-06-15", false);
	}
	// ��ȡ�����б�ӿ�
	ENDPOINT(API_M_GET, "/whmgmt/purchase/querylist", queryReceiptPageTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ReceiptTableQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReceiptPageTable(query));
	}

	// ��ȡ��������ӿ�����
	ENDPOINT_INFO(queryReceiptDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("receipt.describe.query2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReceiptDetailJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "recptCode", ZH_WORDS_GETTER("receipt.query.fields.recptCode"), "R20231019001", false);
	}
	// ��ȡ��������ӿ�
	ENDPOINT(API_M_GET, "/whmgmt/purchase/querydetail", queryReceiptDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ReceiptDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReceiptDetail(query));
	}

private: // ����ӿ�ִ�к���
	ReceiptPageTableJsonVO::Wrapper execQueryReceiptPageTable(const ReceiptTableQuery::Wrapper& query);
	ReceiptDetailJsonVO::Wrapper execQueryReceiptDetail(const ReceiptDetailQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _GETRECEIPT_CONTROLLER_H