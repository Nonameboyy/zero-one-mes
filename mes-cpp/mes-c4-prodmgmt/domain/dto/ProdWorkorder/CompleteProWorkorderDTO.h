#pragma once
#ifndef _COMPLETEPROWORKORDER_DTO_
#define _COMPLETEPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ȷ�������������ݴ�������
 */
class CompleteProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(CompleteProWorkorderDTO, DTO);

	// ���
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}

};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPLETEPROWORKORDER_DTO_