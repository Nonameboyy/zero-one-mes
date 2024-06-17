#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _UPDATEVO_H_
#define _UPDATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureTypeUpdateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class WorkFixtureTypeUpdateJsonVO : public JsonVO<WorkFixtureTypeUpdateDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeUpdateJsonVO, JsonVO<WorkFixtureTypeUpdateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATEVO_H_