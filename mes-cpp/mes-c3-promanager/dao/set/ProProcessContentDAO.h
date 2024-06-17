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
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessContentDO.h"
#include "../../domain/query/set/SetStepExportQuery.h"

/**
 * 示例表数据库操作实现
 */
class ProProcessContentDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SetStepExportQuery::Wrapper& query);
	// 分页查询数据
	list<ProProcessContentDO> selectWithPage(const SetStepExportQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ProProcessContentDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ProProcessContentDO& iObj);
	// 修改数据
	int update(const ProProcessContentDO& uObj);
	// 通过ID删除数据
	int deleteByprocessId(uint64_t id);
	// 通过ID删除数据
	int deleteBycontentId(uint64_t id);
};
#endif // !_SAMPLE_DAO_
