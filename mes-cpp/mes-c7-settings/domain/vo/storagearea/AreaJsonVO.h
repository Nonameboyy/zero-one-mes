#pragma once
#ifndef __AREAJSONVO_H__
#define __AREAJSONVO_H__

#include "../../GlobalInclude.h"
#include "../../dto/storagearea/AreaDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 显示JsonVO，用于响应给客户端的Json对象
*/
class AreaJsonVO : public JsonVO<AreaDTO::Wrapper> {
	DTO_INIT(AreaJsonVO, JsonVO<AreaDTO::Wrapper>)
};
/*
* 示例分页显示JsonVO，用于响应给客户端的Json对象
*/
class AreaPageJsonVO : public JsonVO <AreaPageDTO::Wrapper>
{
	DTO_INIT(AreaPageJsonVO, JsonVO <AreaPageDTO::Wrapper>)

};

#include OATPP_CODEGEN_END(DTO)

#endif //__AREAJSONVO_H__