#pragma once
#ifndef _PRO_ROUTE_PRODUCT_DO_
#define _PRO_ROUTE_PRODUCT_DO_
#include "../DoInclude.h"

/**
 * 产品制程表
 */
class ProRouteProductDO
{
	// 记录ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_Id);
	// 工艺路线ID
	CC_SYNTHESIZE(uint64_t, route_id, Route_Id);
	// 产品物料ID
	CC_SYNTHESIZE(uint64_t, item_id, Item_Id);
	// 产品物料编码
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// 产品物料名称
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// 规格型号
	CC_SYNTHESIZE(string, specification, Specification);
	// 单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_Of_Measure);
	// 生产数量
	CC_SYNTHESIZE(uint32_t, quantity, Quantity);
	// 生产用时
	CC_SYNTHESIZE(double, production_time, Production_Time);
	// 时间单位
	CC_SYNTHESIZE(string, time_unit_type, Time_Unit_Type);
	// 备注
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
