#include "stdafx.h"
#include "WorkFixtureController.h"
#include "../../service/workfixture/WorkFixtureService.h"

WorkFixtureJsonVO::Wrapper WorkFixtureController::execQueryWorkFixtureTable(const WorkFixtureQuery::Wrapper &query)
{
	// 定义service并执行查询
	WorkFixtureService service;
	auto res = service.queryList(query);
	// 响应结果
	auto jvo = WorkFixtureJsonVO::createShared();
	jvo->success(res);
	return jvo;
}

WorkFixtureDetailJsonVO::Wrapper WorkFixtureController::execQueryWorkFixtureDetail(const UInt64 id)
{
	// 定义service并执行查询
	WorkFixtureService service;
	auto res = service.queryDetail(id);
	// 响应结果
	auto jvo = WorkFixtureDetailJsonVO::createShared();
	jvo->success(res);
	return jvo;
}

Uint64JsonVO::Wrapper WorkFixtureController::execAddWorkFixture(const WorkFixtureDTO::Wrapper &dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->toolName || !dto->quantity || !dto->toolTypeId || !dto->toolTypeCode || !dto->toolTypeName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	// 有效值校验
	if (dto->toolName->empty() || dto->quantity.getValue({}) < 0 || dto->quantityAvail.getValue({}) < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	// 定义一个Service
	WorkFixtureService service;
	// 执行数据新增
	uint64_t id = service.addData(dto);
	if (id > 0)
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper WorkFixtureController::execModifyWorkFixture(const WorkFixtureDTO::Wrapper &dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->toolId || !dto->toolName || !dto->quantity || !dto->toolTypeId || !dto->toolTypeCode || !dto->toolTypeName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	// 有效值校验
	if (dto->toolName->empty() || dto->quantity.getValue({}) < 0 || dto->quantityAvail.getValue({}) < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	}
	// 定义一个Service
	WorkFixtureService service;
	// 执行数据修改
	uint64_t id = service.updateData(dto);
	if (id > 0)
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper WorkFixtureController::execRemoveWorkFixture(const List<UInt64> &id)
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
	WorkFixtureService service;
	list<uint64_t> delid;
	for (auto item = id->begin(); item != id->end(); item++)
	{
		delid.push_back(item->getValue({}));  // 用list承接数据
	}
	// 执行数据删除
	if (service.removeData(delid))
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

StringJsonVO::Wrapper WorkFixtureController::execExportWorkFixture(const List<UInt64> &id)
{
	// 对于List到list的处理可以参考execRemoveData函数
	// 其余Service和DAO层相关导出函数的定义和实现直接在WorkFixtureService和WorkFixtureDAO(.h/.cpp)中编写即可
	// 以WorkFixtureTypeSetting为前缀的相关类和源文件不属于工装夹具台账部分的内容，不要修改


	//List转list
	list<uint64_t> exportid;
	for (auto item = id->begin(); item != id->end(); item++)
	{
		exportid.push_back(item->getValue({}));  // 用list承接数据
	}

	//得到返回地址
	WorkFixtureService service;
	string retstring =service.exportData(exportid);//调用service层exportData
	auto jvo = StringJsonVO::createShared();
	jvo->success(retstring);

	return jvo;
}
