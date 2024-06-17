/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/18 20:16:53

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
#include "EquipmentController.h"
#include"service/equipment/EquipmentService.h"

EquipmentPageJsonVO::Wrapper EquipmentController::execEquipment(const EquipmentQuery::Wrapper& query)
{
	// 定义一个Service
	EquipmentService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EquipmentPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

EquipmentDetailJsonVO::Wrapper EquipmentController::execEquipmentDetail(const EquipmentDetailQuery::Wrapper& query)
{
	// 定义一个Service
	EquipmentService service;
	// 查询数据
	auto result = service.getDetail(query);
	// 响应结果
	auto jvo = EquipmentDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper EquipmentController::execAddEquipment(const addEquipmentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->eCode || !dto->eName || !dto->tId  || !dto->workshopId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->eCode->empty() || dto->eName->empty()  || dto->tId<0 || dto->workshopId<0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EquipmentService service;
	// 执行数据新增
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

Uint64JsonVO::Wrapper EquipmentController::executeModifyEquipment(const modifyEquipmentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->eId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->eId<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EquipmentService service;
	// 执行数据
	uint64_t id = service.modifyData(dto,payload);
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
