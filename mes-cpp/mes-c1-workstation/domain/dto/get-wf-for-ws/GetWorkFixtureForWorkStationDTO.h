#pragma once

#ifndef _GETWORKSTATIONLISTDTO_H_
#define _GETWORKSTATIONLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GetWorkFixtureForWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(GetWorkFixtureForWorkStationDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, GetWFForWSTypeName, ZH_WORDS_GETTER("wf_for_ws.fields.typename"));
	API_DTO_FIELD_DEFAULT(UInt64, GetWFForWSAccount, ZH_WORDS_GETTER("wf_for_ws.fields.account"));
};


class GetWorkFixtureForWorkStationPageDTO : public PageDTO<GetWorkFixtureForWorkStationDTO::Wrapper>
{
	DTO_INIT(GetWorkFixtureForWorkStationPageDTO, PageDTO<GetWorkFixtureForWorkStationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_