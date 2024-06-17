#pragma once
//ProdWorkorderBomList
#ifndef _PRODWORKORDERBOMLIST_QUERY_
#define _PRODWORKORDERBOMLIST_QUERY_

#include "../../GlobalInclude.h"
#include "../lib-oatpp/include/domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取生产工单BOM列表查询对象
 */
class ProdWorkorderBomListQuery : public PageQuery {
	DTO_INIT(ProdWorkorderBomListQuery, PageQuery);
	//BOM行ID;line_id;bigint
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("bom.field.line_id");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODWORKORDERBOMLIST_QUERY_