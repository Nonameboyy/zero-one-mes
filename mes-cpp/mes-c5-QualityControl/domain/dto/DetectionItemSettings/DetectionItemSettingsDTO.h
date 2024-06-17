#pragma once
#ifndef _DETECTIONITEMSETTINGS_DTO_
#define _DETECTIONITEMSETTINGS_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DetectionItemSettingsDTO : public oatpp::DTO
{
	DTO_INIT(DetectionItemSettingsDTO, DTO);
	//id
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.id");
	}
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.code");
	}
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.name");
	}
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.type");
	}
	DTO_FIELD(String, tool);
	DTO_FIELD_INFO(tool) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.tool");
	}
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.detectionitemsettings.domain.remark");
	}
};

class DetectionItemSettingsPageDTO :public PageDTO<DetectionItemSettingsDTO::Wrapper>
{
	DTO_INIT(DetectionItemSettingsPageDTO, PageDTO<DetectionItemSettingsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETECTIONITEMSETTINGS_DTO_
