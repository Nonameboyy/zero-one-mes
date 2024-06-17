#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _WORKSTATION_SERVICE_
#define _WORKSTATION_SERVICE_
#include <list>
#include "domain/vo/workstation/GetWorkStationListVO.h"
#include "domain/query/workstation/WorkStationQuery.h"



/**
 * 示例服务实现，演示基础的示例服务实现
 */
class WorkStationService
{
public:
	// 分页查询所有工作站数据
	GetWorkStationListPageDTO::Wrapper listAll(const GetWorkStationListQuery::Wrapper& query);
	// 新增工作站并保存数据
	uint64_t saveData(const AddWorkStationDTO::Wrapper& dto);
	// 修改工作站
	bool updateData(const ModifyWorkStationDTO::Wrapper& dto);
	// 通过ID删除工作站
	bool removeData(uint64_t id);
	// 通过ID批量删除工作站
	bool removeDatas(list< uint64_t> id);
	//批量导出
	string exportData(const list<uint64_t>& id);
};

#endif // !_SAMPLE_SERVICE_

