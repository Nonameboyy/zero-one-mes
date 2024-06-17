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
#ifndef _WORKFIXTURE_FOR_WORKSTATION_DO_
#define _WORKFIXTURE_FOR_WORKSTATION_DO_
#include "DoInclude.h"

/**
 * 表:md_workstation 数据库实体类
 */
class WorkFixtureForWorkStationDO
{
	// 记录ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);
	// 工装夹具ID
	CC_SYNTHESIZE(uint64_t, tooltypeId, TooltypeId);
	// 类型编码
	CC_SYNTHESIZE(string, tooltypeCode, TooltypeCode);
	// 类型名称
	CC_SYNTHESIZE(string, tooltypeName, TooltypeName);
	// 数量
	CC_SYNTHESIZE(uint32_t, quantity, Quantity);
public:
	WorkFixtureForWorkStationDO() {
		recordId = 0;
		tooltypeId = 0;
		tooltypeCode = "";
		tooltypeName = "";
		quantity = 1;
	}
};

#endif // !_WORKSTATION_DO_
