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
#include "ModifyPlanStatusDao.h"
#include "ModifyPlanStatusMapper.h"
#include "../../domain/dto/ModifyPlanStatus/ModifyPlanStatusDto.h"
#include <sstream>

////定义条件解析宏，减少重复代码
//#define SAMPLE_TERAM_PARSE(query, sql) \
//SqlParams params; \
//sql<<" WHERE 1=1"; \
//if (query->name) { \
//	sql << " AND `name`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
//} \
//if (query->sex) { \
//	sql << " AND sex=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
//} \
//if (query->age) { \
//	sql << " AND age=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
//}


int ModifyPlanStatusDao::update(const ModifyPlanStatusDo& uObj)
{
	string sql = "UPDATE `dv_check_plan` SET `status`=?,`updateby`=?,`updatetime`=? WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%ull",  uObj.getStatus(), uObj.getUpdateby(), uObj.getUpdatetime(), uObj.getId());
}
