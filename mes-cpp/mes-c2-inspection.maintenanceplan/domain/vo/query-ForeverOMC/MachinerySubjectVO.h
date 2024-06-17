#ifndef _MACHINERY_SUBJECT_VO_
#define _MACHINERY_SUBJECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/MachinerySubjectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养设备列表显示JsonVO，用于响应给客户端的Json对象
*/
class MachinerySubjectJsonVO : public JsonVO<MachinerySubjectDTO::Wrapper> {
	DTO_INIT(MachinerySubjectJsonVO, JsonVO<MachinerySubjectDTO::Wrapper>);
};

/**
* 点检/保养设备列表分页显示JsonVO，用于响应给客户端的Json对象
*/
class MachinerySubjectPageJsonVO : public JsonVO<MachinerySubjectPageDTO::Wrapper> {
	DTO_INIT(MachinerySubjectPageJsonVO, JsonVO<MachinerySubjectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_SUBJECT_VO_