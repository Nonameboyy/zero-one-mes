#pragma once

#ifndef _RECEIPT_DO_H
#define _RECEIPT_DO_H
#include "../DoInclude.h"

/**
 * 获取单据列表 数据库实体类
 */
class ReceiptPageTableDO
{
	// 数据库的表： wm_item_recpt
	// 
	// 入库单ID
	CC_SYNTHESIZE(int32_t, recptId, RecptId);

	// 入库单编号
	CC_SYNTHESIZE(string, recptCode, RecptCode);

	// 入库单名称
	CC_SYNTHESIZE(string, recptName, RecptName);

	// 供应商名称
	CC_SYNTHESIZE(string, vendorName, VendorName);

	// 订单编号
	CC_SYNTHESIZE(string, poCode, PoCode);

	// 入库日期 
	CC_SYNTHESIZE(string, recptDate, RecptDate);

	// 单据状态
	CC_SYNTHESIZE(string, status, Status);

public:
	ReceiptPageTableDO() {
		recptId = 0;
		recptCode = "";
		recptName = "";
		vendorName = "";
		poCode = "";
		recptDate = "";
		status = "";
	}
};

/**
* 获取单据详情 数据库实体类
*/
class ReceiptDetailDO : public ReceiptPageTableDO
{
	// 入库仓库
	CC_SYNTHESIZE(string, warehouseName, WarehouseName);

	// 备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ReceiptDetailDO() {
		warehouseName = "";
		remark = "";
	}
};
#endif // !_RECEIPT_DO_H
