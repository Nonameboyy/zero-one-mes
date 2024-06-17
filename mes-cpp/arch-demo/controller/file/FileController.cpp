/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:37:57

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include <iostream>
#include "FileController.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper FileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "nickname", nickname);
	API_MULTIPART_PARSE_FORM_FIELD_NUM(container, "age", Int32, age, stoi);
	/* 打印表单数据 */
	if (nickname) OATPP_LOGD("Multipart", "nickname='%s'", nickname.getValue({}).c_str());
	if (age) OATPP_LOGD("Multipart", "age=%d", age.getValue({}));
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

StringJsonVO::Wrapper FileController::execUploadMore(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_FILE(reader, "file0", "public/static/file/test0.png");
	API_MULTIPART_CONFIG_FILE(reader, "file1", "public/static/file/test1.png");
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取文件部分 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file0", file0);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file1", file1);
	/* 断言文件是否获取到 */
	OATPP_ASSERT_HTTP(partfile0, Status::CODE_400, "file0 is null");
	OATPP_ASSERT_HTTP(partfile1, Status::CODE_400, "file1 is null");
	/* 打印文件保存路径 */
	OATPP_LOGD("Multipart", "file0 save path: %s", partfile0->getPayload()->getLocation()->c_str());
	OATPP_LOGD("Multipart", "file1 save path: %s", partfile1->getPayload()->getLocation()->c_str());

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> FileController::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> FileController::execHtmlFile(std::shared_ptr<IncomingRequest> request)
{
	// 获取文件路径
	auto filename = request->getPathTail();

	// 构建文件全路径
	std::string fullPath = "public/" + filename.getValue("");

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file<" << filename.getValue("") << ">: " << std::strerror(errno) << std::endl;
		const char* html = R"(
			<html>
             <head><title>404</title></head>
			 <body>
			  <h1>Page Not Found</h1>
			 </body>
			</html>)";
		auto response = createResponse(Status::CODE_404, html);
		response->putHeader(Header::CONTENT_TYPE, "text/html");
		return response;
	}

	// 创建响应对象
	auto response = createResponse(Status::CODE_200, fstring);

	// 根据文件不同类型设置不同响应头，有可能HTML中包含js和css文件，图片暂不处理
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// 响应结果
	return response;
}

EditorImageVO::Wrapper FileController::execUploadEditorImage(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);
	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 读取数据
	request->transferBody(&reader);
	// 4 获取文件数据
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		// 获取文件后缀名
		string filename = partfile->getFilename().getValue("");
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// 测试将文件保存到磁盘上面
		std::string newFileName = SimpleDateTimeFormat::formatWithMilli("%Y%m%d%H%M%S", "") + "." + suffix;
		string fullPath = "public/static/file/" + newFileName;
		file.saveToFile(fullPath.c_str());

		// 测试响应数据
		string downloadUrl = "http://localhost:8090/file/download?filename=file/" + newFileName;
		auto jvo = EditorImageVO::createShared();
		jvo->success(EditorImageDTO::createShared(downloadUrl));
		return jvo;
	}
	// 5 响应失败
	auto jvo = EditorImageVO::createShared();
	jvo->fail({});
	return jvo;
}
