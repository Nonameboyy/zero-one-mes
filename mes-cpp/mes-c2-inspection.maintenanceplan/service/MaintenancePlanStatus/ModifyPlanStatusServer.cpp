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
#include "ModifyPlanStatusServer.h"
#include "../../dao/ModifyPlanStatus/ModifyPlanStatusDao.h"
#include"./domain/do/ModifyPlanStatus/ModifyPlanStatusDo.h"
#include <SimpleDateTimeFormat.h>

bool ModifyPlanStatusService::updateData(const ModifyPlanStatusDto::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ModifyPlanStatusDo data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	/*data.setId(dto->id.getValue(0));
	data.setStatus(dto->status.getValue(""));*/
	data.setUpdateby(payload.getUsername());
	data.setUpdatetime(SimpleDateTimeFormat::format());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Status, status)
	// 执行数据修改
	ModifyPlanStatusDao dao;
	return dao.update(data) == 1;
}
