#pragma once
#ifndef _MATERIAL_DO_
#define _MATERIAL_DO_
#include "../DoInclude.h"

/**
 * ������Ϣ���ݿ�ʵ����
 */
class MaterialDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	// ���ϵ�ID
	CC_SYNTHESIZE(uint64_t, issue_id, Issue_id);
	// ��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
	// ��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_code);
	// ��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_name);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// ��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// ��������
	CC_SYNTHESIZE(double_t, quantity_issued,Quantity_issued);
	// ���κ�
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	// �ֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// ��������
	CC_SYNTHESIZE(string, location_name, Location_name);
	// ��λ����
	CC_SYNTHESIZE(string, area_name, Area_name);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	MaterialDO() {
		line_id = 0;
		issue_id = 0; 
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity_issued = 0;
		batch_code = "";
		warehouse_name = "";
		location_name = "";
		area_name = "";
		remark = "";
	}
};

#endif // !_MATERIAL_DO_
