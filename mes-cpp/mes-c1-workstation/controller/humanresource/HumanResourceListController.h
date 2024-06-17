#pragma once
#ifndef _HUMANRESOURCELISTCONTROLLER_
#define _HUMANRESOURCELISTCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/humanresource/HumanResourceListQuery.h"
#include "domain/dto/humanresource/HumanResourceListDTO.h"
#include "domain/vo/humanresource/HumanResourceListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 人力资源控制器
 */
class HumanResourceListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(HumanResourceListController);
	// 3 定义接口
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryHumanResource) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(HumanResourceListPageVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "workstationId", ZH_WORDS_GETTER("post.fields.workstationid"), 1, false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/ws/huamnresource/query-humanresource-list", queryHumanResource, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, HumanResourceListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryHumanResourceList(query));
	}


	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addHumanResource) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("post.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ws/humanresource/add-hunmanresource-list", addHumanResource, BODY_DTO(HumanResourceListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddHumanResourceList(dto));
	}
	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("modify.summary"), modifyHumanResource, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ws/humanresource/modify-hunmanresource", modifyHumanResource, BODY_DTO(HumanResourceListDTO::Wrapper, dto), execModifyHumanResource(dto));

	// 定义删除接口描述
	ENDPOINT_INFO(removeHumanResource) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("remove.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "recordId", ZH_WORDS_GETTER("post.fields.recordid"), 1, true);
	}
	// 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/humanresource/remove-hunmanresource/{recordId}", removeHumanResource, PATH(UInt64, recordId), execRemoveHumanResource(recordId));

private:
	// 分页查询数据
	HumanResourceListPageVO::Wrapper execQueryHumanResourceList(const HumanResourceListQuery::Wrapper& query);
	// 新增数据
	Uint64JsonVO::Wrapper execAddHumanResourceList(const HumanResourceListDTO::Wrapper& dto);
	// 修改数据
	Uint64JsonVO::Wrapper execModifyHumanResource(const HumanResourceListDTO::Wrapper& dto);
	// 删除数据
	Uint64JsonVO::Wrapper execRemoveHumanResource(const UInt64& recordId);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 