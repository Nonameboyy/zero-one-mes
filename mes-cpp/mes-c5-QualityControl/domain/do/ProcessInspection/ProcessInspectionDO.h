#pragma once
#ifndef _PROCESSINSPECTION_DO_
#define _PROCESSINSPECTION_DO_

#include "../DoInclude.h"

class ProcessInspectionDO {
	// ���鵥ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���鵥����
	CC_SYNTHESIZE(string, ipqc_code, Ipqc_Code);
	// ���鵥����
	CC_SYNTHESIZE(string, ipqc_name, Ipqc_Name);
	// ��������
	CC_SYNTHESIZE(string, ipqc_type, Ipqc_Type);
	// ��������
	CC_SYNTHESIZE(string, workorder_code, Workorder_Code);
	// ��������
	CC_SYNTHESIZE(string, workorder_name, Workorder_Name);
	// ����վ���
	CC_SYNTHESIZE(string, workstation_code, Workstation_Code);
	// ����վ����
	CC_SYNTHESIZE(string, workstation_name, Workstation_Name);
	// �������
	CC_SYNTHESIZE(double, quantity_check, Quantity_Check);
	// ��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// ��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// ��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_Of_Measure);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// �������
	CC_SYNTHESIZE(string, process_code, Process_Code);
	// ��������
	CC_SYNTHESIZE(string, process_name, Process_Name);
	// ������
	CC_SYNTHESIZE(string, task_code, Task_Code);
	// ������
	CC_SYNTHESIZE(string, task_name, Task_Name);
	// ���ϸ���
	CC_SYNTHESIZE(double, quantity_unqualified, Quantity_Unqualified);
	// �ϸ�Ʒ����
	CC_SYNTHESIZE(double, quantity_qualified, Quantity_Qualified);
	// ����ȱ������
	CC_SYNTHESIZE(double, cr_quantity, Cr_Quantity);
	// ����ȱ������
	CC_SYNTHESIZE(double, maj_quantity, Maj_Quantity);
	// ��΢ȱ������
	CC_SYNTHESIZE(double, min_quantity, Min_Quantity);
	// �������
	CC_SYNTHESIZE(string, inspect_date, Inspect_Date);
	// �����
	CC_SYNTHESIZE(string, check_result, Check_Result);
	// �����Ա
	CC_SYNTHESIZE(string, inspector, Inspector);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// ����״̬
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
