#pragma once
#ifndef _RawMaterialOp_CONTROLLER_
#define _RawMaterialOp_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ServerInfo.h"
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"

#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/vo/RawMaterialOp/RawMaterialOpVO.h"
//=======
#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/vo/RawMaterialOp/RawMaterialOpVO.h"

#include "ExcelComponent.h"

//#include "ApiHelper.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin

/**
 * 示例控制器，演示基础接口的使用
 */
class RawMaterialOpController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RawMaterialOpController);
	// 3 定义接口
public:

	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RawMaterialOp.put.summary"), modifyRawMaterialOp, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/mod-raw_material", modifyRawMaterialOp, BODY_DTO(RawMaterialOpDTO::Wrapper, dto), execModifyRawMaterialOp(dto));



	// 定义删除单据接口描述
	ENDPOINT_INFO(removeRawMaterialOp)
	{
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("RawMaterialOp.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("RawMaterialOp.field.id"), 1, true);
	}

	//定义删除单据接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rejection/del-raw_material-by-rt_id/{rt_id}", removeRawMaterialOp, PATH(UInt64, id), execRemoveRawMaterialOp(id));


	// 定义查询接口描述
	ENDPOINT_INFO(queryRawMaterialOp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RawMaterialOp.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RawMaterialOpJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("RawMaterialOp.field.id"), "RT20221115001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("RawMaterialOp.field.order"), "MO10023110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse", ZH_WORDS_GETTER("RawMaterialOp.field.warehouse"), "N", false);
	}

	//定义查询接口处理
	ENDPOINT(API_M_GET, "/rejection/query-raw_material", queryRawMaterialOp, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RawMaterialOpQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRawMaterialOp(userQuery, authObject->getPayload()));
		
		
	}






private:
	// 删除生产退料单行列表（支持批量删除）
	Uint64JsonVO::Wrapper execRemoveRawMaterialOp(const UInt64& id);

	// 3.3 修改生产退料单行数据
	Uint64JsonVO::Wrapper execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto);
	//查询单据导出单据
	RawMaterialOpPageJsonVO::Wrapper execQueryRawMaterialOp(const RawMaterialOpQuery::Wrapper& query, const PayloadDTO& payload);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End
#endif // _SAMPLE_CONTROLLER_