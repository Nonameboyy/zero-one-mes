#pragma once
#ifndef _PROCESSINSPECTION_DO_
#define _PROCESSINSPECTION_DO_

#include "../DoInclude.h"

class ProcessInspectionDO {
	// 检验单ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 检验单编码
	CC_SYNTHESIZE(string, ipqc_code, Ipqc_Code);
	// 检验单名称
	CC_SYNTHESIZE(string, ipqc_name, Ipqc_Name);
	// 检验类型
	CC_SYNTHESIZE(string, ipqc_type, Ipqc_Type);
	// 工单编码
	CC_SYNTHESIZE(string, workorder_code, Workorder_Code);
	// 工单名称
	CC_SYNTHESIZE(string, workorder_name, Workorder_Name);
	// 工作站编号
	CC_SYNTHESIZE(string, workstation_code, Workstation_Code);
	// 工作站名称
	CC_SYNTHESIZE(string, workstation_name, Workstation_Name);
	// 检测数量
	CC_SYNTHESIZE(double, quantity_check, Quantity_Check);
	// 产品物料编码
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// 产品物料名称
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// 单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_Of_Measure);
	// 规格型号
	CC_SYNTHESIZE(string, specification, Specification);
	// 工序编码
	CC_SYNTHESIZE(string, process_code, Process_Code);
	// 工序名称
	CC_SYNTHESIZE(string, process_name, Process_Name);
	// 任务编号
	CC_SYNTHESIZE(string, task_code, Task_Code);
	// 任务编号
	CC_SYNTHESIZE(string, task_name, Task_Name);
	// 不合格数
	CC_SYNTHESIZE(double, quantity_unqualified, Quantity_Unqualified);
	// 合格品数量
	CC_SYNTHESIZE(double, quantity_qualified, Quantity_Qualified);
	// 致命缺陷数量
	CC_SYNTHESIZE(double, cr_quantity, Cr_Quantity);
	// 严重缺陷数量
	CC_SYNTHESIZE(double, maj_quantity, Maj_Quantity);
	// 轻微缺陷数量
	CC_SYNTHESIZE(double, min_quantity, Min_Quantity);
	// 检测日期
	CC_SYNTHESIZE(string, inspect_date, Inspect_Date);
	// 检测结果
	CC_SYNTHESIZE(string, check_result, Check_Result);
	// 检测人员
	CC_SYNTHESIZE(string, inspector, Inspector);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 单据状态
	CC_SYNTHESIZE(string, status, Status_Order);

public:
	ProcessInspectionDO() {
		id = 0;
		ipqc_code = "";
		ipqc_name = "";
		ipqc_type = "";
		workorder_code = "";
		workorder_name = "";
		workstation_code = "";
		workstation_name = "";
		quantity_check = 1.0;
		item_code = "";
		item_name = "";
		unit_of_measure = "";
		specification = "";
		process_code = "";
		process_name = "";
		task_code = "";
		task_name = "";
		quantity_unqualified = 0.0;
		quantity_qualified = 0.0;
		cr_quantity = 0.0;
		maj_quantity = 0.0;
		min_quantity = 0.0;
		inspect_date = "";
		check_result = "";
		inspector = "";
		remark = "";
		status = "";
	}

};

#endif // !_PROCESSINSPECTION_DO_
