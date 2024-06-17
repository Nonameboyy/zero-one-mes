#pragma once
#ifndef _DETECTIONTEMPLATE_DTO_
#define _DETECTIONTEMPLATE_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 检测模板DTO
 */
class DetectionTemplateDTO : public oatpp::DTO {
	DTO_INIT(DetectionTemplateDTO, DTO);
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

/**
 * 检测模板分页传输对象
 */
class DetectionTemplatePageDTO : public PageDTO<DetectionTemplateDTO::Wrapper> {
	DTO_INIT(DetectionTemplatePageDTO, PageDTO<DetectionTemplateDTO::Wrapper>);
};

#include OATPP_CODEGEN_BEGIN(DTO)
#endif // !_DETECTIONTEMPLATE_DTO_
