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
#include "RemoveDeviceController.h"
#include "service/RemoveDevice/RemoveDeviceService.h"

BooleanJsonVO::Wrapper RemoveDeviceController::execRemoveDevice(const RemoveDeviceListDTO::Wrapper& dto)
{
	// 定义返回结果
	auto res = BooleanJsonVO::createShared();

	// 数据校验
	if (dto->item->empty()) {
		res->init(false, ResultStatus(u8"删除列表为空"));
		return res;
	}

	// 调用service层
	RemoveDeviceService service;
	auto flag = service.removeDevice(dto);
	 
	if (flag) // 删除成功
		res->success(flag);
	else
		res->fail(flag);
	return res;
}