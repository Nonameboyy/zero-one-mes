
#pragma once
#ifndef _REJECT_VO_
#define _REJECT_VO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../dto/rejection/RejectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 退料列表显示VO
 */
class RejectJsonVO : public JsonVO<RejectTableDTO::Wrapper> {
	DTO_INIT(RejectJsonVO, JsonVO<RejectTableDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class RejectPageJsonVO : public JsonVO<RejectPageDTO::Wrapper> {
	DTO_INIT(RejectPageJsonVO, JsonVO<RejectPageDTO::Wrapper>);
};

//详细信息vo
class RejectDetailJsonVO :public JsonVO<RejectDetailDTO::Wrapper> {
	DTO_INIT(RejectDetailJsonVO, JsonVO<RejectDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // vo