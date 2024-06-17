#pragma once
#ifndef _REJECT_CONTROLLER_
#define _REJECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/rejection/RejectVo.h"
#include "../../domain/query/rejection/RejectQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
	class RejectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RejectController);
	// 3 ����ӿ�
public:
	// 1.3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRejectTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RejectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("reject.fields.rt_code"), "code", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workorder_id", ZH_WORDS_GETTER("reject.fields.workorder_id"), "workorder_id", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("reject.fields.warehouse_name"), "warehouse_name", false);
	}
	// 1.3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/rejection/query-documents-page", queryRejectTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RejectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryReject(query, authObject->getPayload()));

	}


	//2. 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRejectDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.detail"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RejectDetailJsonVO);

		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("reject.fields.rt_code"), "RMO123456", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "mo", ZH_WORDS_GETTER("reject.fields.mo"), "N", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sname", ZH_WORDS_GETTER("reject.fields.sname"), "N", false);
	}
	// 2.3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/rejection/query-documents-details", queryRejectDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, RejectDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRejectDetail(query));
	}



	// 3.3.1 ���������ӿ�����
	ENDPOINT_INFO(addOrder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reject.fields.add"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/rejection/add-documents", addOrder, BODY_DTO(RejectDetailDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddReject(dto));
	}

	// 4.3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("reject.fields.modify"), modifyReject, Uint64JsonVO::Wrapper);
	// 4.3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/mod-documents", modifyReject, BODY_DTO(RejectDetailDTO::Wrapper, dto), execModifyReject(dto));

	
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	RejectPageJsonVO::Wrapper execQueryReject(const RejectQuery::Wrapper& query, const PayloadDTO& payload);
	//detailQuery
	RejectDetailJsonVO::Wrapper execQueryRejectDetail(const RejectDetailQuery::Wrapper& query);
	//// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddReject(const RejectDetailDTO::Wrapper& dto);
	//// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyReject(const RejectDetailDTO::Wrapper& dto);
	//// 3.3 ��ʾɾ������
	//Uint64JsonVO::Wrapper execRemoveSample(const UInt64& id);
	//// 3.3 ��������ʽ�������1
	//SampleJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	//// 3.3 ��������ʽ�������2
	//SamplePageJsonVO::Wrapper execQueryAll(const SampleQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif 
