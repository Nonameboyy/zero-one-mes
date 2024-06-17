/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "stdafx.h"
#include "AddDelModDAO.h"
#include "AddDelModMapper.h"
#include <sstream>

uint64_t AddDelModDAO::insert(const AddDelModDO & iObj)
{
	string sql = "INSERT INTO `wm_warehouse` (`warehouse_code`, `warehouse_name`, `location`, `area`, `charge`, `remark`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%d%s%s", iObj.getWarehouse_code(), iObj.getWarehouse_name(), iObj.getLocation(), iObj.getArea(), iObj.getCharge(), iObj.getRemark());
}

int AddDelModDAO::update(const AddDelModDO& uObj)
{
	string sql = "UPDATE `wm_warehouse` SET `warehouse_code`=?, `warehouse_name`=?, `location`=?, `area`=?, `charge`=?, `remark`=? WHERE `warehouse_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%d%s%s%ull", uObj.getWarehouse_code(), uObj.getWarehouse_name(), uObj.getLocation(), uObj.getArea(), uObj.getCharge(), uObj.getRemark(), uObj.getWarehouse_id());
}

int AddDelModDAO::deleteById(uint64_t warehouse_id)
{
	string sql = "DELETE FROM `wm_warehouse` WHERE `warehouse_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", warehouse_id);
}