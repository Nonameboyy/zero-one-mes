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
 * 部门管理 控制器
 */
class PlanSubjectController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PlanSubjectController);
	// 3 定义接口
public:
	//这里可以定义很多个的接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryPlanSubjectTablePage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryTable"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectTablePageJsonVO);//ABF 响应格式是我们定义的那个VO
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();//没有分页，不加这个

		// 定义其他查询参数描述，，，ABF 注意，这里要照着query对象来写
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), "", false);

	}
	// 3.2 定义查询接口处理                                  查询参数                          开启授权才能用
	//
	ENDPOINT(API_M_GET, "/equipment-ledger/inspe-matain/query-panSubject-table", queryPlanSubjectTablePage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
	// 暂时不开授权
	//ENDPOINT(API_M_GET, "/planSubject/query-panSubject-table", queryPlanSubjectTablePage, QUERIES(QueryParams, queryParams))
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, PlanSubjectQuery, queryParams);//解析成Deptquery
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execPlanSubjectTablePage(userQuery, authObject->getPayload()));

		return createDtoResponse(Status::CODE_200, execPlanSubjectTablePage(userQuery, authObject->getPayload()));

		//改成DeptTable，并减少一个参数
		//return createDtoResponse(Status::CODE_200, execPlanSubjectTablePage(query));
	}

	//-------------------------------------------------------------
	ENDPOINT_INFO(queryPlanSubjectDetailPage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("planSubject.query.summaryDetailPage"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PlanSubjectDetailPageJsonVO);//ABF 响应格式是我们定义的那个VO
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();//没有分页，不加这个

		// 定义其他查询参数描述，，，ABF 注意，这里要照着query对象来写
		API_DEF_ADD_QUERY_PARAMS(String, "subCode", ZH_WORDS_GETTER("planSubject.fields.subCode"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subName", ZH_WORDS_GETTER("planSubject.fields.subName"), "7", false);
		API_DEF_ADD_QUERY_PARAMS(String, "subType", ZH_WORDS_GETTER("planSubject.fields.subType"), "7", false);

	}
	// 3.2 定义查询接口处理（分页）                                  查询参数                          开启授权才能用
	ENDPOINT(API_M_GET, "/equipment-ledger/planSubject/query-panSubject-DetailPage", queryPlanSubjectDetailPage, QUERIES(QueryParams, queryParams)
		//, API_HANDLER_AUTH_PARAME
	) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, PlanSubjectQuery, queryParams);//解析成Deptquery
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPlanSubjectDetailPage(query));//改成DeptTable，并减少一个参数
	}
	

private:
	// 3.3 演示分页查询数据
	PlanSubjectTablePageJsonVO::Wrapper execPlanSubjectTablePage(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);//最后那个参数先不要
	//接下来要写一个cpp文件，给execDeptTable
	//PlanSubjectDetailPageJsonVO::Wrapper execQuerySample(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload);

	//暂时为空白对照，具体的操作函数没有定义
	PlanSubjectDetailPageJsonVO::Wrapper execPlanSubjectDetailPage(const PlanSubjectQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
