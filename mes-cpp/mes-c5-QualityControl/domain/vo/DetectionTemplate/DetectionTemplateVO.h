#pragma once
#ifndef _DETECTIONTEMPLATE_VO_
#define _DETECTIONTEMPLATE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/DetectionTemplateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DetectionTemplateJsonVO : public JsonVO<DetectionTemplateDTO::Wrapper> {
	DTO_INIT(DetectionTemplateJsonVO, JsonVO<DetectionTemplateDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DetectionTemplatePageJsonVO : public JsonVO<DetectionTemplatePageDTO::Wrapper> {
	DTO_INIT(DetectionTemplatePageJsonVO, JsonVO<DetectionTemplatePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_VO_