#pragma once
#ifndef _WAREHOUSEMANAGEMENT_CONTROLLER_
#define _WAREHOUSEMANAGEMENT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/WarehouseManagement/WarehouseManagementQuery.h"
#include "domain/dto/WarehouseManagement/WarehouseManagementDTO.h"
#include "domain/vo/WarehouseManagement/WarehouseManagementVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，基础接口的使用
 */

class WarehouseManagementController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(WarehouseManagementController);
	// 3 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryWarehouseManagement) {
		// 定义接口标题 获取库存列表（条件+分页）
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehousemanagement.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WarehouseManagementPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("warehousemanagement.field.item_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("warehousemanagement.field.item_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "batch_code", ZH_WORDS_GETTER("warehousemanagement.field.batch_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("warehousemanagement.field.warehouse_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_code", ZH_WORDS_GETTER("warehousemanagement.field.vendor_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_name", ZH_WORDS_GETTER("warehousemanagement.field.vendor_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "expire_date", ZH_WORDS_GETTER("warehousemanagement.field.expire_date"), "", false);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/wm/inventory-on-hand/query-by-page", queryWarehouseManagement, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(warehousemanagementQuery, WarehouseManagementQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryWarehouseManagement(warehousemanagementQuery, authObject->getPayload()));
	}

	// 定义查询接口描述
	ENDPOINT_INFO(exportWarehouseManagement) {
		// 定义接口标题 获取库存列表（条件+分页）
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehousemanagement.export.summary"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("warehousemanagement.field.item_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("warehousemanagement.field.item_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "batch_code", ZH_WORDS_GETTER("warehousemanagement.field.batch_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("warehousemanagement.field.warehouse_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_code", ZH_WORDS_GETTER("warehousemanagement.field.vendor_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_name", ZH_WORDS_GETTER("warehousemanagement.field.vendor_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "expire_date", ZH_WORDS_GETTER("warehousemanagement.field.expire_date"), "", false);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_POST, "/wm/inventory-on-hand/export", exportWarehouseManagement, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(warehousemanagementQuery, WarehouseManagementQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execExportWarehouseManagement(warehousemanagementQuery));
	}

private:
	// 分页查询数据
	WarehouseManagementPageJsonVO::Wrapper execQueryWarehouseManagement(const WarehouseManagementQuery::Wrapper& query, const PayloadDTO& payload);
	// 导出
	StringJsonVO::Wrapper execExportWarehouseManagement(const WarehouseManagementQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WAREHOUSEMANAGEMENT_CONTROLLER_
