/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
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
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DownloadTemplateController)
public: // 定义接口

	// 定义接口描述
	ENDPOINT_INFO(downloadTemplate) {
		// 定义接口描述标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.download-template.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	// 定义接口执行
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/download-template", downloadTemplate, API_HANDLER_AUTH_PARAME) {
		// 定义执行函数
		API_HANDLER_RESP_VO(execDownloadTemplate());
	}

private: // 定义接口执行函数
	StringJsonVO::Wrapper execDownloadTemplate();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DOWNLOADTEMPLATE_H_