#pragma once
#ifndef _APPROVALSTAGEDTO_VO_
#define _APPROVALSTAGEDTO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ApprovalStage/ApprovalStageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
	����������ʾJsonVO��������Ӧ���ͻ��˵�Json����
	
 */
class ApprovalStageVO : public JsonVO<ApprovalStageDTO::Wrapper> {
	DTO_INIT(ApprovalStageVO, JsonVO<ApprovalStageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPRODUCTIONREPORTLIST_VO_