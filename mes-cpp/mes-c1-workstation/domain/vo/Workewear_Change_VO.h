#pragma once

#ifndef _WORKWEAR_CHANGE_VO_H_
#define _WORKWEAR_CHANGE_VO_H_

#include "../../GlobalInclude.h"
#include "../dto/Change_Workwear_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class ChangeworkwearListJsonVO : public JsonVO<ChangeWorkwearDTO::Wrapper>
{
	DTO_INIT(ChangeworkwearListJsonVO, JsonVO<ChangeWorkwearDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_