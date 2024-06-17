#include "stdafx.h"
#include "WorkStationController.h"
#include "../mes-c1-workstation/service/workstation/WorkStationService.h"
#include "../ApiDeclarativeServicesHelper.h"


//新增工作站
Uint64JsonVO::Wrapper WorkStationController::execAddWorkStation(const AddWorkStationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->workstationCode || !dto->workshopName || !dto->processName || !dto->enableFlag || !dto->workstationName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->workstationCode->empty() || dto->workshopName->empty() || dto->processName->empty() || dto->enableFlag->empty() || dto->workstationName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	WorkStationService service;
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

StringJsonVO::Wrapper WorkStationController::execExportWorkStation(const List<UInt64>& id)
{
	//List转list
	list<uint64_t> exportid;
	for (auto item = id->begin(); item != id->end(); item++)
	{
		exportid.push_back(item->getValue({}));  // 用list承接数据
	}

	//得到返回地址
	WorkStationService service;
	string retstring = service.exportData(exportid);//调用service层exportData
	auto jvo = StringJsonVO::createShared();
	jvo->success(retstring);

	return jvo;
}

//分页查询数据
GetWorkStationListPageJsonVO::Wrapper WorkStationController::execWorkStationList(const GetWorkStationListQuery::Wrapper& query)
{
	// 定义一个Service
	WorkStationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetWorkStationListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 删除工作站
Uint64JsonVO::Wrapper WorkStationController::execRemoveWorkStation(const List<UInt64>& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	bool ok = true;
	if (!id)  ok = false;
	for (auto item = id->begin(); item != id->end(); item++)
	{
		if (item->getValue({}) <= 0)
		{
			ok = false;
			break;
		}
	}
	if (!ok)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义Service执行数据删除
	WorkStationService service;
	list<uint64_t> delid;
	for (auto item = id->begin(); item != id->end(); item++)
	{
		delid.push_back(item->getValue({}));  // 用list承接数据
	}
	// 执行数据删除
	if (service.removeDatas(delid))
	{
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	// 响应结果
	return jvo;
}


// 修改工作站
Uint64JsonVO::Wrapper WorkStationController::execModifyWorkStation(const ModifyWorkStationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->workstationId || dto->workstationId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkStationService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->workstationId);
	}
	else
	{
		jvo->fail(dto->workstationId);
	}
	// 响应结果
	return jvo;
}
