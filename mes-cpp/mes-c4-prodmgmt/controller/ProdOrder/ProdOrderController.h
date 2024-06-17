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
#ifndef _PRODORDER_CONTROLLER_
#define _PRODORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Prodorder/ProdOrderQuery.h"
#include "domain/dto/ProdOrder/ProdOrderDTO.h"
#include "domain/vo/ProdOrder/ProdOrderVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 生产任务查询控制器，基础接口的使用
 */
class ProdOrderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ProdOrderController);

	// 3 定义接口

public:
	// 3.1 定义查询生产任务列表接口描述
	ENDPOINT_INFO(queryProdOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.get.summary"));
		//API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prod.get.summary"), ProdOrderPageJsonVO::Wrapper);
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdOrderPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "task_name", ZH_WORDS_GETTER("prod.field.taskName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workstation_name", ZH_WORDS_GETTER("prod.field.workstationName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "process_name", ZH_WORDS_GETTER("prod.field.processName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("prod.field.startTime"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("prod.field.endTime"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/prodmgmt/prodschedule/querylist", queryProdOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ProdOrderQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProdOrder(userQuery, authObject->getPayload()));
	}

	/*
	// 3.1 定义查询生产任务列表树接口描述
	ENDPOINT_INFO(queryTreeProdOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.getTree.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdOrderQueryTreeJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "task_name", ZH_WORDS_GETTER("prod.field.taskName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workstation_name", ZH_WORDS_GETTER("prod.field.workstationName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "process_name", ZH_WORDS_GETTER("prod.field.processName"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("prod.field.startTime"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("prod.field.endTime"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/prodOrder/queryTree", queryTreeProdOrder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ProdOrderTreeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTreeProdOrder(userQuery, authObject->getPayload()));
	}
	//*/

	// 定义查询用户菜单接口端点描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("prod.getTree.summary"), queryTreeProdOrder, ProdOrderQueryTreeJsonVO::Wrapper);
	// 定义查询用户菜单接口端点处理
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/prodmgmt/prodschedule/querytree", queryTreeProdOrder, execQueryTreeProdOrder(authObject->getPayload()))
	
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addProdOrder) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("prod.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProdOrderAddJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/prodmgmt/prodschedule/add", addProdOrder, BODY_DTO(ProdOrderDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddProdOrder(dto));
	}

private:
	// 3.3 分页查询列表
	ProdOrderPageJsonVO::Wrapper execQueryProdOrder(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 分页查询列表树
	//ProdOrderQueryTreeJsonVO::Wrapper execQueryTreeProdOrder(const ProdOrderTreeQuery::Wrapper& query, const PayloadDTO& payload);
	ProdOrderQueryTreeJsonVO::Wrapper execQueryTreeProdOrder(const PayloadDTO& payload);
	// 3.3 添加生产任务
	//Uint64JsonVO::Wrapper execAddProdOrder(const ProdOrderDTO::Wrapper& dto);
	ProdOrderAddJsonVO::Wrapper execAddProdOrder(const ProdOrderDTO::Wrapper& dto);

	// 3.3 演示修改数据
	//Uint64JsonVO::Wrapper execModifyProdOrder(const ProdOrderDTO::Wrapper& dto);
	// 3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveProdOrder(const UInt64& id);
	// 3.3 测试声明式服务调用1
	//ProdOrderJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	// 3.3 测试声明式服务调用2
	//ProdOrderPageJsonVO::Wrapper execQueryAll(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PRODORDER_CONTROLLER_