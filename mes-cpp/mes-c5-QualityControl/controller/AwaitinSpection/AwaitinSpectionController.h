#pragma once
#ifndef _OASL_CONTROLLER_
#define _OASL_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/AwaitinSpection/AwaitinSpectionVO.h"
#include "../../domain/query/AwaitinSpection/AwaitinSpectionQuery.h"
#include "Macros.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class AwaitinSpectionController : public oatpp::web::server::api::ApiController
{
    //����������������
    API_ACCESS_DECLARE(AwaitinSpectionController);
public://����ӿ�
    // 3.1 ���������ӿ�����
    // �����ȡ���������б�ӿ�����
    ENDPOINT_INFO(getPendingInspectionTasks) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Pending_inspection.get.summary"));
        // ����Ĭ����Ȩ����
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ��������践�ص��� OaslPageJsonVO
        API_DEF_ADD_RSP_JSON_WRAPPER(AwaitinSpectionPageJsonVO);
        // �����ҳ����
        API_DEF_ADD_PAGE_PARAMS();
        // ��ѡ������������ѯ�����������絥�ݱ��롢�������ơ�������͵�
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("Pending_inspection.fields.code"), "", false); // ���ݱ���
        API_DEF_ADD_QUERY_PARAMS(String, "material", ZH_WORDS_GETTER("Pending_inspection.fields.material"), "", false); // ��������
        API_DEF_ADD_QUERY_PARAMS(String, "detectionType", ZH_WORDS_GETTER("Pending_inspection.fields.detectionType"), "", false); // �������
    }
    // �����ȡ���������б�ӿڴ���
    ENDPOINT(API_M_GET, "/qc/await-inspection/query-by-page", getPendingInspectionTasks, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(userQuery, AwaitinSpectionQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryAwaitInspection(userQuery, authObject->getPayload()));
    }

private:
    AwaitinSpectionPageJsonVO::Wrapper execQueryAwaitInspection(const AwaitinSpectionQuery::Wrapper& query, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _OASL_CONTROLLER_ 