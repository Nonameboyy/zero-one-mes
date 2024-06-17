#pragma once
#ifndef _PRODWORKORDERINFO_VO_
#define _PRODWORKORDERINFO_VO_
#include "../../GlobalInclude.h"
#include "../../dto/ProdWorkorder/ProdWorkorderInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取生产工单详情显示JsonVO，用于响应给客户端的Json对象
 */
class ProdWorkorderInfoJsonVO : public JsonVO<ProdWorkorderInfoDTO::Wrapper> {
	DTO_INIT(ProdWorkorderInfoJsonVO, JsonVO<ProdWorkorderInfoDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PRODWORKORDERINFO_VO_
