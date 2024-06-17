#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/17

*/
#ifndef _WORKFIXTURETYPELISTVO_H_
#define _WORKFIXTURETYPELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureTypeListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class WorkFixtureTypeListPageJsonVO : public JsonVO<WorkFixtureTypeListPageDTO::Wrapper>
{
	DTO_INIT(WorkFixtureTypeListPageJsonVO, JsonVO<WorkFixtureTypeListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKFIXTURETYPELISTVO_H_