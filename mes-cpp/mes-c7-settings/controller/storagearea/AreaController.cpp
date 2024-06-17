
#include "stdafx.h"
#include "AreaController.h"
#include "../../service/storagearea/AreaService.h"

AreaPageJsonVO::Wrapper AreaController::execQueryArea(const AreaQuery::Wrapper& query, const PayloadDTO& payload)
{
	AreaService service;
	auto result = service.listAllAreabyPage(query);
	
	auto apj = AreaPageJsonVO::createShared();
	apj->success(result);
	return apj;
}
//返回的是增加的那一行

Uint64JsonVO::Wrapper AreaController::execAddArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto apj = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id ||!dto->location_id || !dto->area_code || !dto->area_name) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	//// 有效值校验
	//if (dto->areasize <= 0 || dto->max_loa <= 0 || dto->create_by->empty() || dto->create_time->empty() || dto->update_by->empty() || dto->update_time->empty()) {
	//	apj->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return apj;
	//}
	//是否要判断 去重
	AreaService service;
	uint64_t row =   service.insertArea(dto,payload);
	if (row > 0) {
		apj->success(UInt64(row));
	}
	else {
		apj->fail(UInt64(row));
	}
	return apj;
}
//返回的是修改的那一行
Uint64JsonVO::Wrapper AreaController::execModifyArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto apj = Uint64JsonVO::createShared();
	//修改传入的是AreaDTO类型 没有过滤掉id 和 location_id
	if (!dto->id || !dto->location_id || !dto->area_code || !dto->area_name) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	
	if (dto->areasize <= 0 || dto->max_loa <= 0 ) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	AreaService service;
	// 执行数据修改
	if (service.updateArea(dto,payload)) {
		apj->success(dto->id);
	}
	else
	{
		apj->fail(dto->id);
	}
	return apj;
}
//返回的是删除的那一行
Uint64JsonVO::Wrapper AreaController::execRemoveArea(const oatpp::List<Int32>& idsdto)
{
	auto apj = Uint64JsonVO::createShared();
	std::list<int64_t> list;
	auto p = idsdto->begin();
	for ( ;p!=idsdto->end(); p++)
	{
		list.push_back((*p).getValue(0));
		if (!(*p) || (*p) <= 0) {
			apj->init(UInt64(-1), RS_PARAMS_INVALID);
			return apj;
		}
	}
	// 定义一个Service
	AreaService service;
	// 执行数据删除
	
	if (service.removeArea(list)) {
		apj->success(list.size());
	}
	else
	{
		apj->fail(list.size());
	}
	// 响应结果
	return apj;
}





