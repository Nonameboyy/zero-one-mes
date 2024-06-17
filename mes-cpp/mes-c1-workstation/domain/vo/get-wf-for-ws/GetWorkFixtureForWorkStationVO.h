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
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetWorkFixtureForWorkStationPageJsonVO : public JsonVO<GetWorkFixtureForWorkStationPageDTO::Wrapper>
{
	DTO_INIT(GetWorkFixtureForWorkStationPageJsonVO, JsonVO<GetWorkFixtureForWorkStationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
