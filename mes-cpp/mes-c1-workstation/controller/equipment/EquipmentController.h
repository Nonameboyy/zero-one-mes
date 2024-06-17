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
#ifndef _EQUIPMENT_CONTROLLER_
#define _EQUIPMENT_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/vo/equipment/EquipmentTypeTreeVO.h"
#include "../../domain/query/equipment/EquipmentQuery.h"
#include "../../domain/vo/equipment/EquipmentVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class EquipmentController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(EquipmentController);
	// 3 定义接口
public:	
	// 定义查询设备类型名称列表树接口端点描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipment.getEquipmentTypeTree.summary"), getEquipmentTypeTree, EquipmentTypeTreeVO::Wrapper);
	// 定义查询设备类型名称列表树接口端点处理
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/ws/equipment/getEquipmentTypeTree", getEquipmentTypeTree, executeGetEquipmentTypeTree(authObject->getPayload()));

	//获取设备列表(条件 + 分页)
		// 3.1 定义查询接口描述
	ENDPOINT_INFO(getEquipmentList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.getEquipmentList.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentPageVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "equimentCode", ZH_WORDS_GETTER("equipmentQuery.equimentCode"), "M0024", false);
		API_DEF_ADD_QUERY_PARAMS(String, "equimentName", ZH_WORDS_GETTER("equipmentQuery.equimentName"), "测试人员", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/ws/equipment/getEquipmentList", getEquipmentList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(equipmentQuery, EquipmentQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetEquipmentList(equipmentQuery, authObject->getPayload()));
	}

private:
	//获取设备类型名称树
	EquipmentTypeTreeVO::Wrapper executeGetEquipmentTypeTree(const PayloadDTO& payload);
	// 3.3 设备分页查询数据
	EquipmentPageVO::Wrapper execGetEquipmentList(const EquipmentQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // EquipmentController