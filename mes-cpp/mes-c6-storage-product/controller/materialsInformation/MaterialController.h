#pragma once
#ifndef _MATERIAL_CONTROLLER_
#define _MATERIAL_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/materialsInformation/MaterialQuery.h"
#include "domain/dto/materialsInformation/MaterialDTO.h"
#include "domain/vo/materialsInformation/MaterialVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 物料信息接口的使用
 */
class MaterialController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MaterialController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMaterial) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Material.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MaterialPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "issue_id", ZH_WORDS_GETTER("Material.field.issue_id"), 1, false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/incoming/search", queryMaterial, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, MaterialQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMaterial(userQuery, authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addMaterial) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Material.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/incoming/add", addMaterial, BODY_DTO(MaterialDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMaterial(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Material.put.summary"), modifyMaterial, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming/change", modifyMaterial, BODY_DTO(MaterialDTO::Wrapper, dto), execModifyMaterial(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeMaterial) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Material.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("Material.field.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming/delete/{line_id}", removeMaterial, PATH(UInt64, line_id), execRemoveMaterial(line_id));

private:
	// 3.3 分页查询数据
	MaterialPageJsonVO::Wrapper execQueryMaterial(const MaterialQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 新增数据
	Uint64JsonVO::Wrapper execAddMaterial(const MaterialDTO::Wrapper& dto);
	// 3.3 修改数据
	Uint64JsonVO::Wrapper execModifyMaterial(const MaterialDTO::Wrapper& dto);
	// 3.3 删除数据
	Uint64JsonVO::Wrapper execRemoveMaterial(const UInt64& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MATERIAL_CONTROLLER_