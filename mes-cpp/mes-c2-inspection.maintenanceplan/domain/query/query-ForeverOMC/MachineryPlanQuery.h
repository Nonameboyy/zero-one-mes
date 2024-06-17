#ifndef _MACHINERY_PLAN_QUERY_
#define _MACHINERY_PLAN_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)	

/*
* 点检/保养计划列表条件分页查询对象
*/
class MachineryPlanQuery : public PageQuery
{
	DTO_INIT(MachineryPlanQuery, PageQuery);

	// 计划编号
	DTO_FIELD(String, plan_code);
	DTO_FIELD_INFO(plan_code) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-code");
	}

	// 计划名称
	DTO_FIELD(String, plan_name);
	DTO_FIELD_INFO(plan_name) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-name");
	}

	// 计划类型
	DTO_FIELD(String, plan_type);
	DTO_FIELD_INFO(plan_type) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-type");
	}

	// 状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.status");
	}
};

/*
* 获取点检保养计划详情
*/
class MachineryPlanDetailsQuery : public oatpp::DTO
{
	DTO_INIT(MachineryPlanDetailsQuery, DTO);

	// 计划ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_PLAN_QUERY_