#pragma once

#ifndef _PICK_VO_
#define _PICK_VO_

#include "../../GlobalInclude.h"
#include "../../dto/pick/PickDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PickJsonVO : public JsonVO<PickDTO::Wrapper> {
	DTO_INIT(PickJsonVO, JsonVO<PickDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PickPageJsonVO : public JsonVO<PickPageDTO::Wrapper> {
	DTO_INIT(PickPageJsonVO, JsonVO<PickPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PICK_VO_