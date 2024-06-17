#include "stdafx.h"
#include "Delete_Workwear_Controller.h"
#include "../mes-c1-workstation/service/wk_deleteservice/DeleteService.h"

Uint64JsonVO::Wrapper DeleteWorkwearController::exeDeleteWorkwear(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DeleteService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}