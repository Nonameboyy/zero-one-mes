#include "stdafx.h"
#include "RawMaterialOpController.h"
#include "../../service/RawMaterialOpService/RawMaterialOpService.h"
#include "../ApiDeclarativeServicesHelper.h"



Uint64JsonVO::Wrapper RawMaterialOpController::execRemoveRawMaterialOp(const UInt64& id)
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
	RawMaterialOpService service;
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

Uint64JsonVO::Wrapper RawMaterialOpController::execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->rt_id || dto->rt_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RawMaterialOpService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->rt_id);
	}
	else
	{
		jvo->fail(dto->rt_id);
	}
	// 响应结果
	return jvo;
}


RawMaterialOpPageJsonVO::Wrapper RawMaterialOpController::execQueryRawMaterialOp(const RawMaterialOpQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	RawMaterialOpService service;
	// 查询数据
	auto result = service.listAll(query);
	
	//// 响应结果
	auto jvo = RawMaterialOpPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
