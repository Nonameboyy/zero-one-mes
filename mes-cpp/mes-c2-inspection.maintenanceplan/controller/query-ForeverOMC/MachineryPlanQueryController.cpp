#include "stdafx.h"
#include "MachineryPlanQueryController.h"
#include "../../service/query-ForeverOMC/MachineryPlanService.h"
#include "../../service/query-ForeverOMC/MachineryListService.h"
#include "../../service/query-ForeverOMC/MachinerySubjectService.h"
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"

MachineryListPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryList(const MachineryListQuery::Wrapper& query)
{
	// 定义一个Service
	MachineryListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MachineryListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachineryPlanPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query)
{
	
	////以上是原本内容，暂时注释，以下是abf的测试
	//// 定义一个Service
	//int a = 0;
	//Dv_check_planService service;
	//// 查询数据
	//MachineryPlanPageDTO::Wrapper result = service.listAll(query);
	//// 响应结果
	//auto jvo = MachineryPlanPageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	//return {};
	// 定义一个Service
	MachineryPlanService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MachineryPlanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachineryPlanDetailsJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query)
{
	// 定义一个Service
	MachineryPlanService service;
	// 查询数据
	auto result = service.getDetails(query);
	// 响应结果
	auto jvo = MachineryPlanDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachinerySubjectPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query)
{
	// 定义一个Service
	MachinerySubjectService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MachinerySubjectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}