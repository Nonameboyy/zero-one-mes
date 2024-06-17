/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/19 13:41:55

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
#ifndef _EXPORTDEVICECONTROLLER_H_
#define _EXPORTDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/ExportDeviceQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExportDeviceController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportDeviceController)
public: // 定义接口
	ENDPOINT_INFO(exportDevice) {
		// 定义接口描述标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.export-device.summary"));

		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// 定义其他参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "device_code",
			ZH_WORDS_GETTER("equipmentledger.export-device.device-code"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "device_name",
			ZH_WORDS_GETTER("equipmentledger.export-device.device-name"), {}, false);

		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, "/equipment-ledger/equip/export-device", exportDevice,
		QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, ExportDeviceQuery, queryParams);
		// 调用执行函数
		API_HANDLER_RESP_VO(execExportDevice(query));
	}

private: // 定义接口执行函数
	StringJsonVO::Wrapper execExportDevice(const ExportDeviceQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTDEVICECONTROLLER_H_