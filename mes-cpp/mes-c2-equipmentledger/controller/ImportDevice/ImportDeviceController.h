/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
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
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ImportDeviceController)
public: // 定义接口
	
	// 1.1 定义接口描述
	ENDPOINT_INFO(uploadFile) {
		// 定义接口标题描述
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.upload-file.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}

	// 1.2 定义接口执行
	ENDPOINT(API_M_POST, "/equipment-ledger/equip/upload-file", uploadFile,
		REQUEST(std::shared_ptr<IncomingRequest>, request),API_HANDLER_AUTH_PARAME)
	{
		// 定义执行函数
		API_HANDLER_RESP_VO(execUploadFile(request));
	}
	
	// 2.1 定义接口描述
	API_DEF_ENDPOINT_INFO_AUTH(
		ZH_WORDS_GETTER("equipmentledger.import-device.summary"),
		importDevice,
		ImportDeviceJsonVO::Wrapper
	)
	// 2.2 定义接口执行
	API_HANDLER_ENDPOINT_AUTH(
		API_M_POST,
		"/equipment-ledger/equip/import-device",
		importDevice,
		BODY_STRING(String, filename),
		execImportDevice(filename)
	)

private: // 定义接口执行函数

	// 上传文件到服务器，要确保文件格式扩展名正确，文件内容不为空，并返回文件路径到前端
	StringJsonVO::Wrapper execUploadFile(std::shared_ptr<IncomingRequest> request);
	// 将根据文件路径将确认好的文件导入到数据库中
	ImportDeviceJsonVO::Wrapper execImportDevice(String filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTDEVICECONTROLLER_H_