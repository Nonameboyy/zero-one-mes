#pragma once
#ifndef _product_VO_
#define _product_VO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../dto/document/productDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 退料列表显示VO
 */
class ProductJsonVO : public JsonVO<ProductDTO::Wrapper> {
	DTO_INIT(ProductJsonVO, JsonVO<ProductDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ProductPageJsonVO : public JsonVO<ProductPageDTO::Wrapper> {
	DTO_INIT(ProductPageJsonVO, JsonVO<ProductPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // vo