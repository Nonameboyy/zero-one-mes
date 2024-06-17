#ifndef _DELETEPLANSUBJECT_VO_
#define _DELETEPLANSUBJECT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/deletePlanSubject/DeletePlanSubjectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养 显示JsonVO，用于响应给客户端的Json对象
*/
class DeletePlanQueryJsonVO : public JsonVO<DeletePlanQueryDTO::Wrapper> {
	DTO_INIT(DeletePlanQueryJsonVO, JsonVO<DeletePlanQueryDTO::Wrapper>);
};

class DeletePlanSubjectQueryJsonVO : public JsonVO<DeletePlanSubjectQueryDTO::Wrapper> {
	DTO_INIT(DeletePlanSubjectQueryJsonVO, JsonVO<DeletePlanSubjectQueryDTO::Wrapper>);
};

class DeletePlanMachineryQueryJsonVO : public JsonVO<DeletePlanMachineryQueryDTO::Wrapper> {
	DTO_INIT(DeletePlanMachineryQueryJsonVO, JsonVO<DeletePlanMachineryQueryDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_PLAN_VO_
