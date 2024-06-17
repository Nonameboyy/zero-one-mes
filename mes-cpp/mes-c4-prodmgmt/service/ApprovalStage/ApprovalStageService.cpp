#include "stdafx.h"
#include "ApprovalStageService.h"
#include "../../domain/do/ApprovalStage/ApprovalStageDO.h"
#include "../../dao/ApprovalStage/ApprovalStageDAO.h"
// 提交审批
bool ApprovalStageService::submitForApproval(const ApprovalStageDTO::Wrapper& dto)
{
	// 组装DO数据
	ApprovalStageDO data;
	 	//data.setId(dto->id.getValue(0));
	 	//data.setName(dto->name.getValue(""));
	 	//data.setSex(dto->sex.getValue(""));
	 	//data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,c_record_id, record_id, c_status, status);
	//cout << data.getc_record_id() << endl;
		// 执行数据修改
	ApprovalStageDAO dao;
	return dao.SubmitForApproval(data) == 1;
}
//审批通过
bool ApprovalStageService::approvalPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// 组装DO数据
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, c_record_id, record_id, c_status, status);
		// 执行数据修改
		ApprovalStageDAO dao;
	return dao.ApprovalPassed(data) == 1;
}
//审批不通过
bool ApprovalStageService::approvalNotPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// 组装DO数据
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, c_record_id, record_id, c_status, status);
		// 执行数据修改
		ApprovalStageDAO dao;
	return dao.ApprovalNotPassed(data) == 1;
}
