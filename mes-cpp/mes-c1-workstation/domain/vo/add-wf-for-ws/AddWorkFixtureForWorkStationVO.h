#pragma once
#ifndef _WORKFIXTUREFORWORKSTATION_VO_H_
#define _WORKFIXTUREFORWORKSTATION_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/add-wf-for-ws/AddWorkFixtureForWorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class AddWorkFixtureForWorkStationJsonVO : public JsonVO<AddWorkFixtureForWorkStationDTO::Wrapper>
{
	DTO_INIT(AddWorkFixtureForWorkStationJsonVO, JsonVO<AddWorkFixtureForWorkStationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_