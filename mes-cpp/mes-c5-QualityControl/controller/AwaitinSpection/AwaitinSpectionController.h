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
    //定义控制器访问入口
    API_ACCESS_DECLARE(AwaitinSpectionController);
public://定义接口
    // 3.1 定义新增接口描述
    // 定义获取待检任务列表接口描述
    ENDPOINT_INFO(getPendingInspectionTasks) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Pending_inspection.get.summary"));
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        // 定义响应参数格式，这里假设返回的是 OaslPageJsonVO
        API_DEF_ADD_RSP_JSON_WRAPPER(AwaitinSpectionPageJsonVO);
        // 定义分页参数
        API_DEF_ADD_PAGE_PARAMS();
        // 可选：定义其他查询参数描述，如单据编码、物资名称、检测类型等
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("Pending_inspection.fields.code"), "", false); // 单据编码
        API_DEF_ADD_QUERY_PARAMS(String, "material", ZH_WORDS_GETTER("Pending_inspection.fields.material"), "", false); // 物资名称
        API_DEF_ADD_QUERY_PARAMS(String, "detectionType", ZH_WORDS_GETTER("Pending_inspection.fields.detectionType"), "", false); // 检测类型
    }
    // 定义获取待检任务列表接口处理
    ENDPOINT(API_M_GET, "/qc/await-inspection/query-by-page", getPendingInspectionTasks, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(userQuery, AwaitinSpectionQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryAwaitInspection(userQuery, authObject->getPayload()));
    }

private:
    AwaitinSpectionPageJsonVO::Wrapper execQueryAwaitInspection(const AwaitinSpectionQuery::Wrapper& query, const PayloadDTO& payload);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _OASL_CONTROLLER_ 