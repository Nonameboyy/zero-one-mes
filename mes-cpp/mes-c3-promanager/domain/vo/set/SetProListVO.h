#pragma once
#ifndef _SETPROLIST_VO_
#define _SETPROLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/set/SetProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取工序步骤列表（条件+分页）
 */
class SetProListJsonVO : public JsonVO<SetProListDTO::Wrapper> {
	DTO_INIT(SetProListJsonVO, JsonVO<SetProListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class SetProListPageJsonVO : public JsonVO<SetProListPageDTO::Wrapper> {
	DTO_INIT(SetProListPageJsonVO, JsonVO<SetProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SETPROSTEPLIST_VO_