#pragma once

#ifndef _CONFIRMPROWORKORDER_VO_
#define _CONFIRMPROWORKORDER_VO_

#include "../../GlobalInclude.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ConfirmProWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ConfirmProWorkorderJsonVO : public JsonVO<ConfirmProWorkorderDTO::Wrapper> {
	DTO_INIT(ConfirmProWorkorderJsonVO, JsonVO<ConfirmProWorkorderDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_CONFIRMPROWORKORDER_VO_