#pragma once
#ifndef _PRO_ROUTE_PRODUCT_DO_
#define _PRO_ROUTE_PRODUCT_DO_
#include "../DoInclude.h"

/**
 * ��Ʒ�Ƴ̱�
 */
class ProRouteProductDO
{
	// ��¼ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_Id);
	// ����·��ID
	CC_SYNTHESIZE(uint64_t, route_id, Route_Id);
	// ��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, item_id, Item_Id);
	// ��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// ��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// ��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_Of_Measure);
	// ��������
	CC_SYNTHESIZE(uint32_t, quantity, Quantity);
	// ������ʱ
	CC_SYNTHESIZE(double, production_time, Production_Time);
	// ʱ�䵥λ
	CC_SYNTHESIZE(string, time_unit_type, Time_Unit_Type);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ProRouteProductDO() {
		record_id = 0;
		route_id = 0;
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity = 1;
		production_time = 1.00;
		time_unit_type = "MINUTE";
		remark = "";
	}
};

#endif // !_PRO_ROUTE_PRODUCT_DO_
