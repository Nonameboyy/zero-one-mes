#pragma once
#ifndef _INSPECT_VO_
#define _INSPECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/LaiLiaoInspect/InspectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class InspectJsonVO : public JsonVO<InspectDTO::Wrapper> {
	DTO_INIT(InspectJsonVO, JsonVO<InspectDTO::Wrapper>);
};

class Inspect_detailJsonVO : public JsonVO<Inspect_detailDTO::Wrapper> {
	DTO_INIT(Inspect_detailJsonVO, JsonVO<Inspect_detailDTO::Wrapper>);
};

class Inspect_tableJsonVO : public JsonVO<Inspect_tableDTO::Wrapper> {
	DTO_INIT(Inspect_tableJsonVO, JsonVO<Inspect_tableDTO::Wrapper>);
};
/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class InspectPageJsonVO : public JsonVO<InspectPageDTO::Wrapper> {
	DTO_INIT(InspectPageJsonVO, JsonVO<InspectPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_INSPECT_VO_