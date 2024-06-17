#pragma once

#ifndef _DELETEPROWORKORDER_VO_
#define _DELETEPROWORKORDER_VO_

#include "../../GlobalInclude.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/DeleteProWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class DeleteProWorkorderJsonVO : public JsonVO<DeleteProWorkorderDTO::Wrapper> {
	DTO_INIT(DeleteProWorkorderJsonVO, JsonVO<DeleteProWorkorderDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEPROWORKORDER_VO_