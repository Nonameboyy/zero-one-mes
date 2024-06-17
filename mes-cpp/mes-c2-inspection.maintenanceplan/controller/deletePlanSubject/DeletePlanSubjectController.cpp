#include "stdafx.h"
#include "DeletePlanSubjectController.h"
//扩查询来辅助
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_plan/Dv_check_planService.h"
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_subject/Dv_check_subjectService.h"
#include "../mes-c2-inspection.maintenanceplan/service/dv_check_machinery/Dv_check_machineryService.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

bool allKeyExistIsCheckMachinery(const DeletePlanMachineryQuery::Wrapper& query)
{
	Dv_check_machineryService service;
	// 查询数据
	DeletePlanMachineryQueryDTO::Wrapper result = service.listAll(query);
	// 响应结果
	auto jvo = DeletePlanMachineryQueryJsonVO::createShared();
	jvo->success(result);
	auto jvoData = jvo->data;
	auto record_idJvoData = jvoData->record_id;
	auto tq001 = query->record_id;

	if (record_idJvoData != nullptr)
	{
		//cout << "数据表存在待删除id：" << tq001 << endl;
		return true;
	}
	else
	{
		//cout << "数据表没有待删除id：" << tq001 << endl;
		return false;
	}
}
BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanMachiner(const DeleteMachinerDTO::Wrapper& dto)
{
	auto jvo = BooleanJsonVO::createShared();
	auto dtoItem = dto->item;
	auto itemList = dtoItem.get();

	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{
		//std::cout << *it << " ";//此处的*it大概能被当做id去使用
		if (!(*it) || (*it) <= 0)
		{
			jvo->init(Boolean(false), RS_PARAMS_INVALID);//失败返回参数异常
			return jvo;

		}
	}//cout << endl;

	//2、暂时不上锁

	//3、存在性检测
	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{
		auto query_delete_machinery = DeletePlanMachineryQuery::createShared();
		query_delete_machinery->setRecord_id(*it);
		if (allKeyExistIsCheckMachinery(query_delete_machinery) == false)
		{
			jvo->init(Boolean(false), RS_FAIL);
			return jvo;
		}
	}
	//4、删除

	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{

		// 定义一个Service
		Dv_check_machineryService service;
		// 执行数据删除
		service.dv_check_machineryRemoveData((*it).getValue(0));
	}
	jvo->init(Boolean(true), RS_SUCCESS);
	return jvo;
}

