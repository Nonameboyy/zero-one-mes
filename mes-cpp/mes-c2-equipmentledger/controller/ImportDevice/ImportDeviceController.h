/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/19 14:08:34

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
#ifndef _IMPORTDEVICECONTROLLER_H_
#define _IMPORTDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/ImportDeviceJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class ImportDeviceController: public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ImportDeviceController)
public: // ����ӿ�
	
	// 1.1 ����ӿ�����
	ENDPOINT_INFO(uploadFile) {
		// ����ӿڱ�������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.upload-file.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}

	// 1.2 ����ӿ�ִ��
	ENDPOINT(API_M_POST, "/equipment-ledger/equip/upload-file", uploadFile,
		REQUEST(std::shared_ptr<IncomingRequest>, request),API_HANDLER_AUTH_PARAME)
	{
		// ����ִ�к���
		API_HANDLER_RESP_VO(execUploadFile(request));
	}
	
	// 2.1 ����ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(
		ZH_WORDS_GETTER("equipmentledger.import-device.summary"),
		importDevice,
		ImportDeviceJsonVO::Wrapper
	)
	// 2.2 ����ӿ�ִ��
	API_HANDLER_ENDPOINT_AUTH(
		API_M_POST,
		"/equipment-ledger/equip/import-device",
		importDevice,
		BODY_STRING(String, filename),
		execImportDevice(filename)
	)

private: // ����ӿ�ִ�к���

	// �ϴ��ļ�����������Ҫȷ���ļ���ʽ��չ����ȷ���ļ����ݲ�Ϊ�գ��������ļ�·����ǰ��
	StringJsonVO::Wrapper execUploadFile(std::shared_ptr<IncomingRequest> request);
	// �������ļ�·����ȷ�Ϻõ��ļ����뵽���ݿ���
	ImportDeviceJsonVO::Wrapper execImportDevice(String filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTDEVICECONTROLLER_H_