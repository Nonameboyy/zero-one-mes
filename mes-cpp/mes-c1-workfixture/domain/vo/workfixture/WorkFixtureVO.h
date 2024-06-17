#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具的Json显示对象，可分页，用于相应给客户端的Json对象
 */
class WorkFixtureJsonVO : public JsonVO<WorkFixturePageDTO::Wrapper>
{
	DTO_INIT(WorkFixtureJsonVO, JsonVO<WorkFixturePageDTO::Wrapper>);
};

/**
 * 单条工装夹具详情的显示对象（无分页）
 */
class WorkFixtureDetailJsonVO : public JsonVO<WorkFixtureDTO::Wrapper>
{
	DTO_INIT(WorkFixtureDetailJsonVO, JsonVO<WorkFixturePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)