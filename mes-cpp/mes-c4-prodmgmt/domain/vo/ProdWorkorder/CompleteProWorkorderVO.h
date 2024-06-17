#pragma once

#ifndef _COMPLETEPROWORKORDER_VO_
#define _COMPLETEPROWORKORDER_VO_

#include "../../GlobalInclude.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/CompleteProWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class CompleteProWorkorderJsonVO : public JsonVO<CompleteProWorkorderDTO::Wrapper> {
	DTO_INIT(CompleteProWorkorderJsonVO, JsonVO<CompleteProWorkorderDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_COMPLETEPROWORKORDER_VO_