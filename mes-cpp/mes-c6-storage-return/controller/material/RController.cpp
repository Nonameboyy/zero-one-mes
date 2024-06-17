#include "stdafx.h"
#include "RController.h"
#include "../../service/material/MatService.h"
#include "../ApiDeclarativeServicesHelper.h"

GetReturnListPageJsonVO::Wrapper RController::execQueryList(const GetReturnListQuery::Wrapper& query)
{

	// 定义一个Service
	MatService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetReturnListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper RController::execAddReturnLine(const AddReturnDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->rtcode || !dto->rtname || !dto->vendorname || !dto->rtdate)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
		//jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		//return jvo;
	//}

	// 定义一个Service
	MatService service;
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

Uint64JsonVO::Wrapper RController::execModifyReturnline(const AddReturnDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->rtid || dto->rtid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MatService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->rtid);
	}
	else
	{
		jvo->fail(dto->rtid);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper RController::execRemoveReturnline(const UInt64& lineid)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!lineid || lineid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MatService service;
	// 执行数据删除
	if (service.removeData(lineid.getValue(0))) {
		jvo->success(lineid);
	}
	else
	{
		jvo->fail(lineid);
	}
	// 响应结果
	return jvo;
}
