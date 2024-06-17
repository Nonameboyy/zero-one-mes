#include "ProdTaskController.h"
#include "stdafx.h"
#include "../../service/ProdTask/ProdTaskService.h"
#include "../ApiDeclarativeServicesHelper.h"
Uint64JsonVO::Wrapper ProdTaskController::execModifyProdTask(const ProdTaskModifyDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->task_id || dto->task_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProdTaskService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(UInt64(dto->task_id));
	}
	else
	{
		jvo->fail(UInt64(dto->task_id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper ProdTaskController::execRemoveProdTask(const UInt64& id)
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
	ProdTaskService service;
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