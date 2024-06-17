#include "stdafx.h"
#include "PickController.h"
#include "../../service/pick/PickService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper PickController::execAddPick(const PickDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->issueCode || !dto->issueName || !dto->clientName||!dto->createTime||!dto->workorderCode||
		!dto->warehouseName||!dto->status||!dto->clientCode||!dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->issueCode->empty() || dto->issueName->empty() || dto->workorderCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	PickService service;
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

Uint64JsonVO::Wrapper PickController::execModifyPick(const PickDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->issueCode || !dto->issueName || !dto->clientName || !dto->createTime || !dto->workorderCode ||
		!dto->warehouseName || !dto->status || !dto->clientCode || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->issueCode->empty() || dto->issueName->empty() || dto->workorderCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	PickService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(UInt64(dto->issueId));
	}
	else
	{
		jvo->fail(UInt64(dto->issueId));
	}
	// 响应结果
	return jvo;
}

//执行生产领料
Uint64JsonVO::Wrapper PickController::executeExecuteGet(const UInt64& id)
{
	return{};
}
//删除单据
Uint64JsonVO::Wrapper PickController::executeRemoveReturn(const UInt64& id)
{
	return{};
}
// 导出单据
StringJsonVO::Wrapper PickController::executeDownloadFile(const oatpp::List<UInt64>& ids)
{
	return{};
}