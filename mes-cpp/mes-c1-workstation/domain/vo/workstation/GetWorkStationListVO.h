#pragma once

#ifndef _GETWORKSTATIONLIST_VO_H_
#define _GETWORKSTATIONLIST_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workstation/WorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetWorkStationListJsonVO : public JsonVO<GetWorkStationListDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListJsonVO, JsonVO<GetWorkStationListDTO::Wrapper>);
};

/**
 * ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetWorkStationListPageJsonVO : public JsonVO<GetWorkStationListPageDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListPageJsonVO, JsonVO<GetWorkStationListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_