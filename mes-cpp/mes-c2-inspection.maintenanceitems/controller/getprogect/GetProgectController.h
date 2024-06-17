#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ksw12355
 @Date: 2024/5/20

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
#ifndef _GETPROGECTCONTROLLER_H_
#define _GETPROGECTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include"../../domain/vo/getprogect/GetProgectVO.h"
#include"../../domain/query/getprogect/GetProgectQuery.h"
#include "domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class GetProgectController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(GetProgectController);
public:
	// 1.1 定义项目列表查询接口描述
	ENDPOINT_INFO(queryProgectList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("project.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetProgectPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		//项目编码
		API_DEF_ADD_QUERY_PARAMS(String, "pCode", ZH_WORDS_GETTER("project.fields.pcode"),  "01star",false);
		//项目名称
		API_DEF_ADD_QUERY_PARAMS(String, "pName", ZH_WORDS_GETTER("project.fields.pname"),  "QQQQQ",false);
		//项目类型
		API_DEF_ADD_QUERY_PARAMS(String, "pType", ZH_WORDS_GETTER("project.fields.ptype"), "QW",false);
	}
	// 1.2 定义项目列表查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/device-manage/query-progectList", queryProgectList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetProgectQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetProgect(query));
	}

	// 2.1 定义项目详情查询接口描述
	ENDPOINT_INFO(queryProgectDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("project.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetProgectDetailJsonVO);
		// 定义其他查询参数描述

		//设备编码
		API_DEF_ADD_QUERY_PARAMS(UInt64, "pId", ZH_WORDS_GETTER("project.fields.pid"), 1, true);
	}
	// 2.2 定义设备详情查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/device-manage/query-progectdetail", queryProgectDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetProgectDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execProgectDetail(query));
	}

	



private:
	//获取设备列表（条件+分页）
	GetProgectPageJsonVO::Wrapper execGetProgect(const GetProgectQuery::Wrapper& query);
	//获取设备详情
	GetProgectDetailJsonVO::Wrapper execProgectDetail(const GetProgectDetailQuery::Wrapper& query);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 

