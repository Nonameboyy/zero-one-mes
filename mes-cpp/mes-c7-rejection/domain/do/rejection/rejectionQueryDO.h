#pragma once
#ifndef _rejectionQuery_DO_
#define _rejectionQuery_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class RejectQueryDO
{
	// 退料单id（唯一）
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_id);
	// 退料单编号
	CC_SYNTHESIZE(string, rt_code, Rt_code);
	// // 退料单名称
	CC_SYNTHESIZE(string, rt_name, Rt_name);
	// // 生产工单id
	CC_SYNTHESIZE(string, workorder_id, Workorder_id);
	//  仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// 库区名称
	CC_SYNTHESIZE(string, location_name, Location_name);
	// 库位名称
	CC_SYNTHESIZE(string, area_name, Area_name);
	//退料日期
	CC_SYNTHESIZE(string, rt_date, Rt_date);
	//单据状态
	CC_SYNTHESIZE(string, status, Status);
	
	//detail data
	//生产工单编码
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//仓库id
	CC_SYNTHESIZE(string, warehouse_id, Warehouse_id);
	//仓库编码
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//库区id
	CC_SYNTHESIZE(string, location_id, Location_id);
	//库区编码
	CC_SYNTHESIZE(string, location_code, Location_code);
	//库位id
	CC_SYNTHESIZE(string, area_id, Area_id);
	//库位编码
	CC_SYNTHESIZE(string, area_code, Area_code);

	//.......................................................
	//接收仓库
	CC_SYNTHESIZE(string, rsname, Rsname);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	RejectQueryDO() {
		rt_id = 0;
		rt_code = "0000";
		rt_name = "Rtname";
		workorder_id = "1";
		warehouse_name = "warehouse_name";
		location_name = "location_name";
		area_name = "area_name";
		rt_date = "rt_date";
		status = "status";
	}
};

#endif // !_rejectionQuery_DO_
