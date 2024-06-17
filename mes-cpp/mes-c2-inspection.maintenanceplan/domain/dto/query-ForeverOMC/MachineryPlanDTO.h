#ifndef _MACHINERY_PLAN_DTO_
#define _MACHINERY_PLAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养计划列表传输对象
*/
class MachineryPlanDTO : public oatpp::DTO
{
	DTO_INIT(MachineryPlanDTO, DTO);

	// 计划ID
	DTO_FIELD(UInt32, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}

	// 计划编码
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

	// 开始日期
	DTO_FIELD(String, start_date);
	DTO_FIELD_INFO(start_date) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.start-date");
	}

	// 结束日期
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.end-date");
	}

	// 频率
	DTO_FIELD(String, cycle_type);
	DTO_FIELD_INFO(cycle_type) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.cycle-type");
	}

	// 次数
	DTO_FIELD(UInt32, cycle_count);
	DTO_FIELD_INFO(cycle_count) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.cycle-count");
	}

	// 状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.status");
	}
};

/**
* 点检/保养计划列表分页传输对象
*/
class MachineryPlanPageDTO : public PageDTO<MachineryPlanDTO::Wrapper>
{
	DTO_INIT(MachineryPlanPageDTO, PageDTO<MachineryPlanDTO::Wrapper>);
};

class MachineryPlanDetailsDTO : public MachineryPlanDTO
{
	DTO_INIT(MachineryPlanDetailsDTO, MachineryPlanDTO);

	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_PLAN_DTO_