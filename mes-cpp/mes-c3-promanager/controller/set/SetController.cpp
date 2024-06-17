#include "stdafx.h"
#include "SetController.h"
#include "../../service/set/ProcessExportService.h"
#include "../../service/set/ContentService.h"
#include "../../service/set/SetService.h"
#include "Macros.h"
#include "ExcelComponent.h"

// 注意：用到FastDfs的地方都要在最后在导入DFS的头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 1 导出工序
StringJsonVO::Wrapper SetController::execProcessExport(const ProcessExportQuery::Wrapper& query)
{
	// 定义一个Service
	ProcessExportService service;
	// 查询数据
	list<SetProAddTableDTO::Wrapper> result = service.listAll(query);
	std::vector<std::vector<std::string>> data;

	// DTO数据转换为vector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(sub->processCode);
		tmp.emplace_back(sub->processName);
		tmp.emplace_back(sub->attention);
		tmp.emplace_back(sub->enableFlag);
		data.emplace_back(tmp);
	}

	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1"),
		ZH_WORDS_GETTER("excel.header.h2"),
		ZH_WORDS_GETTER("excel.header.h3"),
		ZH_WORDS_GETTER("excel.header.h4"),
		});

	// 保存到文件
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// 创建一个fastdfs对象及前缀
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// 响应结果
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}
// 2 添加工序
Uint64JsonVO::Wrapper SetController::execAddSet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->processCode || !dto->processName || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->processCode->empty() || dto->processName->empty() || dto->enableFlag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	SetService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto,payload.getUsername());
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
// 3 修改工序
Uint64JsonVO::Wrapper SetController::execModifySet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->processId || dto->processId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SetService service;
	// 执行数据修改
	if (service.updateData(dto,payload.getUsername())) {
		jvo->success(dto->processId);
	}
	else
	{
		jvo->fail(dto->processId);
	}
	// 响应结果
	return jvo;
}
// 4 获取工序步骤列表
SetProListPageJsonVO::Wrapper SetController::execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload) {
	// 定义一个Service
	SetService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = SetProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 5 添加工序步骤
Uint64JsonVO::Wrapper SetController::execAddStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->contentId || !dto->processId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->contentId < 0 || dto->processId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	SetService service;
	// 执行数据新增
	uint64_t id = service.saveStepData(dto, payload.getUsername());
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
// 6 获取工序列表
ProListPageJsonVO::Wrapper SetController::execQueryProList(const ProListQuery::Wrapper& query)
{
	// 定义一个Service
	SetService service;
	// 查询数据
	auto result = service.listAllForProcess(query);
	// 响应结果
	auto jvo = ProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProListPageJsonVO::Wrapper();
}
// 7 获取工序名称列表
ProNameListJsonVO::Wrapper SetController::execQueryProNameList()
{
	auto jvo = ProNameListJsonVO::createShared();
	// 定义一个Service
	SetService service;
	// 查询数据
	auto result = service.getProcessNameList();
	// 响应结果
	jvo->success(result);
	return jvo;
}
// 8 获取工序详情
ProDetailJsonVO::Wrapper SetController::execQueryProDetail(const ProDetailQuery::Wrapper& query)
{
	// 定义一个Service
	SetService service;
	// 查询数据
	auto result = service.getProcessDetail(query);
	// 响应结果
	auto jvo = ProDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProDetailJsonVO::Wrapper();
}
//9 修改工序步骤
Uint64JsonVO::Wrapper SetController::execModifyStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->contentId || dto->contentId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
	if (service.updateData(dto)) {
		jvo->success(dto->contentId);
	}
	else
	{
		jvo->fail(dto->contentId);
	}
	return jvo;
}
//10 删除工序步骤
Uint64JsonVO::Wrapper SetController::execDeleteStepSet(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ContentService service;
	// 执行数据删除
	if (service.removeStep(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
// 11 导出工序步骤
StringJsonVO::Wrapper SetController::execExportStepSet(const SetProListQuery::Wrapper& query)
{
	// 定义一个Service
	SetService service;
	// 查询数据
	list<SetProListDTO::Wrapper> result = service.listAllForExport(query);
	std::vector<std::vector<std::string>> data;

	// DTO数据转换为vector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(to_string(sub->processId));
		tmp.emplace_back(to_string(sub->orderNum));
		tmp.emplace_back(sub->contentText);
		tmp.emplace_back(sub->device);
		tmp.emplace_back(sub->material);
		tmp.emplace_back(sub->docUrl);
		data.emplace_back(tmp);
	}

	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h9"),
		ZH_WORDS_GETTER("excel.header.h10"),
		ZH_WORDS_GETTER("excel.header.h11"),
		ZH_WORDS_GETTER("excel.header.h12"),
		ZH_WORDS_GETTER("excel.header.h13"),
		ZH_WORDS_GETTER("excel.header.h14"),
		});

	// 保存到文件
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s3");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// 创建一个fastdfs对象及前缀
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// 响应结果
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}

// 12 删除工序
Uint64JsonVO::Wrapper SetController::execDeleteSet(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
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