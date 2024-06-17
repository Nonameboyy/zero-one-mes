#pragma once
#ifndef _RAWMATERIALOP_DO_
#define _RAWMATERIALOP_DO_
#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class RawMaterialOpDO
{
	// ��������ID
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_Id);
	// �������ϱ��
	CC_SYNTHESIZE(string, rt_code, Rt_Code);
	// ������������
	CC_SYNTHESIZE(string, rt_name, Rt_Name);

	// ��������ID
	CC_SYNTHESIZE(uint64_t, workororder_id, Workororder_Id);
	// �����������
	CC_SYNTHESIZE(string, workororder_code, Workororder_Code);

	// �ֿ�ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_Id);
	// �ֿ���
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_Code);
	// �ֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);

	// ����ID
	CC_SYNTHESIZE(uint64_t, location_id, Location_Id);
	// ��������
	CC_SYNTHESIZE(string, location_code, Location_Code);
	// ��������
	CC_SYNTHESIZE(string, location_name, Location_Name);


	// ��λID
	CC_SYNTHESIZE(uint64_t, area_id, Area_Id);
	// ��λ���
	CC_SYNTHESIZE(string, area_code, Area_Code);
	// ��λ����
	CC_SYNTHESIZE(string, area_name, Area_Name);


	// ��������
	CC_SYNTHESIZE(string, rt_date, Rt_Date);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	//Ĭ��ֵ
	RawMaterialOpDO() {
		rt_id = -1;
		rt_code = "";
		rt_name = "";
		workororder_id = -1;
		workororder_code = "";
		warehouse_id = 1;
		warehouse_code = "";
		warehouse_name = "";
		location_id = -1;
		location_code = "";
		location_name = "";
		area_id = -1;
		area_code = "";
		area_name = "";
		rt_date = "";
		remark = "";
	}
};

#endif 