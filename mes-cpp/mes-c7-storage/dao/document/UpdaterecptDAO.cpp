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
#include "UpdaterecptDAO.h"
#include <sstream>

int UpdaterecptDAO::update(const Wm_product_recptDO& uObj)
{
	string sql = "UPDATE `wm_product_recpt` SET `recpt_code`=?, `recpt_name`=?, `workorder_code`=?,`workorder_name`=?,`recpt_date`=?,`remark`=? WHERE `recpt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%ull", uObj.getRecpt_code(), uObj.getRecpt_name(), uObj.getWorkorder_code(), uObj.getWorkorder_name(),uObj.getRecpt_date(),uObj.getRemark(),uObj.getRecpt_id());
}
