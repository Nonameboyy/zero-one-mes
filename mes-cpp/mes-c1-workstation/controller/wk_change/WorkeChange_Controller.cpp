#include "stdafx.h"
#include "WorkeChange_Controller.h"
#include "../mes-c1-workstation/service/wk_changeservice/ChangeSerice.h"


Uint64JsonVO::Wrapper ChangeWorkwearController::exeChangeWorkwear(const ChangeWorkwearDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->workwearId || dto->workwearId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ChangeService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->workwearId);
	}
	else
	{
		jvo->fail(dto->workwearId);
	}
	// 响应结果
	return jvo;
}
