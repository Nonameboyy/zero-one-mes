#pragma once

#ifndef _GETWORKFIXTUREFORWORKSTATION_VO_H_
#define _GETWORKFIXTUREFORWORKSTATION_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-wf-for-ws/GetWorkFixtureForWorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GetWorkFixtureForWorkStationJsonVO : public JsonVO<GetWorkFixtureForWorkStationDTO::Wrapper>
{
	DTO_INIT(GetWorkFixtureForWorkStationJsonVO, JsonVO<GetWorkFixtureForWorkStationDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class GetWorkFixtureForWorkStationPageJsonVO : public JsonVO<GetWorkFixtureForWorkStationPageDTO::Wrapper>
{
	DTO_INIT(GetWorkFixtureForWorkStationPageJsonVO, JsonVO<GetWorkFixtureForWorkStationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
