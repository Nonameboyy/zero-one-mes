#include "stdafx.h"
#include "ReturnController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"
#include "service/return/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query)
{
	ReturnService service;
	auto result = service.listAll(query);
	auto jvo = ReturnPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{

	ReturnService service;
	auto result = service.getDetail(returnDetailQuery);
	auto jvo = ReturnDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->returnCode->empty()||dto->returnName->empty()||dto->returndate->empty()||dto->vendorName->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ReturnService service;
	auto result = service.saveData(dto);
	jvo->success(result);
	return jvo;
}
//// 修改单据
//Uint64JsonVO::Wrapper ReturnController::execModifyReturn(const ReturnDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	/*if (!dto->returnId || dto->returnId <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// 定义一个Service
//	ReturnService service;
//	// 执行数据修改
//	// if (service.updateData(dto))  //需要dao支持，还未定义
//	if (true)//直接响应
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// 响应结果
//	return jvo;
//}
//
//// 执行单据
//Uint64JsonVO::Wrapper ReturnController::execExecuteReturn(const String& code)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	/*if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// 定义一个Service
//	ReturnService service;
//	// 在数据库中执行退货操作
//	// if (service.removeData(id.getValue(0))) 
//
//	if (true)
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// 响应结果
//	return jvo;
//}
//// 删除单据
//Uint64JsonVO::Wrapper ReturnController::execRemoveReturn(const String& code)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	/*if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// 定义一个Service
//	ReturnService service;
//
//	//在数据库中查询对应id的数据
//	//ReturnDTO::Wrapper dto_remove;
//	//状态不为草稿无法删除
//	/*if (dto_remove->status != 0)
//	{
//		jvo->fail(id);
//	}*/
//
//	// 执行数据删除
//	// if (service.removeData(id.getValue(0))) 
//	if (true)
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// 响应结果
//	return jvo;
//}
//// 导出单据
//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ReturnController::execDownloadFile(const String& code)
//{
//	// 构建文件全路径 // 相对路径无法加载
//	std::string fullPath = "C:/Users/RHY/Desktop/C6/zero-one-08mes/mes-cpp/mes-c6-storage-return/public/static/file/C6RyanTest.jpg" ;
//	// 读取文件
//	auto fstring = String::loadFromFile(fullPath.c_str());
//
//	// 判断是否读取成功
//	if (!fstring)
//	{
//		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
//		return createResponse(Status::CODE_404, "File Not Found");
//	}
//
//	// 创建响应头
//	auto response = createResponse(Status::CODE_200, fstring);
//
//	// 设置响应头信息
//	response->putHeader("Content-Disposition", "attachment; code=" + code.getValue(""));
//
//	// 影响成功结果
//	return response;
//}