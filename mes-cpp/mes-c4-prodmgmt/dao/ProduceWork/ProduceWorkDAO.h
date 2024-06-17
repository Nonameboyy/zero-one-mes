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
#ifndef _PWORK_DAO_
#define _PWORK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProduceWork/ProduceWorkDO.h"

/**
 * 示例表数据库操作实现
 */
class ProduceWorkDAO : public BaseDAO
{
public:
	// 通过姓名查询数据
	list<ProduceWorkDO> selectByRecord_id(const uint64_t& record_id);
	// 插入数据
	uint64_t insert(const ProduceWorkDO& iObj);
	//// 修改数据
	int update(const ProduceWorkDO& uObj);

};
#endif // !_SAMPLE_DAO_
