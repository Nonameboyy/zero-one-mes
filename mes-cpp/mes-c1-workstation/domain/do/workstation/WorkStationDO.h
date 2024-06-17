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
#ifndef _WORKSTATION_DO_
#define _WORKSTATION_DO_
#include "../DoInclude.h"

/**
 * 表:md_workstation 数据库实体类
 */
class WorkStationDO
{
	// 工作站ID
	CC_SYNTHESIZE(uint64_t, workstationId, WorkstationId);
	// 工作站编码
	CC_SYNTHESIZE(string, workstationCode, WorkstationCode);
	// 工作站名称
	CC_SYNTHESIZE(string, workstationName, WorkstationName);
	// 所在车间名称
	CC_SYNTHESIZE(string, workshopName, WorkshopName);
	
	//工装夹具类型
	CC_SYNTHESIZE(string, workwearType, WorkwearType);
	//工装夹具资源数量
	CC_SYNTHESIZE(uint64_t, workwearSum, WorkwearSum);

	//所属工序
	CC_SYNTHESIZE(string, processName, ProcessName);
	//是否启用
	CC_SYNTHESIZE(string, enableFlag, EnableFlag);
	//工作站地点
	CC_SYNTHESIZE(string, workstationAddress, WorkstationAddress);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//线边库ID
	CC_SYNTHESIZE(uint64_t, warehouseId, WarehouseId);
	//库区ID
	CC_SYNTHESIZE(uint64_t, locationId, LocationId);
	//库位ID
	CC_SYNTHESIZE(uint64_t, areaId, AreaId);
public:
	WorkStationDO() {
		workstationId = 0;
		workstationCode = "";
		workstationName = "";
		enableFlag = "Y";
		workshopName = "";
		workwearType = "";
		workwearSum = 1;
		processName = "";
		workstationAddress = "";
		remark = "";
		warehouseId = 12;
		locationId = 11;
		areaId = 13;
	}
};

#endif // !_WORKSTATION_DO_
