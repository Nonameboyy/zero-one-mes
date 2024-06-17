#pragma once
#ifndef _PRODUCTVO_H_
#define _PRODUCTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/product/ProductDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//定义一个生产领料列表显示VO
class ProductTableJsonVO : public JsonVO<ProductPageDTO::Wrapper>
{
	// 定义初始化
	DTO_INIT(ProductTableJsonVO, JsonVO< ProductPageDTO::Wrapper>);

public:
	ProductTableJsonVO() {
		this->data = {};
	}
};
//详情显示VO
class ProductDetailJsonVO : public JsonVO<ProductDetailDTO::Wrapper>
{
	// 定义初始化
	DTO_INIT(ProductDetailJsonVO, JsonVO< ProductDetailDTO::Wrapper>);

public:
	ProductDetailJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
