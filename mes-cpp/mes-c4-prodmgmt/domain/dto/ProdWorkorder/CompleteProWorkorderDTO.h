#pragma once
#ifndef _COMPLETEPROWORKORDER_DTO_
#define _COMPLETEPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 确认生产工单数据传输类型
 */
class CompleteProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(CompleteProWorkorderDTO, DTO);

	// 编号
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}

};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPLETEPROWORKORDER_DTO_