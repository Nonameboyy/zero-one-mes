#include "stdafx.h"
#include"AddDeviceTypeController.h"
#include"../../service/add-device-type/AddtDeviceTypeService.h"
#include"../ApiDeclarativeServicesHelper.h"
#include"../../service/declarative/DevTypeApiClient.h"
static StringJsonVO::Wrapper getDevTypeCode(const string &type, const PayloadDTO &payload)
{
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, DevTypeApiClient, "getcode-api");
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 返回查询结果
	return ac->getDevTypeCode(token, type)->readBodyToDto<StringJsonVO::Wrapper>(om);
}

Uint64JsonVO::Wrapper AddDeviceTypeController::execAddDeviceType(const AddDeviceTypeListDTO::Wrapper &dto, const PayloadDTO &payload)
{
	auto jvo = Uint64JsonVO::createShared();
	// 必传参数检验
	if (!dto->parentTypeId|| !dto->status || !dto->machineryTypeName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->status->empty() || dto->machineryTypeName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 通过声明式服务调用获取设备类型编码
	string code = getDevTypeCode("string", payload)->data;
	// 定义一个Service实例
	AddDeviceTypeService service;
	uint64_t res = service.addData(dto, code);
	if (res > 0) 
	{
		jvo->success(UInt64(res));
	}
	else
	{
		jvo->fail(UInt64(res));
	}
	// 响应结果
	return jvo;
}


