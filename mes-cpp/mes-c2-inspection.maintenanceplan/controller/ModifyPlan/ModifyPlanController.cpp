#include "ModifyPlanController.h"
#include "stdafx.h"
#include "service/MaintenancePlan/ModifyPlanServer.h"

MaintenancePlanJsonVo::Wrapper ModifyPlanController::execModifyPlan(const MaintenancePlanDto::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = MaintenancePlanJsonVo::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0 )
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (!dto->code || !dto->name || !dto->type || !dto->cyclecount || !dto->cycletype)
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->cyclecount < 0)
	{
		jvo->init(dto, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ModifyPlanService service;
	// 执行数据修改
	if (service.updateData(dto,payload)) {
		jvo->success(dto);
	}
	else
	{
		jvo->fail(dto);
	}
	//响应结果
	return jvo;
}
