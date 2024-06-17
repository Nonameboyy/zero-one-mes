#pragma once
#ifndef _product_DO_
#define _product_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ProductDO
{
	// 入库单id（唯一）
	CC_SYNTHESIZE(uint64_t, recpt_id, Recpt_id);
	// 入库单编号
	CC_SYNTHESIZE(string, recpt_code, Recpt_code);
	// // 入库单名称
	CC_SYNTHESIZE(string, recpt_name, Recpt_name);
	// // 生产工单code
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//  仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//  产品编码
	CC_SYNTHESIZE(string, product_code, Product_code);
	//  产品名称
	CC_SYNTHESIZE(string, product_name, Product_name);
	
	//入库日期
	CC_SYNTHESIZE(string, recpt_date, Recpt_date);
	//单据状态
	CC_SYNTHESIZE(string, status, Status);

	

public:
	ProductDO() {
		recpt_id = 0;
		recpt_code = "0000";
		recpt_name = "Rtname";
		//workorder_id = "1";
		warehouse_name = "warehouse_name";
		product_name = "product_name";
		product_code= "product_code";
		recpt_date = "recpt_date";
		status = "status";
	}
};

#endif // !_rejectionQuery_DO_
