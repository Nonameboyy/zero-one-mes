#pragma once
#ifndef _storage_DO_
#define _storage_DO_
#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class storageDO
{
	// ���յ���ID
	CC_SYNTHESIZE(uint64_t, re_id, Re_Id);
	//���յ��ݱ��
	CC_SYNTHESIZE(string, re_code, Re_Code);
	// ���յ�������
	CC_SYNTHESIZE(string, re_name, Re_Name);

	// ���յ��ݹ���ID
	CC_SYNTHESIZE(uint64_t, workororder_id, Workororder_Id);
	// ���յ��ݹ������
	CC_SYNTHESIZE(string, workororder_code, Workororder_Code);

	// ���յ��ݲֿ�ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_Id);
	// ���յ��ݲֿ���
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_Code);
	// ���յ��ݲֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);

	// ���յ��ݿ���ID
	CC_SYNTHESIZE(uint64_t, location_id, Location_Id);
	// ���յ��ݿ�������
	CC_SYNTHESIZE(string, location_code, Location_Code);
	// ���յ��ݿ�������
	CC_SYNTHESIZE(string, location_name, Location_Name);


	// ���յ��ݿ�λID
	CC_SYNTHESIZE(uint64_t, area_id, Area_Id);
	// ���յ��ݿ�λ���
	CC_SYNTHESIZE(string, area_code, Area_Code);
	// ���յ��ݿ�λ����
	CC_SYNTHESIZE(string, area_name, Area_Name);


	// ��������
	CC_SYNTHESIZE(string, re_date, Re_Date);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	//Ĭ��ֵ
	storageDO() {
		re_id = -1;
		re_code = "";
		re_name = "";
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
		re_date = "";
		remark = "";
	}
};

#endif 