#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _WORKSTATION_DAO_
#define _WORKSTATION_DAO_
#include "BaseDAO.h"
#include "../mes-c1-workstation/domain/do/workstation/WorkStationDO.h"
#include "../mes-c1-workstation/domain/query/workstation/WorkStationQuery.h"

/**
 * 示例表数据库操作实现
 */
class WorkStationDAO : public BaseDAO
{
public:
	// 统计工作站的数据条数
	uint64_t count(const GetWorkStationListQuery::Wrapper& query);
	// 分页查询数据
	list<WorkStationDO> selectWithPage(const GetWorkStationListQuery::Wrapper& query);

	// 通过工作站编码查询数据
	list<WorkStationDO> selectByWorkstationCode(const string& code);
	// 通过工作站名称查询数据
	list<WorkStationDO> selectByWorkstationName(const string& name);
	// 通过所在车间名称查询数据
	list<WorkStationDO> selectByWorkshopName(const string& name);
	// 通过所属工序查询数据
	list<WorkStationDO> selectByProcessName(const string& name);
	
	// 添加新的工作站
	uint64_t insert(const WorkStationDO& iObj);
	// 修改工作站数据
	int update(const WorkStationDO& uObj);
	// 通过ID删除工作站
	int deleteById(uint64_t id);
	//通过id批量删除
	int deleteByIdList(list<uint64_t> id);
	//根据id列表查数据
	list<WorkStationDO> selectByIdList(const list<uint64_t>& id);
};
#endif // !_SAMPLE_DAO_
