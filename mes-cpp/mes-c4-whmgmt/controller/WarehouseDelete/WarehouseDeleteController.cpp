/*
 Copyright Zero One Star. All rights reserved.

 @Author: xinye
 @Date: 2024/5/22 23:00:00

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
#include "WarehouseDeleteController.h"
#include "../../service/WarehouseDelete/WarehouseDeleteService.h"

Uint64JsonVO::Wrapper WarehouseDeleteController::execWarehouseDelete(const WarehouseDeleteDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (dto->recpt_id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WarehouseDeleteService service;
	// 执行数据修改
	if (service.WarehouseDelete(dto)) {
		jvo->success(UInt64(1));
		jvo->message = "The file was deleted successfully!";
	}
	else
	{
		jvo->fail(UInt64(-1));
		jvo->message = "Error!";
	}
	// 响应结果
	return jvo;
}
