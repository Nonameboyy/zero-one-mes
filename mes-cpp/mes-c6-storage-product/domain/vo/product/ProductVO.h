#pragma once
#ifndef _PRODUCTVO_H_
#define _PRODUCTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/product/ProductDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//����һ�����������б���ʾVO
class ProductTableJsonVO : public JsonVO<ProductPageDTO::Wrapper>
{
	// �����ʼ��
	DTO_INIT(ProductTableJsonVO, JsonVO< ProductPageDTO::Wrapper>);

public:
	ProductTableJsonVO() {
		this->data = {};
	}
};
//������ʾVO
class ProductDetailJsonVO : public JsonVO<ProductDetailDTO::Wrapper>
{
	// �����ʼ��
	DTO_INIT(ProductDetailJsonVO, JsonVO< ProductDetailDTO::Wrapper>);

public:
	ProductDetailJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
