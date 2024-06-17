#pragma once
#ifndef _SINGLE_VO_
#define _SINGLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Single_Defect/Single_Defect_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示检测项JsonVO，用于响应给客户端的Json对象
 */
class SingleJsonVO : public JsonVO<SingleDTO::Wrapper> {
	DTO_INIT(SingleJsonVO, JsonVO<SingleDTO::Wrapper>);
};

/**
 * 分页检测项显示JsonVO，用于响应给客户端的Json对象
 */
class SinglePageJsonVO : public JsonVO<SinglePageDTO::Wrapper> {
	DTO_INIT(SinglePageJsonVO, JsonVO<SinglePageDTO::Wrapper>);
};

/**
 * 显示缺陷JsonVO，用于响应给客户端的Json对象
 */
class DefectJsonVO : public JsonVO<DefectDTO::Wrapper> {
	DTO_INIT(DefectJsonVO, JsonVO<DefectDTO::Wrapper>);
};

/**
 * 分页显示缺陷JsonVO，用于响应给客户端的Json对象
 */
class DefectPageJsonVO : public JsonVO<DefectPageDTO::Wrapper> {
	DTO_INIT(DefectPageJsonVO, JsonVO<DefectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SINGLE_VO_
