#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _MERGEMENU_CONTROLLER_
#define _MERGEMENU_CONTROLLER_
#include "domain/dto/warehouse-settings/WarehouseCascadeDTO.h"
#include "domain/vo/warehouse-settings/AdressMergeMenuVO.h"
#include "domain/vo/BaseJsonVO.h"



using namespace oatpp;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MergeMenuController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 添加访问定义
	API_ACCESS_DECLARE(MergeMenuController);
public:
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storagearea.query-menu.summary"), queryMergeMenu, MergeMenuJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/settings/query-warehouse", queryMergeMenu, executeQueryMergeMenu(authObject->getPayload()))
private:
	MergeMenuJsonVO::Wrapper executeQueryMergeMenu(const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_