#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/user/UserQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/user/UserVO.h"
#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class UserController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(UserController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryAllUser) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("user.query-all.summary"), UserPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "li ming", true);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/user/query-all", queryAllUser, UserQuery, executeQueryAll(query));

	// 定义修改用户信息端点描述
	ENDPOINT_INFO(modifyUser) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("user.modify-user.summary"), StringJsonVO::Wrapper);
		// 定义修改查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("user.field.age"), 100, false);
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "feifei", false);
		// 定义二进制流请求方式，用于选择上传文件
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
	}
	// 定义修改用户信息端点处理（注意：此方式只支持单文件上传，并且更新字段不是很多的场景使用）
	ENDPOINT(API_M_POST, "/user/modify-user", modifyUser, BODY_STRING(String, fileBody), QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(dto, UserDTO, qps);
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(executeModifyUser(fileBody, dto));
	}

	// 定义查询用户菜单接口端点描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("user.query-menu.summary"), queryMenu, MenuJsonVO::Wrapper);
	// 定义查询用户菜单接口端点处理
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/user/query-menu", queryMenu, executeQueryMenu(authObject->getPayload()))
private:
	// 查询所有
	UserPageJsonVO::Wrapper executeQueryAll(const UserQuery::Wrapper& userQuery);
	// 修改用户信息
	StringJsonVO::Wrapper executeModifyUser(const String& fileBody, const UserDTO::Wrapper& dto);
	// 测试菜单
	MenuJsonVO::Wrapper executeQueryMenu(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_