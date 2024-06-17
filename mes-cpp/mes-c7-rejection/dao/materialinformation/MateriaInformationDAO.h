#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 无名氏
 @Date: 2024/05/27 14:23:49

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
#ifndef _MATERIALINFORMATION_DAO_
#define _MATERIALINFORMATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/materialinformation/MaterialinformationDO.h"
#include "../../domain/query/materialinformation/MaterialInformationQuery.h"

/**
 * 示例表数据库操作实现
 */
class MaterialinformationDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const MaterialInformationDO& iObj);
	// 修改数据
	int update(const MaterialInformationDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	// 统计数据条数
	uint64_t count(const MaterialInformationQuery::Wrapper& query);
	// 分页查询数据
	list<MaterialInformationDO> selectWithPage(const MaterialInformationQuery::Wrapper& query);
};
#endif // !_MATERIALINFORMATION_DAO_