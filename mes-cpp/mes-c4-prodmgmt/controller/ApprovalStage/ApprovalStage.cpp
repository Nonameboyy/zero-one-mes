#include "stdafx.h"
#include "ApprovalStage.h"
#include "../../service/ApprovalStage/ApprovalStageService.h"
#include "../ApiDeclarativeServicesHelper.h"
//执行数据修改
// 提交审批
Uint64JsonVO::Wrapper ApprovalStage::execModifyAubmitForApproval(const ApprovalStageDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ApprovalStageService service;
	// 执行数据修改
	if (service.submitForApproval(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}
//审批通过
Uint64JsonVO::Wrapper ApprovalStage::execModifyApprovalPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ApprovalStageService service;
	// 执行数据修改
	if (service.approvalPassed(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}
//审批不通过
Uint64JsonVO::Wrapper ApprovalStage::execModifyApprovalNotPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ApprovalStageService service;
	// 执行数据修改
	if (service.approvalNotPassed(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}