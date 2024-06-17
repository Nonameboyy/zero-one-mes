#pragma once
#ifndef _WAREHOUSE_DELETE_DTO_
#define _WAREHOUSE_DELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改状态
 */
class WarehouseDeleteDTO : public oatpp::DTO
{
	DTO_INIT(WarehouseDeleteDTO, DTO);
	//记录id/生产工单编号;recpt_id;bigint
	DTO_FIELD(List<UInt64>, recpt_id);
	DTO_FIELD_INFO(recpt_id) {
		info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_id");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 