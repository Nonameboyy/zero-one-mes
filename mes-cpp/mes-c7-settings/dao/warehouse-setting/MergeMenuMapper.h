#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _MERGEMENU_MAPPER_
#define  _MERGEMENU_MAPPER_
#include "Mapper.h"
#include "tree/TreeNodeMapper.h"
#include "../../domain/do/adress/AreaMenuDO.h"
#include "../../domain/do/adress/LocationMenuDO.h"
#include "../../domain/do/adress/WarehouseMenuDO.h"
#include"../../domain/dto/warehouse-settings/WarehouseCascadeDTO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AreaMenuMapper : public TreeNodeMapper<AreaMenuDO>
{
public:
	shared_ptr<TreeNode> objectMapper(AreaMenuDO* source) const override
	{
		auto res = make_shared<WarehouseCascadeDTO>();
		res->_id(source->getArea_id());
		res->_pid(source->getLocation_id());
		res->id = source->getArea_id();
		res->code = source->getArea_code();
		res->name = source->getArea_name();
		return res;
	}
};

class LocationMenuMapper :public TreeNodeMapper<LocationMenuDO>{
public:
	shared_ptr<TreeNode> objectMapper(LocationMenuDO* source) const override
	{
		auto res = make_shared<WarehouseCascadeDTO>();
		res->_id(source->getLocation_id());
		res->_pid(source->getWarehouse_id());
		res->id = source->getLocation_id();
		res->code = source->getLocation_code();
		res->name = source->getLocation_name();
		return res;
	}
};

class WarehouseMenuMapper :public TreeNodeMapper<WarehouseMenuDO> {
public:
	shared_ptr<TreeNode> objectMapper(WarehouseMenuDO* source) const override
	{
		auto res = make_shared<WarehouseCascadeDTO>();
		res->_id(source->getWarehouse_id());
		res->id = source->getWarehouse_id();
		res->code = source->getWarehouse_code();
		res->name = source->getWarehouse_name();
		return res;
	}
};

class AreaMapper : public Mapper<AreaMenuDO>
{
public:
	AreaMenuDO mapper(ResultSet* resultSet) const override
	{
		AreaMenuDO data;
		data.setArea_id(resultSet->getString(1));
		data.setArea_code(resultSet->getString(2));
		data.setArea_name(resultSet->getString(3));
		data.setLocation_id(resultSet->getString(4));
		return data;
	}
};

class LocationMapper : public Mapper<LocationMenuDO>
{
public:
	LocationMenuDO mapper(ResultSet* resultSet) const override
	{
		LocationMenuDO data;
		data.setLocation_id(resultSet->getString(1));
		data.setLocation_code(resultSet->getString(2));
		data.setLocation_name(resultSet->getString(3));
		data.setWarehouse_id(resultSet->getString(4));
		return data;
	}
};

class WarehouseMapper : public Mapper<WarehouseMenuDO>
{
public:
     WarehouseMenuDO mapper(ResultSet* resultSet) const override
	{
		WarehouseMenuDO data;
		data.setWarehouse_id(resultSet->getString(1));
		data.setWarehouse_code(resultSet->getString(2));
		data.setWarehouse_name(resultSet->getString(3));
		return data;
	}
};

#endif // !_ADDDELMOD_MAPPER_
