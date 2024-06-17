#include "stdafx.h"
#include "MaterialController.h"
#include "../../service/materialsInformation/MaterialService.h"
#include "../ApiDeclarativeServicesHelper.h"

MaterialPageJsonVO::Wrapper MaterialController::execQueryMaterial(const MaterialQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	MaterialService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MaterialPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MaterialController::execAddMaterial(const MaterialDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->issue_id || !dto->item_id || !dto->item_code || !dto->item_name || !dto->specification || !dto->unit_of_measure || !dto->quantity_issued || !dto->batch_code || !dto->warehouse_name || !dto->location_name || !dto->area_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->issue_id <= 0 || dto->item_id <= 0 || dto->item_code->empty() || dto->item_name->empty() || dto->specification->empty() || dto->unit_of_measure->empty() || dto->quantity_issued <= 0 || dto->batch_code->empty() || dto->warehouse_name->empty() || dto->location_name->empty() || dto->area_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MaterialService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
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

Uint64JsonVO::Wrapper MaterialController::execModifyMaterial(const MaterialDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->line_id || dto->line_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MaterialService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->line_id);
	}
	else
	{
		jvo->fail(dto->line_id);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper MaterialController::execRemoveMaterial(const UInt64& id)
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
	MaterialService service;
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
