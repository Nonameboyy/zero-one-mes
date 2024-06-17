#pragma once
#ifndef _GETPRODUCTIONREPORTLIST_DTO_
#define _GETPRODUCTIONREPORTLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸�״̬
 */
class ApprovalStageDTO : public oatpp::DTO
{
	DTO_INIT(ApprovalStageDTO, DTO);
	//��¼id/�����������;record_id;bigint
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("Approval.post.id");
	}
	//����״̬;status;varchar
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("Approval.post.remark");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 