#pragma once
#ifndef _APPROVALSTAGE_CONTROLLER_
#define _APPROVALSTAGE_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ApprovalStage/ApprovalStageVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ApprovalStage/ApprovalStageDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 生产报工
 */
class ApprovalStage : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ApprovalStage);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述，提交审批
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Approval.post.submi"), modifyAubmitForApproval, ApprovalStageVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodreport/modify1", modifyAubmitForApproval, BODY_DTO(ApprovalStageDTO::Wrapper, dto), execModifyAubmitForApproval(dto));

	// 3.1 定义修改接口描述，审批通过
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Approval.post.passed"), modifyApprovalPassed, ApprovalStageVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodreport/modify2", modifyApprovalPassed, BODY_DTO(ApprovalStageDTO::Wrapper, dto), execModifyApprovalPassed(dto));

	// 3.1 定义修改接口描述，审批不通过
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Approval.post.denied"), modifyApprovalNotPassed, ApprovalStageVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/prodmgmt/prodreport/modify3", modifyApprovalNotPassed, BODY_DTO(ApprovalStageDTO::Wrapper, dto), execModifyApprovalNotPassed(dto));

private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyAubmitForApproval(const ApprovalStageDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyApprovalPassed(const ApprovalStageDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyApprovalNotPassed(const ApprovalStageDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROWORKORDER_CONTROLLER_