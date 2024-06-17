#pragma once
#ifndef _RawMaterialOp_VO_
#define _RawMaterialOp_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RawMaterialOp/RawMaterialOpDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class RawMaterialOpJsonVO : public JsonVO<RawMaterialOpDTO::Wrapper> {
	DTO_INIT(RawMaterialOpJsonVO, JsonVO<RawMaterialOpDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class RawMaterialOpPageJsonVO : public JsonVO<RawMaterialOpPageDTO::Wrapper> {
	DTO_INIT(RawMaterialOpPageJsonVO, JsonVO<RawMaterialOpPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 