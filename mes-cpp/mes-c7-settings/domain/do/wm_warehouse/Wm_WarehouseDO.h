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
#ifndef _WM_WAREHOUSEDO_H_
#define _WM_WAREHOUSEDO_H_

#include "../DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class Wm_WarehouseDO
{
	// 仓库id
	CC_SYNTHESIZE(int64_t, warehouse_id, Warehouse_id);
	// 仓库编码
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	// 仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// 位置
	CC_SYNTHESIZE(string, location, Location);
	// 面积
	CC_SYNTHESIZE(double, area, Area);
	//负责人
	CC_SYNTHESIZE(string, charge, Charge);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	//更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	Wm_WarehouseDO() {}
	Wm_WarehouseDO(int64_t warehouse_id, string warehouse_code, string warehouse_name, string location, double area, string charge, string remark,string attr1,string attr2,int attr3,int attr4,string create_by,string create_time,string update_by,string update_time)
	{
		this->warehouse_id= warehouse_id;
		this->warehouse_code = warehouse_code;
		this->warehouse_name = warehouse_name;
		this->location = location;
		this->area = area;
		this->charge = charge;
		this->remark = remark;
		this->create_by = create_by;
		this->create_time = create_time;
		this->update_by = update_by;
		this->update_time = update_time;
	}
};

#endif // !_SAMPLEMENUDO_H_