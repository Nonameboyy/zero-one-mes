#pragma once
#ifndef _PRODWORKORDERBOMLIST_VO_
#define _PRODWORKORDERBOMLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/ProdWorkorderBomListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��������BOM����б���ʾJsonVO
 */
class ProdWorkorderBomListJsonVO : public JsonVO<ProdWorkorderBomListDTO::Wrapper> {
	DTO_INIT(ProdWorkorderBomListJsonVO, JsonVO<ProdWorkorderBomListDTO::Wrapper>);
};

/**
 * ��ȡ��������BOM�б��ҳ��ʾJsonVO
 */
class ProdWorkorderBomListPageJsonVO : public JsonVO<ProdWorkorderBomListPageDTO::Wrapper> {
	DTO_INIT(ProdWorkorderBomListPageJsonVO, JsonVO<ProdWorkorderBomListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PRODWORKORDERBOMLIST_VO_