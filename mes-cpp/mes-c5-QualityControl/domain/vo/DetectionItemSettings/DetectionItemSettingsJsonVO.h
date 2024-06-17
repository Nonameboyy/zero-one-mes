#pragma once
#ifndef _DETECTIONITEMSETTINGS_VO_
#define _DETECTIONITEMSETTINGS_VO_


#include "../../GlobalInclude.h"
#include "../../dto/DetectionItemSettings/DetectionItemSettingsDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DetectionItemSettingsJsonVO :public JsonVO<DetectionItemSettingsDTO::Wrapper> {
	DTO_INIT(DetectionItemSettingsJsonVO, JsonVO < DetectionItemSettingsDTO::Wrapper >);
};

class DetectionItemSettingsPageJsonVO : public JsonVO<DetectionItemSettingsPageDTO::Wrapper> {
	DTO_INIT(DetectionItemSettingsPageJsonVO, JsonVO<DetectionItemSettingsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETECTIONITEMSETTINGS_VO_
