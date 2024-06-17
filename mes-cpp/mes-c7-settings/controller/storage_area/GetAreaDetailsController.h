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
#ifndef _GETAREADETAILS_CONTROLLER_
#define _GETAREADETAILS_CONTROLLER_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/storage_area/GetAreaDetailsQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/storage_area/GetAreaDetailsVO.h"


using namespace oatpp;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class GetAreaDetailsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 添加访问定义
	API_ACCESS_DECLARE(GetAreaDetailsController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryGetAreaDatails) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("area.get.summary"), GetAreaDetailsJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "li ming", true);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/settings/area/get", queryGetAreaDatails, GetAreaDetailsQuery, executeQueryAll(query));
private:
	// 查询所有
	GetAreaDetailsPageJsonVO::Wrapper executeQueryAll(const GetAreaDetailsQuery::Wrapper& userQuery);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_