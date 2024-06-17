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
#include "AddrecptDAO.h"
#include "AddrecptMapper.h"
#include <sstream>

uint64_t AddrecptDAO::insert(const Wm_product_recptDO& iObj)
{
	string sql = "INSERT INTO `wm_product_recpt` (`recpt_code`, `recpt_date`,`recpt_name`,`remark`,`workorder_code`,`workorder_id`,`workorder_name`,`item_id`) VALUES ( ?, ?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%i%s%i", iObj.getRecpt_code(), iObj.getRecpt_date(), iObj.getRecpt_name(), iObj.getRemark(), iObj.getWorkorder_code(), iObj.getWorkorder_id(), iObj.getWorkorder_name(),iObj.getItem_id());
}

//int SampleDAO::update(const SampleDO& uObj)
//{
//	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
//	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
//}

