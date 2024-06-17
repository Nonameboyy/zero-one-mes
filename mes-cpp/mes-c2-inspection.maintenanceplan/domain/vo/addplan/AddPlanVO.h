#pragma once
#pragma once
#ifndef _ADDPLANVO_H_
#define _ADDPLANVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/addplan/AddPlanDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个项目列表显示VO
 */
class AddPlanJsonVO : public JsonVO<oatpp::List<AddPlanDTO::Wrapper>>
{
	DTO_INIT(AddPlanJsonVO, JsonVO<oatpp::List<AddPlanDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_