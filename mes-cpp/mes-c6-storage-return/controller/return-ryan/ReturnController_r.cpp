#include "stdafx.h"
#include "ReturnController_r.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"
#include "service/return-ryan/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"

//ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	return {};
//}
//
//ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
//{
//	return {};
//}
//
//Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
//{
//	return {};
//}




// 修改单据
Uint64JsonVO::Wrapper ReturnController_r::execModifyReturn(const ReturnDTO_r::Wrapper& dto)
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
	ReturnService service;
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

// 执行单据
Uint64JsonVO::Wrapper ReturnController_r::execExecuteReturn(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ReturnService service;
	// 执行数据修改
	if (service.excuteData(id)){
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
// 删除单据
Uint64JsonVO::Wrapper ReturnController_r::execRemoveReturn(const oatpp::List<UInt64>& ids)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	
	// 参数校验
	for (list<UInt64>::iterator i = ids->begin();i != ids->end();i++)
	{
		UInt64 id = *i;
		if (!id || id <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		ReturnService service;
		// 执行数据删除
		if (service.removeData(id.getValue(0))) {
			jvo->success(id);
		}
		else
		{
			jvo->fail(id);
		}
	}
	// 响应结果
	return jvo;
}
// 导出单据
StringJsonVO::Wrapper ReturnController_r::execDownloadFile(const ReturnQuery_r::Wrapper& query, const PayloadDTO& payload)
{
	ExcelComponent excel;
	ReturnService service;
	//获取数据
	auto result = service.listAllExort(query);
	vector<vector<std::string>> data;
	stringstream ss;
	//读取数据
	for (auto i = result.begin(); i != result.end(); ++i) {
		auto x = *i;
		//rt_id,rt_code,rt_name,po_code, vendor_name, batch_code, rt_date, status, remark
		vector<std::string> row;
		ss.clear();
		ss << x.getRt_code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getRt_name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getPo_code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getVendor_name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getRt_date();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getStatus_();
		row.push_back(ss.str());
		ss.str("");

		data.push_back(row);
	}
	std::string fileName = ZH_WORDS_GETTER("excel.Return.path");
	// 中文词典
	//std::string sheetName = ZH_WORDS_GETTER("excel.Return.sheet.s1");
	std::string sheetName = "title";
	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.Return.header.h1"),
		ZH_WORDS_GETTER("excel.Return.header.h2"),
		ZH_WORDS_GETTER("excel.Return.header.h3"),
		ZH_WORDS_GETTER("excel.Return.header.h4"),
		ZH_WORDS_GETTER("excel.Return.header.h5"),
		ZH_WORDS_GETTER("excel.Return.header.h6")
		});
	//创建excel
	excel.writeVectorToFile(fileName, sheetName, data);
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
	auto downloadUrl = dfs.uploadFile(fileName);
	downloadUrl = urlPrefix + downloadUrl;
	auto ans = StringJsonVO::createShared();
	//只有前缀,上传失败
	if (downloadUrl == urlPrefix) {
		ans->init("error", RS_FAIL);
	}
	else {
		ans->init(downloadUrl, RS_SUCCESS);
	}
	//删除本地文件
	std::remove(fileName.c_str());
	return ans;
}

StringJsonVO::Wrapper ReturnController_r::execDownloadFile_q(const ReturnQuery_r::Wrapper& query)
{
	auto res = StringJsonVO::createShared();

	ReturnService service;
	auto url = service.exportTable(query);

	if (url != "")
		res->success(url);
	else
		res->fail("");
	return res;
	return StringJsonVO::Wrapper();
}
