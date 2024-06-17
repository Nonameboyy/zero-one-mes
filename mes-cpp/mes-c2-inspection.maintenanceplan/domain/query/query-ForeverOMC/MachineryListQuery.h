#ifndef _MACHINERY_LIST_QUERY_
#define _MACHINERY_LIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)	

/*
* 点检/保养设备列表分页查询对象
*/
class MachineryListQuery : public PageQuery
{
	DTO_INIT(MachineryListQuery, PageQuery);

	// 计划ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-list.field.plan-code");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_LIST_QUERY_