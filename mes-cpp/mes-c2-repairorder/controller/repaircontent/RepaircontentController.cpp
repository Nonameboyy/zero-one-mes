	/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/18 23:42

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
#include "RepaircontentController.h"
#include "../../service/repaircontent/RepaircontentService.h"
#include "../ApiDeclarativeServicesHelper.h"

RepaircontentPageJsonVO::Wrapper RepaircontentController::execQueryRepaircontent(const RepaircontentQuery::Wrapper& query)
{
	//...
	// 定义一个Service
	RepaircontentService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RepaircontentPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RepaircontentJsonVO::Wrapper RepaircontentController::execDetailsRepaircontent(const RepaircontentQuery::Wrapper& id)
{
	//...
	// 定义返回数据对象
	auto jvo = RepaircontentJsonVO::createShared();
	// 参数校验
	if (id->repair_id <= 0) {
		jvo->fail(RepaircontentDTO::Wrapper());
		return jvo;
	}
	// 定义一个Service
	RepaircontentService service;
	// 执行数据查询
	auto dto = service.getData(id);
	jvo->success(dto);
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper RepaircontentController::execAddRepaircontent(const AddRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	 //非空校验
	if (!dto->repair_id || 
		!dto->subject_id ||
		!dto->malfunction ||
		!dto->malfunction_url ||
		!dto->repair_des) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->repair_id < 0 || dto->subject_id<0 || dto->malfunction->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepaircontentService service;
	// 执行数据新增
	uint64_t res = service.saveData(dto,payload);
	if (res > 0) {
		jvo->success(res);
	}
	else {
		jvo->fail(res);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper RepaircontentController::execModifyRepaircontent(const ModifyRepaircontentDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 非空校验
	if ( !dto->line_id ||
		!dto->subject_id ||
		!dto->repair_des ||
		!dto->malfunction ||
		!dto->malfunction_url)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RepaircontentService service;
	// 执行数据新增
	if (service.updateData(dto,payload)) {
		jvo->success(dto->line_id);
	}
	else {
		jvo->fail(dto->line_id);
	}
	// 响应结果
	return jvo;


}

Uint64JsonVO::Wrapper RepaircontentController::execRemoveRepaircontent(const DeleteMultiRepaircontentDTO::Wrapper& id)
{
	auto jvo = Uint64JsonVO::createShared();

	uint64_t cnt = 0; // 执行成功计数
	// 定义一个Service
	RepaircontentService service;
	for (const uint64_t& it : *id->line_idList) { // 不用校验, 失败不管 (隐藏字段, 一般不会有问题)
		if (it) {
			cnt += service.removeData(it);
		}
	}
	jvo->success(cnt);
	// 响应结果
	return jvo;
}

