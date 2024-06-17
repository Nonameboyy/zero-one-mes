#pragma once

#ifndef _WAREHOUSEMANAGEMENT_DO_
#define _WAREHOUSEMANAGEMENT_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class WarehouseManagementDO
{
	CC_SYNTHESIZE(int, item_id, Item_Id);
	//��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_Code);

	// ��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// ��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_Of_Measure);
	// ������κ�
	CC_SYNTHESIZE(string, batch_code, Batch_Code);
	//�ֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);
	// ��������
	CC_SYNTHESIZE(string, location_name, Location_Name);
	// ��λ����
	CC_SYNTHESIZE(string, area_name, Area_Name);
	// ��Ӧ�̱��
	CC_SYNTHESIZE(string, vendor_code, Vendor_Code);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendor_name, Vendor_Name);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendor_nick, Vendor_Nick);
	// �����������
	CC_SYNTHESIZE(string, workorder_code, Workorder_Code);
	// ��������
	CC_SYNTHESIZE(string, recpt_date, Recpt_Date);
	// �����Ч��
	CC_SYNTHESIZE(string, expire_date, Expire_Date);
public:
	WarehouseManagementDO() {
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		batch_code = "";
		warehouse_name = "";
		location_name = "";
		area_name = "";
		vendor_code = "";
		vendor_name = "";
		vendor_nick = "";
		workorder_code = "";
		recpt_date = "";
		expire_date = "";
	}
};

#endif // !_WAREHOUSEMANAGEMENT_DO_
