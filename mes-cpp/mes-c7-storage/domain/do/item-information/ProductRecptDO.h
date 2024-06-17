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
#ifndef _PRODUCT_RECPT_DO_
#define _PRODUCT_RECPT_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类,对应表wm_storage_location的数据
 */
class ProductRecptDO
{
	//入库单编号,必填
	CC_SYNTHESIZE(string, recpt_code, RecptCode);//定义属性recpt_code,类型为string,并且定义getRecptCode()返回recpt_code
	// 入库单名称
	CC_SYNTHESIZE(string, recpt_name, RecptName);
	//生产工单编码
	CC_SYNTHESIZE(string, workorder_code, WorkorderCode);
	//生产工单名称
	CC_SYNTHESIZE(string, workorder_name, WorkorderName);
	//入库日期
	CC_SYNTHESIZE(string, recpt_date, RecptDate);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//产品物料ID
	CC_SYNTHESIZE(uint64_t, item_id, ItemId);
public:
	ProductRecptDO()
	{
		recpt_code = "recpt_code";
		recpt_name = "recpt_name";
		workorder_code = "workorder_code";
		workorder_name = "workorder_name";
		recpt_date = "recpt_date";
		remark = "remark";
		item_id = 1;
	}
};

#endif // !_PRODUCT_RECPT_DO_
