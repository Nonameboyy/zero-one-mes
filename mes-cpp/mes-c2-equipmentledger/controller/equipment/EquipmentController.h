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
#ifndef _EQUIPMENTCONTROLLER_H_
#define _EQUIPMENTCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/vo/equipment/EquipmentVO.h"
#include "domain/query/equipment/EquipmentQuery.h"
#include "domain/vo/BaseJsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class EquipmentController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(EquipmentController);
public:
	// 1 定义设备列表查询接口描述
	ENDPOINT_INFO(queryEquipment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
	
		//设备编码
		API_DEF_ADD_QUERY_PARAMS(String, "eCode", ZH_WORDS_GETTER("equipment.fields.ecode"), "M0066", false);
		//设备名称
		API_DEF_ADD_QUERY_PARAMS(String, "eName", ZH_WORDS_GETTER("equipment.fields.ename"), "TextileMachinery", false);
	}
	// 1 定义设备列表查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/query-equipment", queryEquipment, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, EquipmentQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execEquipment(query));
	}

	// 2 定义设备详情查询接口描述
	ENDPOINT_INFO(queryEquipmentDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EquipmentDetailJsonVO);
		// 定义其他查询参数描述
		
		//设备ID
		API_DEF_ADD_QUERY_PARAMS(UInt64, "eId", ZH_WORDS_GETTER("equipment.fields.id"),217, true);
	}
	// 2 定义设备详情查询接口处理
	ENDPOINT(API_M_GET, "/equipment-ledger/equip/query-detail", queryEquipmentDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, EquipmentDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execEquipmentDetail(query));
	}

	// 3 定义新增接口描述
	ENDPOINT_INFO(addEquipment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3 定义新增接口处理
	ENDPOINT(API_M_POST, "/equipment-ledger/equip/add-equipment", addEquipment, BODY_DTO(addEquipmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddEquipment(dto, authObject->getPayload()));
	}

	//4 定义修改设备端点描述
	ENDPOINT_INFO(modifyEquipment) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipment.query.summary3"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 4定义修改设备端点处理
	ENDPOINT(API_M_PUT, "/equipment-ledger/equip/modify-equipment", modifyEquipment, BODY_DTO(modifyEquipmentDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {

		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeModifyEquipment(dto, authObject->getPayload()));
	}

	
	
	

private:
	//获取设备列表（条件+分页）
	EquipmentPageJsonVO::Wrapper execEquipment(const EquipmentQuery::Wrapper& query);
	//获取设备详情
	EquipmentDetailJsonVO::Wrapper execEquipmentDetail(const EquipmentDetailQuery::Wrapper& query);
	//增加设备
	Uint64JsonVO::Wrapper execAddEquipment(const addEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	//修改设备
	Uint64JsonVO::Wrapper executeModifyEquipment(const modifyEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif 

