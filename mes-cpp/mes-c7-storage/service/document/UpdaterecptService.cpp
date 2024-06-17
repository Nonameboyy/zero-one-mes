/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "UpdaterecptService.h"
#include "../../dao/document/UpdaterecptDAO.h"


bool UpdaterecptService::updateData(const UpdaterecptDTO::Wrapper& dto)
{
	// 组装DO数据
	Wm_product_recptDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Recpt_code, recpt_code, Recpt_date, recpt_date, Recpt_name, recpt_name, Remark, remark, Workorder_code, workorder_code, Workorder_name, workorder_name,Recpt_id,recpt_id)
		// 执行数据修改
		UpdaterecptDAO dao;
	return dao.update(data) == 1;
}


