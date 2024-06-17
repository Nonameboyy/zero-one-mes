#include "stdafx.h"
#include "ProWorkorderController.h"
#include "../mes-c4-prodmgmt/service/ProWorkorder/ProWorkorderService.h"


Uint64JsonVO::Wrapper ProWorkorderController::execModifyProWorkdorder(const ModifyProWorkorderDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->workorderId || dto->workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProWorkorderService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->workorderId);
	}
	else
	{
		jvo->fail(dto->workorderId);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper ProWorkorderController::execRemoveProWorkorder(const UInt64& id)
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
	ProWorkorderService service;
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

Uint64JsonVO::Wrapper ProWorkorderController::execConfirmProWorkorder(const UInt64& workorderId)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!workorderId || workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProWorkorderService service;

	if (service.confirmData(workorderId.getValue(0))) {
		jvo->success(workorderId);
	}
	else
	{
		jvo->fail(workorderId);
	}
	// 响应结果
	return jvo;

}

Uint64JsonVO::Wrapper ProWorkorderController::execCompleteProWorkorder(const UInt64& workorderId)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!workorderId || workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProWorkorderService service;
	// 执行数据删除
	if (service.completeData(workorderId.getValue(0))) {
		jvo->success(workorderId);
	}
	else
	{
		jvo->fail(workorderId);
	}
	// 响应结果
	return jvo;
}

