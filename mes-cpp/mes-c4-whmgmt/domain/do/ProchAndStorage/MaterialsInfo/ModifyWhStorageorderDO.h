#pragma once
#ifndef _MODIFYWHSTORAGEORDER_DO_
#define _MODIFYWHSTORAGEORDER_DO_
/*
�޸���ⵥ�е����ݿ�ʵ����
*/
#include "../../DoInclude.h"
class ModifyWhStorageorderDO
{
	//��ID line_id bigint
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	//��Ʒ����ID item_id bigint
	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
	//���ϱ��� item_code varchar
	CC_SYNTHESIZE(string, item_code, Item_code);
	//�������� item_name varchar
	CC_SYNTHESIZE(string, item_name, Item_name);

	//��λ unit_of_measure varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//������� quantity_recived double
	CC_SYNTHESIZE(double, quantity_recived, Quantity_recived);
	//������κ� batch_code varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//��Ч�� expire_date String
	CC_SYNTHESIZE(string, expire_date, Expire_date);

	//�ֿ�ID warehouse_id bigint
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_id);
	//�ֿ���� warehouse_code varchar
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//�ֿ����� warehouse_name varchar
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);

	//����ID location_id bigint
	CC_SYNTHESIZE(uint64_t, location_id, Location_id);
	//�������� location_code varchar
	CC_SYNTHESIZE(string, location_code, Location_code);
	//�������� location_name varchar
	CC_SYNTHESIZE(string, location_name, Location_name);

	//��λID area_id bigint
	CC_SYNTHESIZE(uint64_t, area_id, Area_id);
	//��λ���� area_code varchar
	CC_SYNTHESIZE(string, area_code, Area_code);
	//��λ���� area_name varchar
	CC_SYNTHESIZE(string, area_name, Area_name);

	//�Ƿ���� iqc_check char
	CC_SYNTHESIZE(string, iqc_check, Iqc_check);
	//���ϼ��鵥���� iqc_code varchar
	CC_SYNTHESIZE(string, iqc_code, Iqc_code);
	//���ϼ��鵥ID iqc_id bigint
	CC_SYNTHESIZE(uint64_t, iqc_id, Iqc_id);
	//��ע remark varchar
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ModifyWhStorageorderDO() {
		line_id = 0;
		item_id = 1;
		item_code = "";
		item_name = "";

		unit_of_measure = "";
		quantity_recived = 0.00;
		batch_code = "";
		expire_date = "";

		warehouse_id = 0;
		warehouse_code = "";
		warehouse_name = "";

		location_id = 0;
		location_code = "";
		location_name = "";

		area_id = 0;
		area_code = "";
		area_name = "";

		iqc_check = "";
		iqc_code = "";
		iqc_id = 0;
		remark = "";
	}
};
#endif // !_MODIFYWHSTORAGEORDER_DO_
