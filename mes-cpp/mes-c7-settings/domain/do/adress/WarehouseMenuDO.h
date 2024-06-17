#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/17 16:25:30

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
#ifndef _WAREHOUSEMENUDO_H_
#define _WAREHOUSEMENUDO_H_

#include "../DoInclude.h"
/**
 * ²âÊÔ²Ëµ¥Êý¾Ý¿âÊµÌå
 */
class WarehouseMenuDO
{
	// Î¨Ò»±àºÅ
	CC_SYNTHESIZE(string, warehouse_id, Warehouse_id);
	// ²Ö¿â±àÂë
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//²Ö¿âÃû³Æ
	 CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);

public:
	WarehouseMenuDO() {}
	WarehouseMenuDO(string warehouse_id, string warehouse_code, string warehouse_name)
	{
		this->warehouse_id = warehouse_id;
		this->warehouse_code = warehouse_code;
		this->warehouse_name = warehouse_name;

	}
};

#endif // !_SAMPLEMENUDO_H_