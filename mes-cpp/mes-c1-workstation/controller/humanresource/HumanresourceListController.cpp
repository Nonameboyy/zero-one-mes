#include "stdafx.h"
#include "HumanResourceListController.h"
#include "../../service/humanresource/HumanResourceListService.h"
#include "../ApiDeclarativeServicesHelper.h"

HumanResourceListPageVO::Wrapper HumanResourceListController::execQueryHumanResourceList(const HumanResourceListQuery::Wrapper& query)
{
	// 定义一个Service
	HumanResourceListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = HumanResourceListPageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execAddHumanResourceList(const HumanResourceListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->postName || !dto->quantity || !dto->workstationId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->postName->empty() || dto->quantity < 0 || dto->workstationId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	HumanResourceListService service;
	// 执行数据新增
	uint64_t recordId = service.saveData(dto);
	if (recordId > 0) {
		jvo->success(UInt64(recordId));
	}
	else
	{
		jvo->fail(UInt64(recordId));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execModifyHumanResource(const HumanResourceListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->recordId || dto->recordId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	HumanResourceListService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->recordId);
	}
	else
	{
		jvo->fail(dto->recordId);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execRemoveHumanResource(const UInt64& recordId)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!recordId || recordId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	HumanResourceListService service;
	// 执行数据删除
	if (service.removeData(recordId.getValue(0))) {
		jvo->success(recordId);
	}
	else
	{
		jvo->fail(recordId);
	}
	// 响应结果
	return jvo;
}
