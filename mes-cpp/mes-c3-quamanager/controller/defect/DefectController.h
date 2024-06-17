#pragma once
#ifndef _DEFECT_CONTROLLER_
#define _DEFECT_CONTROLLER_

#include "domain/dto/defect/DefectDTO.h"
#include "domain/dto/defect/DefectModifyDTO.h"
#include "domain/query/defect/QcDefectQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/defect/DefectVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 常见缺陷控制器
 */
class DefectController : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(DefectController);

public:
	// 1 获取缺陷列表（条件+分页）
	ENDPOINT_INFO(queryDefect) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DefectPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "defect_name", ZH_WORDS_GETTER("defect.field.defect_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "index_type", ZH_WORDS_GETTER("defect.field.index_type"), "APPEARANCE", false);
		API_DEF_ADD_QUERY_PARAMS(String, "defect_level", ZH_WORDS_GETTER("defect.field.defect_level"), "MIN", false);
	}
	ENDPOINT(API_M_GET, "/defect/get-list", queryDefect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, QcDefectQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDefect(userQuery, authObject->getPayload()));
	}

	// 2 添加缺陷
	ENDPOINT_INFO(addDefect) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("defect.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/defect/add-defect", addDefect, BODY_DTO(DefectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDefect(dto, authObject->getPayload()));
	}

	// 3 修改缺陷
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("defect.modify.summary"), modifyDefect, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(					 //
		API_M_PUT,								 //
		"/defect/modify-defect",				 //
		modifyDefect,							 //
		BODY_DTO(DefectModifyDTO::Wrapper, dto), //
		execModifyDefect(dto, authObject->getPayload())					 //
	);

	// 4 删除缺陷
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("defect.remove.summary"), removeDefect, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(			   //
		API_M_DEL,						   //
		"/defect/remove-defect/{id-list}", //
		removeDefect,					   //
		PATH(String, ids, "id-list"),	   //
		execRemoveDefect(ids)			   //
	);
	// 导出缺陷
	ENDPOINT_INFO(exportDefect)
	{
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("defect.export.summary"), Void);
	}
	ENDPOINT(												//
		API_M_POST,											//
		"/defect/export-defect",							//
		exportDefect,										//
		REQUEST(std::shared_ptr<IncomingRequest>, request), //
		API_HANDLER_AUTH_PARAME)
	{
		return execExportDefect(request);
	}
private:
	// 1 获取缺陷列表（条件+分页）
	DefectPageJsonVO::Wrapper execQueryDefect(const QcDefectQuery::Wrapper& query, const PayloadDTO& payload);
	// 2 添加缺陷
	Uint64JsonVO::Wrapper execAddDefect(const DefectDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3 修改缺陷
	Uint64JsonVO::Wrapper execModifyDefect(const DefectModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// 4 删除缺陷
	Uint64JsonVO::Wrapper execRemoveDefect(const String& ids);
	// 5 导出缺陷、
	std::shared_ptr<OutgoingResponse> execExportDefect(std::shared_ptr<IncomingRequest> request);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_