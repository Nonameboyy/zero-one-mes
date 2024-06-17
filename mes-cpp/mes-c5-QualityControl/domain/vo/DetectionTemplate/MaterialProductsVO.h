#pragma once
#ifndef _MATERIALPRODUCTS_VO_
#define _MATERIALPRODUCTS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/DetectionTemplate/MaterialProductsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MaterialProductsJsonVO : public JsonVO<MaterialProductsDTO::Wrapper> {
	DTO_INIT(MaterialProductsJsonVO, JsonVO<MaterialProductsDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class MaterialProductsPageJsonVO : public JsonVO<MaterialProductsPageDTO::Wrapper> {
	DTO_INIT(MaterialProductsPageJsonVO, JsonVO<MaterialProductsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_VO_