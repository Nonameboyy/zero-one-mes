#pragma once
#ifndef _RELATEPTO_VO_H_
#define _RELATEPTO_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/process/RelateProDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加工艺关联产品显示JsonVO，用于响应给客户端的Json对象
 */
class AddRelateProJsonVO : public JsonVO<AddRelateProDTO::Wrapper>
{
	DTO_INIT(AddRelateProJsonVO, JsonVO<AddRelateProDTO::Wrapper>);
};

/**
 * 修改工艺关联产品显示JsonVO，用于响应给客户端的Json对象
 */
class ModRelateProJsonVO : public JsonVO<ModRelateProDTO::Wrapper>
{
	DTO_INIT(ModRelateProJsonVO, JsonVO<ModRelateProDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RELATEPTO_VO_