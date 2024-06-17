#pragma once
#ifndef _RAWMATERIALOP_DO_
#define _RAWMATERIALOP_DO_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 */
class RawMaterialOpDO
{
	// 生产退料ID
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_Id);
	// 生产退料编号
	CC_SYNTHESIZE(string, rt_code, Rt_Code);
	// 生产退料名称
	CC_SYNTHESIZE(string, rt_name, Rt_Name);

	// 生产工单ID
	CC_SYNTHESIZE(uint64_t, workororder_id, Workororder_Id);
	// 生产工单编号
	CC_SYNTHESIZE(string, workororder_code, Workororder_Code);

	// 仓库ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_Id);
	// 仓库编号
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_Code);
	// 仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);

	// 库区ID
	CC_SYNTHESIZE(uint64_t, location_id, Location_Id);
	// 库区编码
	CC_SYNTHESIZE(string, location_code, Location_Code);
	// 库区名称
	CC_SYNTHESIZE(string, location_name, Location_Name);


	// 库位ID
	CC_SYNTHESIZE(uint64_t, area_id, Area_Id);
	// 库位编号
	CC_SYNTHESIZE(string, area_code, Area_Code);
	// 库位名称
	CC_SYNTHESIZE(string, area_name, Area_Name);


	// 退料日期
	CC_SYNTHESIZE(string, rt_date, Rt_Date);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	//默认值
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