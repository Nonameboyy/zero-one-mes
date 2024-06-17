#pragma once
#ifndef _ADDPRODWORKORDER_VO_
#define _ADDPRODWORKORDER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/AddProdWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增工单显示JsonVO，用于响应给客户端的Json对象
 */
class AddProdWorkorderJsonVO : public JsonVO<AddProdWorkorderDTO::Wrapper> {
	DTO_INIT(AddProdWorkorderJsonVO, JsonVO<AddProdWorkorderDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPRODWORKORDER_VO_