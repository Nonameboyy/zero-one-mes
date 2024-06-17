#pragma once
#ifndef _PROINSPECT_DO_H_
#define _PROINSPECT_DO_H_
#include "../DoInclude.h"

class ProinspectDO
{
	// 缺陷ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 检验单类型
	CC_SYNTHESIZE(string, qc_type, Qc_type);
	// 检验单ID
	CC_SYNTHESIZE(uint64_t, qc_id, Qc_id);
	// 检验单行ID
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	// 缺陷名称
	CC_SYNTHESIZE(string, defect_name, Defect_name);
	// 缺陷等级
	CC_SYNTHESIZE(string, defect_level, Defect_level);
	// 缺陷数量
	CC_SYNTHESIZE(int32_t, defect_quantity, Defect_quantity);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 检验项名称
	CC_SYNTHESIZE(string, index_name, Index_name);
	// 检验项类型
	CC_SYNTHESIZE(string, index_type, Index_type);
	// 检验工具
	CC_SYNTHESIZE(string, qc_tool, Qc_tool);
	// 检验要求
	CC_SYNTHESIZE(string, check_method, Check_method);
	// 标准值
	CC_SYNTHESIZE(Float64, stander_val, Stander_val);
	// 单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// 误差上限
	CC_SYNTHESIZE(Float64, threshold_max, Threshold_max);
	// 误差下限
	CC_SYNTHESIZE(Float64, threshold_min, Threshold_min);
	// 致命缺陷数量
	CC_SYNTHESIZE(Float64, cr_quantity, Cr_quantity);
	// 严重缺陷数量
	CC_SYNTHESIZE(Float64, maj_quantity, Maj_quantity);
	// 轻微缺陷数量
	CC_SYNTHESIZE(Float64, min_quantity, Min_quantity);

public:
	ProinspectDO() {
		record_id = 1;
		qc_type = "";
		qc_id = 1;
		line_id = 1;
		defect_name = "";
		defect_level = "";
		remark = "";
		defect_quantity = 1;
	}
};

#endif // !_PROINSPECTDO_H_