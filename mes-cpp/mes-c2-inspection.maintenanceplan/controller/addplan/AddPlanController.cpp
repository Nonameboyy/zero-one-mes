#include "stdafx.h"
#include "AddPlanController.h"
#include "../../service/addplan/AddPlanService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper AddPlanController::execAddplan(const AddPlanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->planCode || !dto->planType || !dto->cycleCount||!dto->planName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->cycleCount < 0 || dto->planCode->empty() || dto->planType->empty() || dto->planName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 非空校验
	// 定义一个Service
	AddPlanService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果

	return jvo;
}