#pragma once
#ifndef _PRODWORKORDERBOMLIST_VO_
#define _PRODWORKORDERBOMLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/ProdWorkorderBomListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取生产工单BOM组成列表显示JsonVO
 */
class ProdWorkorderBomListJsonVO : public JsonVO<ProdWorkorderBomListDTO::Wrapper> {
	DTO_INIT(ProdWorkorderBomListJsonVO, JsonVO<ProdWorkorderBomListDTO::Wrapper>);
};

/**
 * 获取生产工单BOM列表分页显示JsonVO
 */
class ProdWorkorderBomListPageJsonVO : public JsonVO<ProdWorkorderBomListPageDTO::Wrapper> {
	DTO_INIT(ProdWorkorderBomListPageJsonVO, JsonVO<ProdWorkorderBomListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PRODWORKORDERBOMLIST_VO_