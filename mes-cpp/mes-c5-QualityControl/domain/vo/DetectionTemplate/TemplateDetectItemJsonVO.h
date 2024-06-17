#pragma once
#ifndef _TEMPLATEDETECTITEM_VO_
#define _TEMPLATEDETECTITEM_VO_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/TemplateDetectItemDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


// 显示JsonVO，用于响应给客户端的检测模板检测项的Json对象
class TemplateDetectItemJsonVO : public JsonVO<TemplateDetectItemDTO::Wrapper> {
	DTO_INIT(TemplateDetectItemJsonVO, JsonVO<TemplateDetectItemDTO::Wrapper>);
};

// 分页显示JsonVO，用于响应给客户端的检测模板检测项的Json对象
class TemplateDetectItemPageJsonVO : public JsonVO<TemplateDetectItemPageDTO::Wrapper> {
	DTO_INIT(TemplateDetectItemPageJsonVO, JsonVO<TemplateDetectItemPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPLATEDETECTITEM_VO_