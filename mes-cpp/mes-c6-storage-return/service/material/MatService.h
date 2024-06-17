#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/5/28 11:08:56

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
#ifndef _MATSERVICE_H_
#define _MATSERVICE_H_
#include <list>
#include "domain/vo/material/GetReturnListVO.h"
#include "domain/query/material/GetReturnListQuery.h"
#include "domain/dto/material/AddReturnDTO.h"
#include "domain/dto/material/GetReturnListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MatService
{
public:
	// 分页查询所有数据
	GetReturnListPageDTO::Wrapper listAll(const GetReturnListQuery::Wrapper& query);
	// 保存数据-插入数据
	uint64_t saveData(const AddReturnDTO::Wrapper& dto1);
	// 修改数据
	bool updateData(const AddReturnDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_MATSERVICE_H_

