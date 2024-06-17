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
#ifndef _RETURN_DAO_R_
#define _RETURN_DAO_R_
#include "BaseDAO.h"
#include "../../domain/do/return-ryan/ReturnDO_r.h"
#include "../../domain/query/return-ryan/ReturnQuery_r.h"

/**
 * 示例表数据库操作实现
 */
class ReturnDAO_r : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReturnQuery_r::Wrapper& query);
	// 分页查询数据
	list<ReturnDO_r> selectWithPage(const ReturnQuery_r::Wrapper& query, int flag);
	// 通过姓名查询数据
	list<ReturnDO_r> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ReturnDO_r& iObj);


	// 修改数据
	int update(const ReturnDO_r& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 通过ID修改状态
	int updateStatusById(uint64_t id);

};
#endif // !_RETURN_DAO_
#pragma once
