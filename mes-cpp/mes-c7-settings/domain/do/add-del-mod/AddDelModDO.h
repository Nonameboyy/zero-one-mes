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
#ifndef _ADDDELMOD_DO_
#define _ADDDELMOD_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AddDelModDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_id);
	// 仓库编码
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	// 仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// 位置
	CC_SYNTHESIZE(string, location, Location);
	// 面积
	CC_SYNTHESIZE(double, area, Area);
	// 负责人
	CC_SYNTHESIZE(string, charge, Charge);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	AddDelModDO() {
		warehouse_id = 0;
		warehouse_code = "";
		warehouse_name = "";
		location = "";
		area = 0.0;
		charge = "";
		remark = "";
	}
};

#endif // !_ADDDELMOD_DO_
