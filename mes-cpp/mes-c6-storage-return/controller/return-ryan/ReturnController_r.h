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
#ifndef _RETURNCONTROLLER_R_H_
#define _RETURNCONTROLLER_R_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/return-ryan/ReturnQuery_r.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/return-ryan/ReturnVO_r.h"
#include "ApiHelper.h"
#include "domain/dto/return-ryan/ReturnDTO_r.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ReturnController_r : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(ReturnController_r);
public:
	//Ryan
	// 定义修改单据接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.modify.summary"), modifyReturn, Uint64JsonVO::Wrapper);
	// 定义修改单据接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/return/modify", modifyReturn, BODY_DTO(ReturnDTO_r::Wrapper, dto), execModifyReturn(dto));

	// 定义执行退货接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.execute.summary"), executeReturn, Uint64JsonVO::Wrapper);
	// 定义执行退货接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/do/{rt_id_exec}", executeReturn, PATH(UInt64, rt_id_exec), execExecuteReturn(rt_id_exec));

	// 定义删除单据接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("return.remove.summary"), removeReturn, Uint64JsonVO::Wrapper);
	// 定义删除单据接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/return/remove", removeReturn, BODY_DTO(List<UInt64>, ids), execRemoveReturn(ids));

	// 定义导出单据接口描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("return.download.summary"), Void);
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他查询参数描述
		
		API_DEF_ADD_QUERY_PARAMS(String, "rt_code", ZH_WORDS_GETTER("return.field.rt_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rt_name", ZH_WORDS_GETTER("return.field.rt_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "po_code", ZH_WORDS_GETTER("return.field.po_code"), "", false);


	}
	// 定义导出单据接口处理
	ENDPOINT(API_M_GET, "/return/export", downloadFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ReturnQuery_r, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execDownloadFile(userQuery, authObject->getPayload()));
	}

private:
	// 修改单据
	Uint64JsonVO::Wrapper execModifyReturn(const ReturnDTO_r::Wrapper& dto);
	// 执行单据
	Uint64JsonVO::Wrapper execExecuteReturn(const UInt64& id);
	// 删除单据
	Uint64JsonVO::Wrapper execRemoveReturn(const oatpp::List<UInt64>& ids);
	// 导出单据
	StringJsonVO::Wrapper execDownloadFile(const ReturnQuery_r::Wrapper& query, const PayloadDTO& payload);
	//
	StringJsonVO::Wrapper execDownloadFile_q(const ReturnQuery_r::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _RETURNCONTROLLER_H_