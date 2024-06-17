#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTCONTROLLER_H_
#define _PLANSUBJECTCONTROLLER_H_

//#include "../../domin/vo/dept/DeptVO.h"
#include "../../domain/vo/planSubject/PlanSubjectVO.h"
#include "../../domain/query/planSubject/PlanSubjectQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * ���Ź��� ������
 */
class PlanSubjectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PlanSubjectController);
	// 3 ����ӿ�
public:
	//������Զ���ܶ���Ľӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPlanSubjectTablePage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryTable"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectTablePageJsonVO);//ABF ��Ӧ��ʽ�����Ƕ�����Ǹ�VO
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();//û�з�ҳ���������

		// ����������ѯ��������������ABF ע�⣬����Ҫ����query������д
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), "", false);

	}
	// 3.2 �����ѯ�ӿڴ���                                  ��ѯ����                          ������Ȩ������
	//
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/query-panSubject-table", queryPlanSubjectTablePage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
	// ��ʱ������Ȩ
	//ENDPOINT(API_M_GET, "/planSubject/query-panSubject-table", queryPlanSubjectTablePage, QUERIES(QueryParams, queryParams))
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, PlanSubjectQuery, queryParams);//������Deptquery
		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execPlanSubjectTablePage(userQuery, authObject->getPayload()));

		return createDtoResponse(Status::CODE_200, execPlanSubjectTablePage(userQuery, authObject->getPayload()));

		//�ĳ�DeptTable��������һ������
		//return createDtoResponse(Status::CODE_200, execPlanSubjectTablePage(query));
	}

	//-------------------------------------------------------------
	ENDPOINT_INFO(queryPlanSubjectDetailPage) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryDetailPage"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectDetailPageJsonVO);//ABF ��Ӧ��ʽ�����Ƕ�����Ǹ�VO
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();//û�з�ҳ���������

		// ����������ѯ��������������ABF ע�⣬����Ҫ����query������д
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), "7", false);

	}
	// 3.2 �����ѯ�ӿڴ�����ҳ��                                  ��ѯ����                          ������Ȩ������
	ENDPOINT(API_M_GET, "/equipment-ledger/planSubject/query-panSubject-DetailPage", queryPlanSubjectDetailPage, QUERIES(QueryParams, queryParams)
		//, API_HANDLER_AUTH_PARAME
	) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, PlanSubjectQuery, queryParams);//������Deptquery
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPlanSubjectDetailPage(query));//�ĳ�DeptTable��������һ������
	}
	

private:
	// 3.3 ��ʾ��ҳ��ѯ����
	PlanSubjectTablePageJsonVO::Wrapper execPlanSubjectTablePage(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);//����Ǹ������Ȳ�Ҫ
	//������Ҫдһ��cpp�ļ�����execDeptTable
	//PlanSubjectDetailPageJsonVO::Wrapper execQuerySample(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);

	//��ʱΪ�հ׶��գ�����Ĳ�������û�ж���
	PlanSubjectDetailPageJsonVO::Wrapper execPlanSubjectDetailPage(const PlanSubjectQuery::Wrapper& query);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
