#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _CREATEVO_H_
#define _CREATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureTypeCreateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class WorkFixtureTypeCreateJsonVO : public JsonVO<WorkFixtureTypeCreateDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeCreateJsonVO, JsonVO<WorkFixtureTypeCreateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CREATEVO_H_