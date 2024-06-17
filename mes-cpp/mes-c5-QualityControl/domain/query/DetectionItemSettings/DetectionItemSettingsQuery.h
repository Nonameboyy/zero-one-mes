#pragma once
#ifndef _DETECTIONITEMSETTINGS_QUERY_
#define _DETECTIONITEMSETTINGS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DetectionItemSettingsQuery : public PageQuery
{
	DTO_INIT(DetectionItemSettingsQuery, PageQuery);
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
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETECTIONITEMSETTINGS_QUERY_

