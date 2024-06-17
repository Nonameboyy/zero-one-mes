#pragma once
#ifndef _DETECTIONTEMPLATE_CONTROLLER_
#define _DETECTIONTEMPLATE_CONTROLLER_

#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/DetectionTemplate/DetectionTemplateDTO.h"
#include "../../domain/query/DetectionTemplate/DetectionTemplateQuery.h"
#include "../../domain/vo/DetectionTemplate/DetectionTemplateVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 修改检测模板 余晖
 */
class DetectionTemplateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DetectionTemplateController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述 
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("DetectionTemplate.modify.summary"), modifyDetectionTemplate, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/detection-template/modify", modifyDetectionTemplate, BODY_DTO(DetectionTemplateDTO::Wrapper, dto), execModifyDetectionTemplate(dto));

	//定义删除检测模板接口描述
	ENDPOINT_INFO(removeDetectionTemplate) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("detection_template.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("detection_template.fields.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/detection-template/delete/{template_id}", removeDetectionTemplate, PATH(UInt64, template_id), execRemoveDetectionTemplate(template_id));

	ENDPOINT_INFO(queryDetectionTemplateList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.get.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionTemplatePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "template_id", ZH_WORDS_GETTER("DetectionTemplate.field.template_id"), 18, false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_code", ZH_WORDS_GETTER("DetectionTemplate.field.template_code"), "QCT2022040", false);
		API_DEF_ADD_QUERY_PARAMS(String, "template_name", ZH_WORDS_GETTER("DetectionTemplate.field.template_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enable_flag", ZH_WORDS_GETTER("DetectionTemplate.field.enable_flag"), "Y", false);
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("DetectionTemplate.field.remark"), "", false);
	}

	ENDPOINT(API_M_GET, "/qc/detection-template/query-by-page", queryDetectionTemplateList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(templateListQuery, DetectionTemplateQuery, queryParams);
		// 呼叫执行函数
		API_HANDLER_RESP_VO(execQueryDetectionTemplateList(templateListQuery, authObject->getPayload()));
	}

	// 定义新增接口描述
	ENDPOINT_INFO(addDetectionTemplate) {
		// 定义接口标题 添加检测模板
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/qc/detection-template/add", addDetectionTemplate, BODY_DTO(DetectionTemplateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDetectionTemplate(dto));
	}

	//  定义获取检验模板详情接口描述
	ENDPOINT_INFO(queryDetecTempDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("DetectionTemplate.querydetectempdetails.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DetectionTemplatePageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "template_code", ZH_WORDS_GETTER("DetectionTemplate.field.template_code"), "", true);
	}
	//  定义获取检验模板详情接口处理
	ENDPOINT(API_M_GET, "/qc/detection-template/query-by-details", queryDetecTempDetails, QUERY(String, template_code), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDetecTempDetails(template_code, authObject->getPayload()));
	}

private:
	Uint64JsonVO::Wrapper execModifyDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto);

	//删除检测模板
	Uint64JsonVO::Wrapper execRemoveDetectionTemplate(const UInt64& template_id);

	DetectionTemplatePageJsonVO::Wrapper execQueryDetectionTemplateList(const DetectionTemplateQuery::Wrapper& query, const PayloadDTO& payload);
	// 新增数据
	Uint64JsonVO::Wrapper execAddDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto);
	//  获取检验模板详情
	DetectionTemplatePageJsonVO::Wrapper execQueryDetecTempDetails(const String& template_code, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DETECTIONTEMPLATE_CONTROLLER_