/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/19 15:14:11

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
#ifndef _DOWNLOADTEMPLATE_H_
#define _DOWNLOADTEMPLATE_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DownloadTemplateController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DownloadTemplateController)
public: // ����ӿ�

	// ����ӿ�����
	ENDPOINT_INFO(downloadTemplate) {
		// ����ӿ���������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.download-template.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}
	// ����ӿ�ִ��
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/download-template", downloadTemplate, API_HANDLER_AUTH_PARAME) {
		// ����ִ�к���
		API_HANDLER_RESP_VO(execDownloadTemplate());
	}

private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execDownloadTemplate();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DOWNLOADTEMPLATE_H_