#ifndef _MACHINERY_PLAN_VO_
#define _MACHINERY_PLAN_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/MachineryPlanDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养设备列表显示JsonVO，用于响应给客户端的Json对象
*/
class MachineryPlanJsonVO : public JsonVO<MachineryPlanDTO::Wrapper> {
	DTO_INIT(MachineryPlanJsonVO, JsonVO<MachineryPlanDTO::Wrapper>);
};

/**
* 点检/保养设备列表分页显示JsonVO，用于响应给客户端的Json对象
*/
class MachineryPlanPageJsonVO : public JsonVO<MachineryPlanPageDTO::Wrapper> {
	DTO_INIT(MachineryPlanPageJsonVO, JsonVO<MachineryPlanPageDTO::Wrapper>);
};

/**
* 点检/保养设备列表详情显示JsonVO，用于响应给客户端的Json对象
*/
class MachineryPlanDetailsJsonVO : public JsonVO<MachineryPlanDetailsDTO::Wrapper> {
	DTO_INIT(MachineryPlanDetailsJsonVO, JsonVO<MachineryPlanDetailsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_PLAN_VO_