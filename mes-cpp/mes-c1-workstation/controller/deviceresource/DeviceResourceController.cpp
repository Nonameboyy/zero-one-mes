#include "stdafx.h"
#include "DeviceResourceController.h"
#include "domain/do/deviceresource/DeviceResourceDO.h"
#include "service/deviceresource/DeviceResourceService.h"



DeviceResourcePageVO::Wrapper DeviceResourceController::execGetDeviceResourceList(const DeviceResourceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	DeviceResourceService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = DeviceResourcePageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper DeviceResourceController::execAddDeviceResource(const DeviceResourceDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->equipmentCode || !dto->equipmentName || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->quantity < 0 || dto->equipmentName->empty() || dto->equipmentCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	DeviceResourceService service;
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

Uint64JsonVO::Wrapper DeviceResourceController::execModifyDeviceResource(const DeviceResourceDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->machineryId || dto->machineryId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DeviceResourceService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->machineryId);
	}
	else
	{
		jvo->fail(dto->machineryId);
	}
	// 响应结果
	return jvo;
}
Uint64JsonVO::Wrapper DeviceResourceController::execDeleteDeviceResource(const UInt64& deviceResourceId)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!deviceResourceId || deviceResourceId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DeviceResourceService service;
	// 执行数据删除
	if (service.deleteData(deviceResourceId.getValue(0))) {
		jvo->success(deviceResourceId);
	}
	else
	{
		jvo->fail(deviceResourceId);
	}
	// 响应结果
	return jvo;
}


