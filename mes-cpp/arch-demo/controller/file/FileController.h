#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 11:19:05

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
#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/file/FileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class FileController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FileController);
public:
	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/file/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

	// ����һ�����ļ��ϴ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload-more.summary"), uploadFileMore, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/file/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadMore(request));

	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.jpg", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/file/download", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}

	// ����һ��HTML�ļ��ӿ�
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.html.summary"), htmlFile, Void);
	// ����˵�
	ENDPOINT(API_M_GET, "/file/**", htmlFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		return execHtmlFile(request);
	}

	// ����һ���ļ��ϴ��ӿ����ڴ����ı��༭��
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.editor-upload-image.summary"), uploadImage, EditorImageVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "/file/editor-upload-image", uploadImage, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadEditorImage(request));
private: // ����ӿ�ִ�к���
	// ִ�е��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	// ִ�ж��ļ��ϴ�����
	StringJsonVO::Wrapper execUploadMore(std::shared_ptr<IncomingRequest> request);
	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	// ִ��HTML�ļ�����
	std::shared_ptr<OutgoingResponse> execHtmlFile(std::shared_ptr<IncomingRequest> request);
	// ִ��EditorͼƬ�ϴ�����
	EditorImageVO::Wrapper execUploadEditorImage(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_