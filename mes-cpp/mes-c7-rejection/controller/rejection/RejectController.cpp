#include "stdafx.h"
#include "RejectController.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PayloadDTO.h"
#include "domain/dto/PayloadDTO.h"
#include"service/rejectionQueryService/rejectionQuery.h"

RejectPageJsonVO::Wrapper RejectController::execQueryReject(const RejectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	RejectTableQueryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RejectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;


}

RejectDetailJsonVO::Wrapper RejectController::execQueryRejectDetail(const RejectDetailQuery::Wrapper& query)
{
	// 定义一个Service
	RejectTableQueryService service;
	// 查询数据
	auto result = service.queryDetail(query);
	// 响应结果
	auto jvo = RejectDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


Uint64JsonVO::Wrapper RejectController::execAddReject(const RejectDetailDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->rt_code || !dto->workorder_code || !dto->warehouse_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->rt_code->empty() || dto->workorder_code->empty() || dto->warehouse_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RejectTableQueryService service;
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

Uint64JsonVO::Wrapper RejectController::execModifyReject(const RejectDetailDTO::Wrapper& dto)
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
	RejectTableQueryService service;
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
