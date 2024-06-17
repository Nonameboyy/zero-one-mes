#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _RETURN_DO_R_
#define _RETURN_DO_R_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ReturnDO_r
{
	//退货单ID
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_id);
	// 退货单编号
	CC_SYNTHESIZE(string, rt_code, Rt_code);
	// 退货单名称
	CC_SYNTHESIZE(string, rt_name, Rt_name);
	// 采购订单编号
	CC_SYNTHESIZE(string, po_code, Po_code);
	// 供应商ID
	CC_SYNTHESIZE(uint64_t, vendor_id, Vendor_id);
	// 供应商编码
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	// 供应商名称
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	// 供应商简称
	CC_SYNTHESIZE(string, vendor_nick, Vendor_nick);
	// 批次号
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	// 退货日期
	CC_SYNTHESIZE(string, rt_date, Rt_date);
	// 单据状态
	CC_SYNTHESIZE(string, status, Status_);//Status 已被定义
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	//	预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//	预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//	预留字段3
	CC_SYNTHESIZE(int32_t, attr3, Attr3);
	//	预留字段4
	CC_SYNTHESIZE(int32_t, attr4, Attr4);
	//	创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	//	创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//	更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	//	更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	ReturnDO_r() {
		rt_id = 1;
		rt_code = "111";
		rt_name = "rt_name";
		po_code = "222";
		vendor_id = 2;
		vendor_code = "333";
		vendor_name = "vendor_name";
		vendor_nick = "vendor_nick";
		batch_code = "444";
		rt_date = "2024-05-21 09:49:51";
		status = "status";
		remark = "remark";
		attr1 = "attr1";
		attr2 = "attr2";
		attr3 = 3;
		attr4 = 4;
		create_by = "create_by";
		create_time = "2024-05-21 09:49:51";
		update_by = "update_by";
		update_time = "2024-05-21 09:49:51";
	}
};

#endif // !_RETURN_DO_
