#pragma once
#ifndef _storage_CONTROLLER_
#define _storage_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ServerInfo.h"
#include "domain/dto/storage/storageDTO.h"

#include "domain/query/storage/storageQuery.h"
#include "domain/vo/storage/storageVO.h"
//=======
#include "domain/query/storage/storageQuery.h"
#include "domain/vo/storage/storageVO.h"

#include "ExcelComponent.h"

//#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin

/**
 * 示例控制器，演示基础接口的使用
 */
class storageController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	//控制器访问入口
	API_ACCESS_DECLARE(storageController);
public:

	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("storage.put.summary"), modifystorage, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/storage/mod-storage", modifystorage, BODY_DTO(storageDTO::Wrapper, dto), execModifystorage(dto));

	// 定义删除单据接口描述 支持批量删除
	ENDPOINT_INFO(removestorage)
	{
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("storage.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("storage.field.id"), 1, true);
	}

	//定义删除单据接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/storage/del-storage-by-recpt_id/{recpt_id}", removestorage, PATH(UInt64, id), execRemovestorage(id));

	


	// 定义查询接口描述
	ENDPOINT_INFO(querystorage) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("storage.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(storageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("storage.field.id"), "RT20221115001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("storage.field.order"), "MO10023110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse", ZH_WORDS_GETTER("storage.field.warehouse"), "N", false);
	}

	//定义查询接口处理
	ENDPOINT(API_M_GET, "/storage/query-storage", querystorage, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, storageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerystorage(userQuery, authObject->getPayload()));

	}






private:
	// 删除产品入库单据单行列表（支持批量删除）
	Uint64JsonVO::Wrapper execRemovestorage(const UInt64& id);

	//修改产品入库单行数据
	Uint64JsonVO::Wrapper execModifystorage(const storageDTO::Wrapper& dto);

	//查询单据导出单据
	storagePageJsonVO::Wrapper execQuerystorage(const storageQuery::Wrapper& query, const PayloadDTO& payload);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End
#endif 