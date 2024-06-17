#pragma once
#ifndef _APPROVALSTAGEDTO_DAO_
#define _APPROVALSTAGEDTO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ApprovalStage/ApprovalStageDO.h"

/**
 * 示例表数据库操作实现
 */
class ApprovalStageDAO : public BaseDAO
{
public:
	// 提交审批
	int SubmitForApproval(const ApprovalStageDO& uObj);
	//审批通过
	int ApprovalPassed(const ApprovalStageDO& uObj);
	//审批不通过
	int ApprovalNotPassed(const ApprovalStageDO& uObj);
};
#endif // !_APPROVALSTAGEDTO_DAO_