bool allKeyExistIsCheckSubject(const DeletePlanSubjectQuery::Wrapper& query)
{
	Dv_check_subjectService service;
	// 查询数据
	DeletePlanSubjectQueryDTO::Wrapper result = service.listAll(query);
	// 响应结果
	auto jvo = DeletePlanSubjectQueryJsonVO::createShared();
	jvo->success(result);
	auto jvoData = jvo->data;
	auto record_idJvoData = jvoData->record_id;
	auto tq001 = query->record_id;

	if (record_idJvoData != nullptr)
	{
		//cout << "数据表存在待删除id：" << tq001 << endl;
		return true;
	}
	else
	{
		//cout << "数据表没有待删除id：" << tq001 << endl;
		return false;
	}
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanSubject(const DeleteSubjectDTO::Wrapper& dto)
{
	auto jvo = BooleanJsonVO::createShared();
	auto dtoItem = dto->item;
	auto itemList = dtoItem.get();

	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{
		//std::cout << *it << " ";//此处的*it大概能被当做id去使用
		if (!(*it) || (*it) <= 0)
		{
			jvo->init(Boolean(false), RS_PARAMS_INVALID);//失败返回参数异常
			return jvo;

		}
	}//cout << endl;

	//2、暂时不上锁

	//3、存在性检测
	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{
		auto query_delete_subject = DeletePlanSubjectQuery::createShared();
		query_delete_subject->setRecord_id(*it);
		if (allKeyExistIsCheckSubject(query_delete_subject) == false)
		{
			jvo->init(Boolean(false), RS_FAIL);
			return jvo;
		}
	}
	//4、删除

	for (std::list<oatpp::Int64>::iterator it = itemList->begin(); it != itemList->end(); ++it)
	{

		// 定义一个Service
		Dv_check_subjectService service;
		// 执行数据删除
		service.dv_check_subjectRemoveData((*it).getValue(0));
	}
	jvo->init(Boolean(true), RS_SUCCESS);
	return jvo;
}

bool idExistIs(const DeletePlanQuery::Wrapper& query)
{
	Dv_check_planService service;
	// 查询数据
	DeletePlanQueryDTO::Wrapper result = service.listAll(query);
	// 响应结果
	auto jvo = DeletePlanQueryJsonVO::createShared();
	jvo->success(result);

	//auto test001 = jvo.get();
	//auto test002 = jvo->data;//得到DTO，即数据传输对象
	auto jvoData = jvo->data;
	auto plan_idJvoData = jvoData->plan_id;
	//auto test003 = test002->plan_id;//得到了dto里的plan_id数据

	auto tq001 = query->plan_id;

	//不存在查询结果时，调用判断会引发访问权限异常，【不可以】
	//if (test003!=0)cout << "输入的id和查找到的id一致，存在" << endl;
	//else cout << "查找的id不存在" << endl;

	//这个可用
	if (plan_idJvoData != nullptr)
	{
		//cout << "数据表存在待删除id：" << tq001 << endl;
		return true;
	}
	else
	{
		//cout << "数据表没有待删除id：" << tq001 << endl;
		return false;
	}
}

BooleanJsonVO::Wrapper DeletePlanSubjectController::execDeletePlan(const DeletePlanDTO::Wrapper& dto)
{
	//删除操作流程：
	//1、判断输入合法性，不合法返回错误
	//2、上锁（避免批量id检测通过后被抢先删除），准备开始尝试
	//3、检查  本次批量id是否全都在数据表中，不满足条件则不执行删除
	//4、删除联表*2，删除本表*1
	//5、解锁
	//6、返回成功提示


	auto jvo = BooleanJsonVO::createShared();
	//1、参数校验
	auto idListDTO = (dto->item);
	auto idList = idListDTO.get();
	//auto abf2 = idListDTO->begin();
	//auto abf11 = *(idListDTO->begin());
	//遍历list进行参数校验，1、范围检测。  2、存在性检测。
	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{
		//std::cout << *it << " ";//此处的*it大概能被当做id去使用
		if (!(*it) || (*it) <= 0)
		{
			jvo->init(Boolean(false), RS_PARAMS_INVALID);//失败返回参数异常
			return jvo;
		}
	}//cout << endl;

	//3、检查，查询
	//auto nums = idList->size();
	//auto existNums = 0;
	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{
		//这个方法读取权限有问题，用不了，换一个
		//DeletePlanQuery::Wrapper query ;
		//query->plan_id = *it;

		auto query_delete_plan = DeletePlanQuery::createShared();
		//query_delete_plan[param.first.toString()] = oatpp::Int64(*it);
		//query_delete_plan= oatpp::Int64(*it);
		query_delete_plan->setPlan_id(*it);
		if (idExistIs(query_delete_plan) == false)
		{
			jvo->init(Boolean(false), RS_FAIL);
			return jvo;
		}
	}
	//4、删除

	for (std::list<oatpp::Int64>::iterator it = idList->begin(); it != idList->end(); ++it)
	{

		// 定义一个Service
		Dv_check_planService service;
		//注释了连表操作
		//service.dv_check_machineryRemoveDataIDP((*it).getValue(0));
		//service.dv_check_subjectRemoveDataIDP((*it).getValue(0));
		// 执行数据删除
		service.dv_check_planRemoveData((*it).getValue(0));
	}
	jvo->init(Boolean(true), RS_SUCCESS);
	return jvo;

}

DeletePlanQueryJsonVO::Wrapper DeletePlanSubjectController::execDeletePlanQuery(const DeletePlanQuery::Wrapper& query)
{
	int a = 0;
	Dv_check_planService service;
	// 查询数据
	DeletePlanQueryDTO::Wrapper result = service.listAll(query);
	// 响应结果
	auto jvo = DeletePlanQueryJsonVO::createShared();
	jvo->success(result);

	auto test001 = jvo.get();
	auto test002 = jvo->data;//得到DTO，即数据传输对象
	auto test003 = test002->plan_id;//得到了dto里的plan_id数据

	auto tq001 = query->plan_id;

	//不存在查询结果时，调用判断会引发访问权限异常，【不可以】
	//if (test003!=0)cout << "输入的id和查找到的id一致，存在" << endl;
	//else cout << "查找的id不存在" << endl;

	//这个可用

	if (test003 != nullptr)
		;
		//cout << "输入的id和查找到的id一致，存在" << endl;
	else
	{
		//jvo->init
		//cout << "查找的id不存在" << endl;
	}
	return jvo;
}










