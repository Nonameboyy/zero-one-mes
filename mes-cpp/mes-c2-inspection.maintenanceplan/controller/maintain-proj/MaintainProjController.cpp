/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "MaintainProjController.h"

#include "../ApiDeclarativeServicesHelper.h"
#include"../mes-c2-inspection.maintenanceplan/service/AddProject/AddprojectService.h"

Uint64JsonVO::Wrapper MaintainProjController::execAddProj(const MaintainProjDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->planId||!dto->machineryId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return  jvo;
	}

	// 定义一个Service
	AddprojectService service;
	uint64_t id = service.saveData(dto,payload);
	if (id > 0)
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}


