#pragma once

#ifndef _MODIFYPROWORKORDER_VO_
#define _MODIFYPROWORKORDER_VO_

#include "../../GlobalInclude.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ModifyProWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ModifyProWorkorderJsonVO : public JsonVO<ModifyProWorkorderDTO::Wrapper> {
	DTO_INIT(ModifyProWorkorderJsonVO, JsonVO<ModifyProWorkorderDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYPROWORKORDER_VO_