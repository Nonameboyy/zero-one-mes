#pragma once
#ifndef __AREACONTROLLER_H__
#define __AREACONTROLLER_H__

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/storagearea/AreaDTO.h"
#include "domain/query/storagearea/AreaQuery.h"
#include "domain/vo/storagearea/AreaJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)
class AreaController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AreaController)
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryArea) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagearea.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AreaPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述	
		API_DEF_ADD_QUERY_PARAMS(Int64, "location_id", ZH_WORDS_GETTER("storagearea.fields.locationId"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_code", ZH_WORDS_GETTER("storagearea.fields.areacode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("storagearea.fields.areaname"), "", false);	
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_x", ZH_WORDS_GETTER("storagearea.fields.positionx"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_y", ZH_WORDS_GETTER("storagearea.fields.positiony"), 0, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "position_z", ZH_WORDS_GETTER("storagearea.fields.positionz"), 0, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/settings/area/query-warehouse_area-page", queryArea, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AreaQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryArea(userQuery,authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addArea) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storagearea.add.insert"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
		
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/settings/area/add-warehouse_area", addArea, BODY_DTO(AreaDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddArea(dto, authObject->getPayload()));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storagearea.modify.update"), modifyArea, Uint64JsonVO::Wrapper)
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/settings/area/mod-warehouse_area", modifyArea, BODY_DTO(AreaDTO::Wrapper, dto), execModifyArea(dto, authObject->getPayload()));

	// 3.1 定义删除接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storagearea.remove.delete"), removeArea, Uint64JsonVO::Wrapper)
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/settings/area/del-warehouse_area-by-area_id/{area_id}", removeArea, BODY_DTO(List<Int32>, idsdto), execRemoveArea(idsdto));

private:
	// 3.3 演示分页查询数据
	AreaPageJsonVO::Wrapper execQueryArea(const AreaQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveArea( const oatpp::List<Int32>& idsdto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif //__AREACONTROLLER_H__