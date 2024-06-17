#pragma once
#ifndef _PROMATERIAL_VO_H_
#define _PROMATERIAL_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProMaterialDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取产品制程物料显示JsonVO，用于响应给客户端的Json对象
 */
class ProMaterialJsonVO : public JsonVO<ProMaterialDTO::Wrapper>
{
	DTO_INIT(ProMaterialJsonVO, JsonVO<ProMaterialDTO::Wrapper>);

};

/**
 * 获取产品制程物料分页显示JsonVO，用于响应给客户端的Json对象
 */
class ProMaterialPageJsonVO : public JsonVO<ProMaterialPageDTO::Wrapper>
{
	DTO_INIT(ProMaterialPageJsonVO, JsonVO<ProMaterialPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROMATERIAL_VO_