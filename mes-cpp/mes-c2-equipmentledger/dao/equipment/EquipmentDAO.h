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
#ifndef _EQUIPMENT_DAO_
#define _EQUIPMENT_DAO_
#include "BaseDAO.h"
#include"../../domain/do/dv_machinery/dvMachineryDO.h"
#include"../../domain/query/equipment/EquipmentQuery.h"
#include"../../domain/do/dv_machinery_type/dvMachineryTypeDO.h"
#include"../../domain/do/md_workshop/md_workshopDO.h"
/**
 * 示例表数据库操作实现
 */
class EquipmentDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const EquipmentQuery::Wrapper& query);
	// 分页查询数据
	list<dvMachineryDO> selectWithPage(const EquipmentQuery::Wrapper& query);
	// 通过设备ID查询数据
	list<dvMachineryDO> selectWithId(const EquipmentDetailQuery::Wrapper& query);
	// 插入数据
	uint64_t insert( dvMachineryDO& iObj);
	//通过设备类型名称获得设备类型ID
	list<dvMachineryTypeDO> getMachinerytypeidByname(std::string name);
	//通过车间名称获得车间ID
	list<MdWorkshopDO> getWorkshopidByname(std::string name);
	// 修改数据
	int modify( dvMachineryDO iObj);
	//根据车间ID获取详情
	list<MdWorkshopDO> getWorkshopByid(std::int64_t id);
	//根据设备类型ID获取详情
	list<dvMachineryTypeDO> getMachinerytypeByid(std::int64_t id);
	//根据设备ID获取详情
	list<dvMachineryDO> getMachineryByid(std::int64_t id);
	
};
#endif // 

