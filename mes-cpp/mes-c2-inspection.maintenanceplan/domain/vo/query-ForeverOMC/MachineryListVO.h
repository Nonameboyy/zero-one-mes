#ifndef _MACHINERY_LIST_VO_
#define _MACHINERY_LIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/MachineryListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养设备列表显示JsonVO，用于响应给客户端的Json对象
*/
class MachineryListJsonVO : public JsonVO<MachineryListDTO::Wrapper> {
	DTO_INIT(MachineryListJsonVO, JsonVO<MachineryListDTO::Wrapper>);
};

/**
* 点检/保养设备列表分页显示JsonVO，用于响应给客户端的Json对象
*/
class MachineryListPageJsonVO : public JsonVO<MachineryListPageDTO::Wrapper> {
	DTO_INIT(MachineryListPageJsonVO, JsonVO<MachineryListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_LIST_VO_