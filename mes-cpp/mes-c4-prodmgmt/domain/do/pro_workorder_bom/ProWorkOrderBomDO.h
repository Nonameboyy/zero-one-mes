#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
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
#ifndef _ProWorkOrderBom_DO_
#define _ProWorkOrderBom_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ProWorkOrderBomDO
{
	CC_SYNTHESIZE(int, workorder_id, workOrderId);
	CC_SYNTHESIZE(string, item_code, itemCode);
	CC_SYNTHESIZE(string, item_name, itemName);
	CC_SYNTHESIZE(string, item_spc, itemSpc);
	CC_SYNTHESIZE(string, unit_of_measure, unitOfMeasure);
	CC_SYNTHESIZE(string, item_or_product, itemOrProduct);
	CC_SYNTHESIZE(double, quantity, bQuantity);
	CC_SYNTHESIZE(int, item_id, itemId);
	
	CC_SYNTHESIZE(string, create_time, createTime);//xj字段
	
public:
	ProWorkOrderBomDO() {
		workorder_id = 0;
		item_code = "";
		item_name = "";
		item_spc = "";
		unit_of_measure = "";
		item_or_product = "";
		quantity = 0.0;
		item_id = 0;
		workorder_id = 0;
		create_time = "";
	}
};

#endif // !_ProWorkOrderBom_DO_
