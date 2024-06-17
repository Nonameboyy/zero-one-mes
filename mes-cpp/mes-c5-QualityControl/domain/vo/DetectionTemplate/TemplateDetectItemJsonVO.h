#pragma once
#ifndef _TEMPLATEDETECTITEM_VO_
#define _TEMPLATEDETECTITEM_VO_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/TemplateDetectItemDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


// ��ʾJsonVO��������Ӧ���ͻ��˵ļ��ģ�������Json����
class TemplateDetectItemJsonVO : public JsonVO<TemplateDetectItemDTO::Wrapper> {
	DTO_INIT(TemplateDetectItemJsonVO, JsonVO<TemplateDetectItemDTO::Wrapper>);
};

// ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵ļ��ģ�������Json����
class TemplateDetectItemPageJsonVO : public JsonVO<TemplateDetectItemPageDTO::Wrapper> {
	DTO_INIT(TemplateDetectItemPageJsonVO, JsonVO<TemplateDetectItemPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPLATEDETECTITEM_VO_