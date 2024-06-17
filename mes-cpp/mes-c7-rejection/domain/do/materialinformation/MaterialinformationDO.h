#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/27 11:52:32

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
#ifndef _MATERIALINFORMATION_DO_
#define _MATERIALINFORMATION_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class MaterialInformationDO
{
	// 生产退料ID
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_Id);
	// 生产退料编号
	CC_SYNTHESIZE(string, rt_code, Rt_Code);
	// 生产退料名称
	CC_SYNTHESIZE(string, rt_name, Rt_Name);

	// 生产工单ID
	CC_SYNTHESIZE(uint64_t, workororder_id, Workororder_Id);
	// 生产工单编号
	CC_SYNTHESIZE(string, workororder_code, Workororder_Code);

	// 仓库ID
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_Id);
	// 仓库编号
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_Code);
	// 仓库名称
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_Name);

	// 库区ID
	CC_SYNTHESIZE(uint64_t, location_id, Location_Id);
	// 库区编码
	CC_SYNTHESIZE(string, location_code, Location_Code);
	// 库区名称
	CC_SYNTHESIZE(string, location_name, Location_Name);


	// 库位ID
	CC_SYNTHESIZE(uint64_t, area_id, Area_Id);
	// 库位编号
	CC_SYNTHESIZE(string, area_code, Area_Code);
	// 库位名称
	CC_SYNTHESIZE(string, area_name, Area_Name);


	// 退料日期
	CC_SYNTHESIZE(string, rt_date, Rt_Date);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	MaterialInformationDO() {
		rt_id = -1;
		rt_code = "";
		rt_name = "";
		workororder_id = -1;
		workororder_code = "";
		warehouse_id = -1;
		warehouse_code = "";
		warehouse_name = "";
		location_id = -1;
		location_code = "";
		location_name = "";
		area_id = -1;
		area_code = "";
		area_name = "";
		rt_date = "";
		remark = "";
	}
};

#endif // !_MATERIALINFORMATION_DO_
