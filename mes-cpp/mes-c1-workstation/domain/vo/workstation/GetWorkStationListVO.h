#pragma once

#ifndef _GETWORKSTATIONLIST_VO_H_
#define _GETWORKSTATIONLIST_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workstation/WorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class GetWorkStationListJsonVO : public JsonVO<GetWorkStationListDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListJsonVO, JsonVO<GetWorkStationListDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class GetWorkStationListPageJsonVO : public JsonVO<GetWorkStationListPageDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListPageJsonVO, JsonVO<GetWorkStationListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_