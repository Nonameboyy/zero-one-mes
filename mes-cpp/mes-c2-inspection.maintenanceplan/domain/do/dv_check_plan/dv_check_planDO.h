#pragma once
/*
*
*/
#ifndef _DV__CHECK__PLAN_DO_
#define _DV__CHECK__PLAN_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Dv_check_planDO
{
	// 计划ID，
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	//内联展开看形式，（分析：其实是定义了一个变量和get/set方法，get获取有返回，set设置无返回）
//protected: uint64_t plan_id; 
//public: uint64_t getPlan_id(void) const {return plan_id;}
//public: void setPlan_id(uint64_t var) {plan_id = var;};
	// 计划编码
	CC_SYNTHESIZE(string, plan_code, Plan_code);
	// 计划名称
	CC_SYNTHESIZE(string, plan_name, Plan_name);
	// 计划类型
	CC_SYNTHESIZE(string, plan_type, Plan_type);
	// 开始时间
	CC_SYNTHESIZE(string, start_date, Start_date);
	// 结束时间
	CC_SYNTHESIZE(string, end_date, End_date);
	// 频率
	CC_SYNTHESIZE(string, cycle_type, Cycle_type);
	// 次数
	//CC_SYNTHESIZE(uint32_t, cycle_count, Cycle_count);
protected: uint32_t cycle_count; public: uint32_t getCycle_count(void) const {
	return cycle_count;
}public: void setCycle_count(uint32_t var) {
	cycle_count = var;
};
	// 状态
	CC_SYNTHESIZE(string, status, Status);
	// 备注 
	CC_SYNTHESIZE(string, remark, Remark);
	// 预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// 预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// 预留字段3
	CC_SYNTHESIZE(uint32_t, attr3, Attr3);
	// 预留字段4
	CC_SYNTHESIZE(uint32_t, attr4, Attr4);
	// 创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	//默认构造
	Dv_check_planDO() {
		plan_id = 0;
		plan_code = "";
		plan_name = "";
		plan_type = "";
		start_date = "";
		end_date = "";
		cycle_type = "";
		cycle_count = 0;
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}
};

#endif // !_DV__CHECK__PLAN_DO_
