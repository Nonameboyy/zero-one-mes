#pragma once
#ifndef _product_VO_
#define _product_VO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../dto/document/productDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б���ʾVO
 */
class ProductJsonVO : public JsonVO<ProductDTO::Wrapper> {
	DTO_INIT(ProductJsonVO, JsonVO<ProductDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProductPageJsonVO : public JsonVO<ProductPageDTO::Wrapper> {
	DTO_INIT(ProductPageJsonVO, JsonVO<ProductPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // vo