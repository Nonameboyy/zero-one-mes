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

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

StringJsonVO::Wrapper FileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* TODO: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/* ��ȡ������ */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "nickname", nickname);
	API_MULTIPART_PARSE_FORM_FIELD_NUM(container, "age", Int32, age, stoi);
	/* ��ӡ������ */
	if (nickname) OATPP_LOGD("Multipart", "nickname='%s'", nickname.getValue({}).c_str());
	if (age) OATPP_LOGD("Multipart", "age=%d", age.getValue({}));
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* ��ӡ�ļ����� */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* ���Խ��ļ����浽�������� */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		/* �����ϴ���FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// ��ȡ�ļ���׺��
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// �ϴ��ļ�
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

StringJsonVO::Wrapper FileController::execUploadMore(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);

	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_FILE(reader, "file0", "public/static/file/test0.png");
	API_MULTIPART_CONFIG_FILE(reader, "file1", "public/static/file/test1.png");
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 ��ȡ����
	request->transferBody(&reader);
	/* ��ӡ�ϴ��ܲ����� */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 ��������
	/* TODO: ���������ݾ����߼�����Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	/* ��ȡ�ļ����� */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file0", file0);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file1", file1);
	/* �����ļ��Ƿ��ȡ�� */
	OATPP_ASSERT_HTTP(partfile0, Status::CODE_400, "file0 is null");
	OATPP_ASSERT_HTTP(partfile1, Status::CODE_400, "file1 is null");
	/* ��ӡ�ļ�����·�� */
	OATPP_LOGD("Multipart", "file0 save path: %s", partfile0->getPayload()->getLocation()->c_str());
	OATPP_LOGD("Multipart", "file1 save path: %s", partfile1->getPayload()->getLocation()->c_str());

	// 5 ��Ӧ���
	/* TODO: ������Ӧʲô�������Ҫ�������ҵ����������������ʹ��ʾ�����ѡ� */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> FileController::execDownloadFile(const String& filename)
{
	// �����ļ�ȫ·��
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> FileController::execHtmlFile(std::shared_ptr<IncomingRequest> request)
{
	// ��ȡ�ļ�·��
	auto filename = request->getPathTail();

	// �����ļ�ȫ·��
	std::string fullPath = "public/" + filename.getValue("");

	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
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

	// ������Ӧ����
	auto response = createResponse(Status::CODE_200, fstring);

	// �����ļ���ͬ�������ò�ͬ��Ӧͷ���п���HTML�а���js��css�ļ���ͼƬ�ݲ�����
	if (filename->find(".js") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/javascript; charset=utf-8");
	else if (filename->find(".css") != string::npos)
		response->putHeader(Header::CONTENT_TYPE, "text/css");
	else
		response->putHeader(Header::CONTENT_TYPE, "text/html");

	// ��Ӧ���
	return response;
}

EditorImageVO::Wrapper FileController::execUploadEditorImage(std::shared_ptr<IncomingRequest> request)
{
	// 1 ��ʼ��
	API_MULTIPART_INIT(container, reader);
	// 2 ���ö�ȡ��
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 ��ȡ����
	request->transferBody(&reader);
	// 4 ��ȡ�ļ�����
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		// ��ȡ�ļ���׺��
		string filename = partfile->getFilename().getValue("");
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		// ���Խ��ļ����浽��������
		std::string newFileName = SimpleDateTimeFormat::formatWithMilli("%Y%m%d%H%M%S", "") + "." + suffix;
		string fullPath = "public/static/file/" + newFileName;
		file.saveToFile(fullPath.c_str());

		// ������Ӧ����
		string downloadUrl = "http://localhost:8090/file/download?filename=file/" + newFileName;
		auto jvo = EditorImageVO::createShared();
		jvo->success(EditorImageDTO::createShared(downloadUrl));
		return jvo;
	}
	// 5 ��Ӧʧ��
	auto jvo = EditorImageVO::createShared();
	jvo->fail({});
	return jvo;
}
