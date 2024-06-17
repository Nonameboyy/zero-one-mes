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
#ifndef _GETALLDETAILS_DAO_
#define _GETALLDETAILS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/wm_warehouse/Wm_WarehouseDO.h"
#include "../../domain/query/warehouse/GetAllDetailsQuery.h"

/**
 * 示例表数据库操作实现
 */
class GetAllDetailsDAO : public BaseDAO
{
public:
	// 查询数据
	list<Wm_WarehouseDO> selectdetails(const GetAllDetailsQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_
