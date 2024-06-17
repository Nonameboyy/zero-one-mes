#pragma once
#ifndef _MATERIAL_VO_
#define _MATERIAL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/materialsInformation/MaterialDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialJsonVO : public JsonVO<MaterialDTO::Wrapper> {
	DTO_INIT(MaterialJsonVO, JsonVO<MaterialDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialPageJsonVO : public JsonVO<MaterialPageDTO::Wrapper> {
	DTO_INIT(MaterialPageJsonVO, JsonVO<MaterialPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MATERIAL_VO_