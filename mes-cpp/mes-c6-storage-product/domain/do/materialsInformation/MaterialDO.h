#pragma once
#ifndef _MATERIAL_DO_
#define _MATERIAL_DO_
#include "../DoInclude.h"

/**
 * 物料信息数据库实体类
 */
class MaterialDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	// 领料单ID
	CC_SYNTHESIZE(uint64_t, issue_id, Issue_id);
	// 产品物料ID
	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
	// 产品物料编码
	CC_SYNTHESIZE(string, item_code, Item_code);
	// 产品物料名称
	CC_SYNTHESIZE(string, item_name, Item_name);
	// 规格型号
	CC_SYNTHESIZE(string, specification, Specification);
	// 单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// 领料数量
	CC_SYNTHESIZE(double_t, quantity_issued,Quantity_issued);
	// 批次号
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	// 仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// 库区名称
	CC_SYNTHESIZE(string, location_name, Location_name);
	// 库位名称
	CC_SYNTHESIZE(string, area_name, Area_name);
	// 备注
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
