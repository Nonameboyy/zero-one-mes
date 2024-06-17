#pragma once

#ifndef _RETURN_DO_
#define _RETURN_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class ReturnDO
{
	// 退货单ID
	CC_SYNTHESIZE(uint64_t, returnID, returnid);
	// 退货单编号
	CC_SYNTHESIZE(string, returnCode, returncode);
	// 退货单名称
	CC_SYNTHESIZE(string, returnName, returnname);
	// 采购单编号
	CC_SYNTHESIZE(string, purchaseCode, purchasecode);
	// 供应商编码
	CC_SYNTHESIZE(string, vendorCode, vendorcode);
	// 供应商名称
	CC_SYNTHESIZE(string, vendorName, vendorname);
	// 退货日期
	CC_SYNTHESIZE(string, returnDate, returndate);
	// 单据状态
	CC_SYNTHESIZE(string, status, status);
	// 批次号
	CC_SYNTHESIZE(string, batchCode, batchcode);
	// 备注
	CC_SYNTHESIZE(string, remark, remark);
	// 更新者
	CC_SYNTHESIZE(string, updateBy, updateby);
	// 更新时间
	CC_SYNTHESIZE(string, updateTime, updatetime);
	// 创建者
	CC_SYNTHESIZE(string, createBy, createby);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, createtime);
	// 供应商ID
	CC_SYNTHESIZE(uint64_t, vendorID, vendorid);
	// 供应商简称
	CC_SYNTHESIZE(string, vendorNick, vendornick);
	
public:
	ReturnDO() {

		returnID = 0;
		returnCode = "0";
		returnName = "returnName";
		purchaseCode = "1";
		vendorCode = "2";
		vendorName = "vendorName";
		returnDate = "1234-12-31";
		status = "PREPARE";
		batchCode = "1234";
		remark = "null";
		updateBy = "updateBy";
		updateTime = "updateTime";
		createBy = "createBy";
		createTime = "createTime";
		vendorID = 0;
		vendorNick = "vendorNick";
	}
};

#endif // !_RETURN_DO_
