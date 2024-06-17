#pragma once
#ifndef _GETPRODUCTIONREPORTLIST_DTO_
#define _GETPRODUCTIONREPORTLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改状态
 */
class ApprovalStageDTO : public oatpp::DTO
{
	DTO_INIT(ApprovalStageDTO, DTO);
	//记录id/生产工单编号;record_id;bigint
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("Approval.post.id");
	}
	//报工状态;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("Approval.post.remark");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 