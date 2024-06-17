#pragma once
#ifndef _MATERIALPRODUCTS_VO_
#define _MATERIALPRODUCTS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/MaterialProductsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialProductsJsonVO : public JsonVO<MaterialProductsDTO::Wrapper> {
	DTO_INIT(MaterialProductsJsonVO, JsonVO<MaterialProductsDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MaterialProductsPageJsonVO : public JsonVO<MaterialProductsPageDTO::Wrapper> {
	DTO_INIT(MaterialProductsPageJsonVO, JsonVO<MaterialProductsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_VO_