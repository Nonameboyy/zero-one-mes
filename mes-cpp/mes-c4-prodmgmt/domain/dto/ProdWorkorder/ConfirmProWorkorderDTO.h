#pragma once
#ifndef _CONFIRMPROWORKORDER_DTO_
#define _CONFIRMPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ȷ�������������ݴ�������
 */
class ConfirmProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(ConfirmProWorkorderDTO, DTO);

	// ���
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}

};



#include OATPP_CODEGEN_END(DTO)
#endif // !_CONFIRMPROWORKORDER_DTO_