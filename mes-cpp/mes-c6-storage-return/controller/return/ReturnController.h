#pragma once

#ifndef _RETURNCONTROLLER_H_
#define _RETURNCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/return/ReturnQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/return/ReturnVO.h"
#include "ApiHelper.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReturnController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(ReturnController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAllReturn) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReturnPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// �˻�������
		API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", false);
		// �˻������
		API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123456", false);
		// �ɹ������
		API_DEF_ADD_QUERY_PARAMS(String, "purchaseCode", ZH_WORDS_GETTER("return.fields.pucode"), "null", false);
		// ��Ӧ������
		API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("return.fields.vename"), "01star", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/return/query-all", queryAllReturn, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ReturnQuery, queryParams);
		// ����ִ�к�����Ӧ���

		API_HANDLER_RESP_VO(executeQueryAll(query));

	}

	// �����ѯ����������ϸ��Ϣ�ӿ�����
	ENDPOINT_INFO(queryReturnDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.query-detail.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ReturnDetailJsonVO);
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ����������ѯ��������
		// �˻������
		API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123456", true);
	}
	// �����ѯ������ϸ��Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/return/query-detail", queryReturnDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ReturnDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryDetail(query));
	}

	// ��������µ�����Ϣ�ӿ�����
	ENDPOINT_INFO(addReturnDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("return.add-detail.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ����������ѯ��������
		// �˻������
		API_DEF_ADD_QUERY_PARAMS(String, "returnCode", ZH_WORDS_GETTER("return.fields.rtcode"), "RTV123", true);
		// �˻�������
		API_DEF_ADD_QUERY_PARAMS(String, "returnName", ZH_WORDS_GETTER("return.fields.rtname"), "01star", true);
		// �ɹ������
		API_DEF_ADD_QUERY_PARAMS(String, "purchaseCode", ZH_WORDS_GETTER("return.fields.pucode"), "null", false);
		// ��Ӧ������
		API_DEF_ADD_QUERY_PARAMS(String, "vendorName", ZH_WORDS_GETTER("return.fields.vename"), "01star", true);
		// ���κ�
		API_DEF_ADD_QUERY_PARAMS(String, "batchCode", ZH_WORDS_GETTER("return.fields.batchcode"), "null", false);
		// �˻�����
		API_DEF_ADD_QUERY_PARAMS(String, "returndate", ZH_WORDS_GETTER("return.fields.rtdate"), "2024-5-21", true);
		// ����״̬
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("return.fields.status"), "PREPARE", true);
		// ��ע
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("return.fields.remark"), " ", false);
	}
	// ��������������ϸ��Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_POST, "/return/add-detail", addReturnDetail, BODY_DTO(ReturnAdd::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDetail(dto));
	}

private:

	// ��ѯ���е�����Ϣ
	ReturnPageJsonVO::Wrapper executeQueryAll(const ReturnQuery::Wrapper& returnQuery);
	// ��ѯ��һ������ϸ��Ϣ
	ReturnDetailJsonVO::Wrapper executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery);
	// ����µ�����ϸ��Ϣ
	Uint64JsonVO::Wrapper execAddDetail(const ReturnAdd::Wrapper& returnAdd);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RETURNCONTROLLER_H_