#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/19 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/materialinformation/MaterialInformationDTO.h"
#include "domain/query/materialinformation/MaterialInformationQuery.h"
#include "domain/vo/materialinformation/MaterialInformationVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MaterialInformationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MaterialInformationController);
	// 3 定义接口
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMaterialInformation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialinformation.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MaterialInformationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/rejection/material/query-product_reject-page", queryMaterialInformation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, MaterialInformationQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addMaterialInformation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("materialinformation.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/rejection/material/add-product_reject", addMaterialInformation, BODY_DTO(MaterialInformationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMaterialInformation(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("materialinformation.put.summary"), modifyMaterialInformation, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/material/mod-product_reject", modifyMaterialInformation, BODY_DTO(MaterialInformationDTO::Wrapper, dto), execModifyMaterialInformation(dto));


	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeMaterialInformation) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("materialinformation.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("materialinformation.field.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rejection/material/del-product_reject-by-rt_id/{rt_id}", removeMaterialInformation, PATH(UInt64, id), execRemoveMaterialInformation(id));
	
private:
	// 3.3 新增生产退料单行数据
	Uint64JsonVO::Wrapper execAddMaterialInformation(const MaterialInformationDTO::Wrapper& dto);
	// 3.3 修改生产退料单行数据
	Uint64JsonVO::Wrapper execModifyMaterialInformation(const MaterialInformationDTO::Wrapper& dto);

	// 3.3 分页查询生产退料单行
	MaterialInformationPageJsonVO::Wrapper execQuerySample(const MaterialInformationQuery::Wrapper& query, const PayloadDTO& payload);

	// 3.3 删除生产退料单行列表（支持批量删除）
	Uint64JsonVO::Wrapper execRemoveMaterialInformation(const UInt64& id);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_