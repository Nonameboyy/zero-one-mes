#pragma once
#ifndef _DETECTIONTEMPLATE_QUERY_
#define _DETECTIONTEMPLATE_QUERY_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/DetectionTemplateDTO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class DetectionTemplateQuery : public PageQuery
{
	DTO_INIT(DetectionTemplateQuery, PageQuery);
	// 检测模板ID(唯一值)
	DTO_FIELD(UInt64, template_id);
	DTO_FIELD_INFO(template_id) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_id");
	}
	// 检测模板编号
	DTO_FIELD(String, template_code);
	DTO_FIELD_INFO(template_code) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_code");
	}
	// 检测模板名称
	DTO_FIELD(String, template_name);
	DTO_FIELD_INFO(template_name) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.template_name");
	}
	// 产品编码
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.item_code");
	}
	// 产品名称
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.item_name");
	}
	// 检测种类
	DTO_FIELD(String, qc_types);
	DTO_FIELD_INFO(qc_types) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.qc_types");
	}
	// 是否启用
	DTO_FIELD(String, enable_flag);
	DTO_FIELD_INFO(enable_flag) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.enable_flag");
	}
	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("DetectionTemplate.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROCESSINSPECTION_QUERY_