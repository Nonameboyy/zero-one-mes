#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: evlast
 @Date: 2024/6/5 

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
#ifndef _CHANGE_DAO_
#define _CHANGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/workstation/WorkStationDO.h"
#include "../../domain/query/workwear/Workwear_Change_Query.h"
#include "../../domain/dto/Change_Workwear_DTO.h"

/**
 * 示例表数据库操作实现
 */
class ChangeDAO : public BaseDAO
{
public:
	// 修改数据
	int updateData(const WorkStationDO& uObj);
};
#endif // !_SAMPLE_DAO_
