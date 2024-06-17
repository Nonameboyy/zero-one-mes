#include "stdafx.h"
#include "storageController.h"
#include "../../service/storage/storageService.h"
#include "../ApiDeclarativeServicesHelper.h"



Uint64JsonVO::Wrapper storageController::execRemovestorage(const UInt64& id)
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
	storageService service;
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

Uint64JsonVO::Wrapper storageController::execModifystorage(const storageDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->re_id || dto->re_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	storageService service;
	// 执行数据修改
	if (service.update(dto)) {
		jvo->success(dto->re_id);
	}
	else
	{
		jvo->fail(dto->re_id);
	}
	// 响应结果
	return jvo;
}


storagePageJsonVO::Wrapper storageController::execQuerystorage(const storageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	storageService service;
	// 查询数据
	auto result = service.listAll(query);
	
	//// 响应结果
	auto jvo = storagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
