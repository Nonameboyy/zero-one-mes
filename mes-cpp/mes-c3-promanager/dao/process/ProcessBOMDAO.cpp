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
#include "ProcessBOMDAO.h"
#include "SimpleDateTimeFormat.h"
#include <sstream>

int ProcessBOMDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pro_route_product_bom` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
uint64_t ProcessBOMDAO::insert(const ProRouteProductBomDO& iObj, const PayloadDTO& payload)
{
	string sql = "INSERT INTO `pro_route_product_bom` (`route_id`, `process_id`, `product_id`,`item_id`,`item_code`, `item_name`, `unit_of_measure`, `specification`, `quantity`, `remark`, `create_by`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%ull%ull%ull%s%s%s%s%d%s%s%s", iObj.getRoute_id(), iObj.getProcess_id(), iObj.getProduct_id(), iObj.getItem_id(), iObj.getItem_code(), iObj.getItem_name(),iObj.getUnit_of_measure(),iObj.getSpecification(),iObj.getQuantity(),iObj.getRemark(), payload.getUsername(), SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
}

int ProcessBOMDAO::update(const ProRouteProductBomDO& uObj, const PayloadDTO& payload)
{
	string sql = "UPDATE `pro_route_product_bom` SET `item_code`=?, `item_name`=?, `unit_of_measure`=?, `specification`=?, `quantity`=?, `remark`=?, `update_by`=?, `update_time`=? WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%d%s%s%s%ull", uObj.getItem_code(), uObj.getItem_name(), uObj.getUnit_of_measure(), uObj.getSpecification(), uObj.getQuantity(), uObj.getRemark(), payload.getUsername(), SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"), uObj.getRecord_id());
}