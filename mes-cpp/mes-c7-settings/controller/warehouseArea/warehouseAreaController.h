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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehouseArea/warehouseAreaQuery.h"
#include "domain/dto/warehouseArea/warehouseAreaDTO.h"
#include "domain/vo/warehouseArea/warehouseAreaVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 库区管理控制器
 */
class warehouseAreaController : public oatpp::web::server::api::ApiController //继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(warehouseAreaController);
	//定义接口
public:
	// 1.1 定义查询接口描述:接口名为queryWarehouseArea
	ENDPOINT_INFO(queryWarehouseArea) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse-area.query.summary"));//"分页查询库区数据"
		// 定义默认授权参数（访问接口需要身份验证,下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(warehouseAreaPageJsonVO);
		// 定义分页查询参数描述:端点支持分页查询-提供分页功能所需的标准参数
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述 注意！和query里定义的名称相同,设置为非必须参数,则可以展示出全部库区
		API_DEF_ADD_QUERY_PARAMS(String, "warehouseAreaName", ZH_WORDS_GETTER("warehouse-area.field.name"),"default name",false);
	}
	// 1.2 定义查询接口处理:路由到URL/warehouseArea找到queryWarehouseArea端点,产生查询请求queryParams
	ENDPOINT(API_M_GET, "/settings/location/query-warehouse_location-page", queryWarehouseArea, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为WarehouseAreaQuery领域模型
		API_HANDLER_QUERY_PARAM(query, WarehouseAreaQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryWarehouseArea(query));
	}

	//2.1定义新增库区接口描述
	ENDPOINT_INFO(addWarehouseArea){
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehouse-area.post.summary"));//"新增一个库区数据"
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 2.2 定义新增接口处理 注意！！！！！这里虽然传了库区id,但具体实现没有传入库区id,而是按照数据库自增方式生成库区id
	ENDPOINT(API_M_POST, "/settings/location/add-warehouse_location", addWarehouseArea, BODY_DTO(warehouseAreaListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddWarehouseArea(dto));
	}

	// 3.1 定义修改库区接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("warehouse-area.put.summary"), modifyWarehouseArea, Uint64JsonVO::Wrapper);
	// 3.2 定义修改库区接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/location/mod-warehouse_location", modifyWarehouseArea, BODY_DTO(warehouseAreaListDTO::Wrapper, dto), execModifyWarehouseArea(dto));

	//// 4.1 定义删除接口描述
	//ENDPOINT_INFO(removeWarehouseArea) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("warehouse-area.delete.summary"), Uint64JsonVO::Wrapper);
	//	// 定义其他路径参数说明:注意此处参数名要与DTO里的属于对应,默认值=1,require=true
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "area_id", ZH_WORDS_GETTER("warehouse-area.field.id"), 1, true);
	//}
	//// 4.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/warehouseArea-settings/del-warehouseArea-by/{area_id}", removeWarehouseArea, PATH(UInt64, area_id), execRemoveWarehouseArea(area_id));
	// 4.1 定义删除接口描述
	ENDPOINT_INFO(removeWarehouseArea) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("warehouse-area.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// 4.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/location/del-warehouse_location-by-location_id/{location_id}", removeWarehouseArea, BODY_DTO(List<UInt64>,ids), execRemoveWarehouseArea(ids));

	
private:
	// 1.3 分页查询数据
	warehouseAreaPageJsonVO::Wrapper execQueryWarehouseArea(const WarehouseAreaQuery::Wrapper& query);
	// 2.3新增库区数据
	Uint64JsonVO::Wrapper execAddWarehouseArea(const warehouseAreaListDTO::Wrapper& dto);
	// 3.3修改库区数据
	Uint64JsonVO::Wrapper execModifyWarehouseArea(const warehouseAreaListDTO::Wrapper& dto);
	// 4.3删除库区数据
	Uint64JsonVO::Wrapper execRemoveWarehouseArea(const List<UInt64>& ids);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_