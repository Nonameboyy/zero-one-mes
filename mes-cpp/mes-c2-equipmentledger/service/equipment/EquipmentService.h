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

#ifndef _EQUIPMENT_SERVICE_
#define _EQUIPMENT_SERVICE_

#include"../../domain/dto/equipment/EquipmentDTO.h"
#include"../../domain/query/equipment/EquipmentQuery.h"
class EquipmentService
{
public:
	// 分页查询所有数据
	EquipmentPageDTO::Wrapper listAll(const EquipmentQuery::Wrapper& query);
	// 获取设备详情
	EquipmentDetailDTO::Wrapper getDetail(const EquipmentDetailQuery::Wrapper& query);
	//新增设备
	uint64_t saveData(const addEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool modifyData(const modifyEquipmentDTO::Wrapper& dto, const PayloadDTO& payload);
	
};

#endif // 

