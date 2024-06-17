#pragma once
#ifndef _DELETEPROWORKORDER_DTO_
#define _DELETEPROWORKORDER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除生产工单数据传输类型
 */
class DeleteProWorkorderDTO : public oatpp::DTO
{
	DTO_INIT(DeleteProWorkorderDTO, DTO);

	// 编号
	DTO_FIELD(UInt64, workorderId);
	DTO_FIELD_INFO(workorderId) {
		info->description = ZH_WORDS_GETTER("ProdWorkorder.field.workorderId");
	}
	
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEPROWORKORDER_DTO_