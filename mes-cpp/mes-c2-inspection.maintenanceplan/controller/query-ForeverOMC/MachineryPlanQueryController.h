#ifndef _MACHINERY_LIST_CONTROLLER_
#define _MACHINERY_LIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/query-ForeverOMC/MachineryListQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryListDTO.h"
#include "domain/vo/query-ForeverOMC/MachineryListVO.h"

#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"
#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"

#include "domain/query/query-ForeverOMC/MachinerySubjectQuery.h"
#include "domain/dto/query-ForeverOMC/MachinerySubjectDTO.h"
#include "domain/vo/query-ForeverOMC/MachinerySubjectVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
* 设备清单控制器
*/
class MachineryPlanQueryController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(MachineryPlanQueryController);

public:
	// 定义查询设备清单列表接口描述
	ENDPOINT_INFO(queryMachineryList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-list.query.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "plan_id", ZH_WORDS_GETTER("machinery-list.field.plan-id"), 207, true);
	}
	// 定义查询设备清单列表接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/machinery-list", queryMachineryList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析领域模型
		API_HANDLER_QUERY_PARAM(querymachinerylist, MachineryListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMachineryList(querymachinerylist));
	}

	// 定义点检/保养设备计划列表接口描述
	ENDPOINT_INFO(queryMachineryPlan) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryPlanPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "plan_code", ZH_WORDS_GETTER("machinery-plan.field.plan-code"), "PLAN2022048", false);
		API_DEF_ADD_QUERY_PARAMS(String, "plan_name", ZH_WORDS_GETTER("machinery-plan.field.plan-name"), "NAME", false);
		API_DEF_ADD_QUERY_PARAMS(String, "plan_type", ZH_WORDS_GETTER("machinery-plan.field.plan-type"), "CHECK / MAINTEN", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("machinery-plan.field.status"), "PREPARE / FINISHED", false);
	}

	// 定义查询设备清单列表接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/machinery-plan", queryMachineryPlan, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析领域模型
		API_HANDLER_QUERY_PARAM(querymachineryplan, MachineryPlanQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMachineryPlan(querymachineryplan));
	}

	// 定义点检/保养设备计划列表接口描述
	ENDPOINT_INFO(queryMachineryPlanDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query-details.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MachineryPlanDetailsJsonVO);
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), 207, true);
	}
	// 定义查询设备清单列表接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/machinery-plan-details", queryMachineryPlanDetails, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析领域模型
		API_HANDLER_QUERY_PARAM(querymachineryplandetails, MachineryPlanDetailsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMachineryPlanDetails(querymachineryplandetails));
	}

	// 定义查询点检/保养项目列表接口描述
	ENDPOINT_INFO(queryMachinerySubject) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-subject.query.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MachinerySubjectPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "plan_id", ZH_WORDS_GETTER("machinery-subject.field.plan-id"), 207, true);
	}
	// 定义查询点检/保养项目列表接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/machinery-subject", queryMachinerySubject, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析领域模型
		API_HANDLER_QUERY_PARAM(querymachinerysubject, MachinerySubjectQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMachinerySubject(querymachinerysubject));
	}

private:
	// 分页查询设备清单列表数据
	MachineryListPageJsonVO::Wrapper execQueryMachineryList(const MachineryListQuery::Wrapper& query);

	// 分页查询点检/保养计划列表数据 
	MachineryPlanPageJsonVO::Wrapper execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query);

	// 查询点检/保养计划详细信息
	MachineryPlanDetailsJsonVO::Wrapper execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query);

	// 分页查询点检/保养项目列表数据
	MachinerySubjectPageJsonVO::Wrapper execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MACHINERY_LIST_CONTROLLER_
