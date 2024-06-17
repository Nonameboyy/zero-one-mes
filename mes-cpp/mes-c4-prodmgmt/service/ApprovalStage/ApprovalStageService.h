#pragma once
#ifndef _APPROVALSTAGEDTO_SERVICE_
#define _APPROVALSTAGEDTO_SERVICE_
#include <list>
#include "domain/vo/ApprovalStage/ApprovalStageVO.h"
#include "domain/dto/ApprovalStage/ApprovalStageDTO.h"

/**
	修改审批状态服务实现
 */
class ApprovalStageService
{
public:
	// 提交审批
	bool submitForApproval(const ApprovalStageDTO::Wrapper& dto);
	//审批通过
	bool approvalPassed(const ApprovalStageDTO::Wrapper& dto);
	//审批不通过
	bool approvalNotPassed(const ApprovalStageDTO::Wrapper& dto);

};

#endif // !_APPROVALSTAGEDTO_SERVICE_


