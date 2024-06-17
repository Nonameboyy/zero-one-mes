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
#include "EquipmentTypeDAO.h"

int EquipmentTypeDAO::update(const EquipmentTypeDO& uObj)
{
	string sql = "UPDATE `dv_machinery_type` SET `machinery_type_name`=?, `parent_type_id`=?, `remark`=?,`enable_flag`=?,`update_time`=? WHERE `machinery_type_id`=?";
	return sqlSession->executeUpdate(sql, "%s%ull%s%s%s%ull", uObj.getName(), uObj.getParentId(), uObj.getRemark(), uObj.getEnable(), uObj.getUpdateTime(), uObj.getId());
}

int EquipmentTypeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `dv_machinery_type` WHERE `machinery_type_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

uint64_t EquipmentTypeDAO::countByPId(uint64_t id)
{
	string sql = "SELECT count(*) FROM `dv_machinery_type` WHERE 1=1 AND parent_type_id=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "i", uint64_t, id);
	return sqlSession->executeQueryNumerical(sql, params);
}
 
// 