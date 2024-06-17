#pragma once
#ifndef _storage_DO_
#define _storage_DO_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 */
class storageDO
{
	// 接收单据ID
	CC_SYNTHESIZE(uint64_t, re_id, Re_Id);
	//接收单据编号
	CC_SYNTHESIZE(string, re_code, Re_Code);
	// 接收单据名称
	CC_SYNTHESIZE(string, re_name, Re_Name);

	// 接收单据工单ID
	CC_SYNTHESIZE(uint64_t, workororder_id, Workororder_Id);
	// 接收单据工单编号
	CC_SYNTHESIZE(string, workororder_code, Workororder_Code);

	// 接收单据仓库ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_Id);
	// 接收单据仓库编号
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_Code);
	// 接收单据仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);

	// 接收单据库区ID
	CC_SYNTHESIZE(uint64_t, location_id, Location_Id);
	// 接收单据库区编码
	CC_SYNTHESIZE(string, location_code, Location_Code);
	// 接收单据库区名称
	CC_SYNTHESIZE(string, location_name, Location_Name);


	// 接收单据库位ID
	CC_SYNTHESIZE(uint64_t, area_id, Area_Id);
	// 接收单据库位编号
	CC_SYNTHESIZE(string, area_code, Area_Code);
	// 接收单据库位名称
	CC_SYNTHESIZE(string, area_name, Area_Name);


	// 接收日期
	CC_SYNTHESIZE(string, re_date, Re_Date);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	//默认值
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