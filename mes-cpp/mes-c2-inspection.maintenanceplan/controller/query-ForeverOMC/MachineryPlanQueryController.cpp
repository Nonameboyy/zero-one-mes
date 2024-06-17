#include "stdafx.h"
#include "MachineryPlanQueryController.h"
#include "../../service/query-ForeverOMC/MachineryPlanService.h"
#include "../../service/query-ForeverOMC/MachineryListService.h"
#include "../../service/query-ForeverOMC/MachinerySubjectService.h"
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"

MachineryListPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryList(const MachineryListQuery::Wrapper& query)
{
	// ����һ��Service
	MachineryListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MachineryListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachineryPlanPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlan(const MachineryPlanQuery::Wrapper& query)
{
	
	////������ԭ�����ݣ���ʱע�ͣ�������abf�Ĳ���
	//// ����һ��Service
	//int a = 0;
	//Dv_check_planService service;
	//// ��ѯ����
	//MachineryPlanPageDTO::Wrapper result = service.listAll(query);
	//// ��Ӧ���
	//auto jvo = MachineryPlanPageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	//return {};
	// ����һ��Service
	MachineryPlanService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MachineryPlanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachineryPlanDetailsJsonVO::Wrapper MachineryPlanQueryController::execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query)
{
	// ����һ��Service
	MachineryPlanService service;
	// ��ѯ����
	auto result = service.getDetails(query);
	// ��Ӧ���
	auto jvo = MachineryPlanDetailsJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

MachinerySubjectPageJsonVO::Wrapper MachineryPlanQueryController::execQueryMachinerySubject(const MachinerySubjectQuery::Wrapper& query)
{
	// ����һ��Service
	MachinerySubjectService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MachinerySubjectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}