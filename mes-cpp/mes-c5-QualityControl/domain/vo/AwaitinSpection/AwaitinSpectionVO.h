#pragma once

#ifndef _OASL_VO_
#define _OASL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/AwaitinSpection/AwaitinSpectionDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 用于响应给客户端的Json对象
 */                                         
class AwaitinSpectionJsonVO : public JsonVO<AwaitinSpectionDTO::Wrapper> {
public:
    DTO_INIT(AwaitinSpectionJsonVO, JsonVO<AwaitinSpectionDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class AwaitinSpectionPageJsonVO : public JsonVO<AwaitinSpectionPageDTO::Wrapper> {
public:
    DTO_INIT(AwaitinSpectionPageJsonVO, JsonVO<AwaitinSpectionPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
