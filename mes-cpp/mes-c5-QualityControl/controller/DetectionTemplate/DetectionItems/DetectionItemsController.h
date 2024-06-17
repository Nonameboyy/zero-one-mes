#pragma once
#ifndef _TEMPLATEDETECTITEM_CONTROLLER_
#define _TEMPLATEDETECTITEM_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/vo/DetectionTemplate/TemplateDetectItemJsonVO.h"
#include "../../../domain/dto/DetectionTemplate/TemplateDetectItemDTO.h"
#include "../../../domain/query/DetectionTemplate/TemplateDetectItemQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DetectionItemsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DetectionItemsController); // 控制器访问入口
public:
	ENDPOINT_INFO(queryTemplateDetectItem) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templatedetectitem.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TemplateDetectItemPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("templatedetectitem.field.template_id"), 1, true);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/qc/templatedetect-item/query-by-page", queryTemplateDetectItem, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, TemplateDetectItemQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTemplateDetectItem(query));
	}

	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("templatedetectitem.put.summary"), modifyTemplateDetectItem, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/templatedetect-item/modify", modifyTemplateDetectItem, BODY_DTO(TemplateDetectItemDTO::Wrapper, dto), execModifyTemplateDetectItem(dto));

	// 定义新增接口描述
	ENDPOINT_INFO(addTemplateDetectItem) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("templatedetectitem.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/qc/templatedetect-item/add", addTemplateDetectItem, BODY_DTO(TemplateDetectItemDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTemplateDetectItem(dto));
	}

	// 定义删除接口描述
	ENDPOINT_INFO(removeTemplateDetectItem) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("templatedetectitem.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("templatedetectitem.field.record_id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/templatedetect-item/remove", removeTemplateDetectItem, BODY_DTO(oatpp::List<UInt64>, record_ids), execRemoveTemplateDetectItem(record_ids));

private: // 定义接口的执行函数
	TemplateDetectItemPageJsonVO::Wrapper execQueryTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query); // 分页查询执行函数
	Uint64JsonVO::Wrapper execModifyTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execAddTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveTemplateDetectItem(const oatpp::List<UInt64>& record_ids);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_TEMPLATEDETECTITEM_CONTROLLER_
