#include "stdafx.h"
#include "ProcessInspectionController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/ProcessInspection/ProcessInspectionService.h"
#include "../../dao/ProcessInspection/ProcessInspectionDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "gtest/gtest.h"
#include "FastDfsClient.h"
#include "../include/NacosClient.h"

ProcessInspectionQueryPageJsonVO::Wrapper ProcessInspectionController::execQueryProcessInspection(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ProcessInspectionService service;
	//执行查询
	auto result = service.listAll(query);
	auto vo = ProcessInspectionQueryPageJsonVO::createShared();
	//把QueryPageDTO装到vo中
	vo->success(result);
	return vo;
}

Uint64JsonVO::Wrapper ProcessInspectionController::execRemoveProcessInspection(const List<UInt64>& ids)
{
	ProcessInspectionService service;
	//查询是否每一个id都符合,符合的查询,
	int flag = 0;
	auto result = Uint64JsonVO::createShared();
	for (auto i = ids->begin(); i != ids->end(); ++i) {
		auto x = (*i).getValue(0);
		//参数错误
		if (x < 0 || !x) {
			if(!flag)
				result->init(UInt64(-1), RS_PARAMS_INVALID);
			flag = 1;
		}
		else {
			//删除失败
			if (!service.remove(x)) {
				if (!flag)
					result->init(UInt64(-1), RS_FAIL);
				flag = 1;
			}
		}
	}
	if(!flag)
		result->init(UInt64(1), RS_SUCCESS);
	return result;
}

StringJsonVO::Wrapper ProcessInspectionController::execExportProcessInspection(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ExcelComponent excel;
	ProcessInspectionService service;
	//获取数据
	auto result = service.listAllExort(query);
	vector<vector<std::string>> data;
	stringstream ss;
	//读取数据
	for (auto i = result.begin(); i != result.end();++i) {
		auto x = *i;
		vector<std::string> row;
		ss.clear();
		ss << x.getId();
		row.push_back(ss.str());

		ss.str("");
		ss << x.getIpqc_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getIpqc_Type();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getWorkorder_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getItem_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getItem_Name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getSpecification();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getUnit_Of_Measure();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getQuantity_Check();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getCheck_Result();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getInspect_Date();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getInspector();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getStatus_Order();
		row.push_back(ss.str());
		ss.str("");

		data.push_back(row);
	}
	std::string fileName = ZH_WORDS_GETTER("excel.ProcessInspection.path");
	// 中文词典 
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h1"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h2"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h3") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h4") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h5") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h6"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h7"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h8"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h9"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h10"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h11"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h12"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h13")
		});
	//创建excel
	excel.writeVectorToFile(fileName, sheetName,data);
	//创建文件服务器对象,并拼接url前缀
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	//后缀名长度
	auto pos = fileName.rfind(".");
	string suffix = "";
	//有后缀名
	if (pos != string::npos) {
		suffix = fileName.substr(pos + 1);
	}
	//上传文件
	auto downloadUrl=dfs.uploadFile(fileName);
	downloadUrl = urlPrefix + downloadUrl;
	auto ans = StringJsonVO::createShared();
	//只有前缀,上传失败
	if (downloadUrl== urlPrefix) {
		ans->init("error", RS_FAIL);
	}
	else {
		ans->init(downloadUrl, RS_SUCCESS);
	}
	//删除本地文件
	std::remove(fileName.c_str());
	return ans;
}

// 获取过程检验单详情
ProcessInspectionJsonVO::Wrapper ProcessInspectionController::execQueryInspectionDetails(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ProcessInspectionService service;
	auto result = service.getInspectionDetails(query);
	auto jvo = ProcessInspectionJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ProcessInspectionController::execModifyTheProcessInspection(const ProcessInspectionDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProcessInspectionService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
	//return {};
}

Uint64JsonVO::Wrapper ProcessInspectionController::execAddProcessInspection(const ProcessInspectionDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->ipqc_code || !dto->ipqc_type || !dto->workorder_code
		|| !dto->workstation_code || !dto->quantity_check
		|| !dto->quantity_unqualified || !dto->quantity_qualified)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->ipqc_code->empty() || dto->ipqc_type->empty() || dto->workorder_code->empty()
		|| dto->workstation_code->empty() || dto->quantity_check < 0
		|| dto->quantity_unqualified < 0 || dto->quantity_qualified < 0
		)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ProcessInspectionService service;
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

// 确认检验单
Uint64JsonVO::Wrapper ProcessInspectionController::execModifyConfirmOrders(const ProcessInspectionDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (dto->check_result != "ACCEPT" && dto->check_result != "REJECT") {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ProcessInspectionService service;
	// 执行数据修改
	if (service.updateConfirmOrdersData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	//return Uint64JsonVO::Wrapper();
}
// 完成检验单
Uint64JsonVO::Wrapper ProcessInspectionController::execModifyFinishOrders(const ProcessInspectionDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (dto->workorder_code == "" || !dto->workorder_code) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ProcessInspectionService service;
	// 执行数据修改
	if (service.updateFinishOrdersData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	//return Uint64JsonVO::Wrapper();
}