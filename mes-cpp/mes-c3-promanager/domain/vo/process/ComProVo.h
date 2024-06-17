#pragma once

#ifndef _COMPROJOSNVO_H_
#define _COMPROJOSNVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/process/ComProDTO.h"
#include "domain/dto/set/ProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//修改
/**
 * 组成工序列表
 */
class ProJsonVO : public JsonVO<ComProPageDTO::Wrapper>
{
	//初始化
	DTO_INIT(ProJsonVO, JsonVO<ComProPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_PROJOSNVO_H_
