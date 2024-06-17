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
#include "MaterialInformationController.h"
#include "../../service/materialinformation/MaterialInformationService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper MaterialInformationController::execAddMaterialInformation(const MaterialInformationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->rt_id || !dto->rt_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	std::istringstream iss(dto->rt_date);
	std::tm tm = {};
	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (dto->rt_code->empty() || iss.fail())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MaterialInformationService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper MaterialInformationController::execModifyMaterialInformation(const MaterialInformationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->rt_id || !dto->rt_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	std::istringstream iss(dto->rt_date);
	std::tm tm = {};
	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (dto->rt_code->empty() || iss.fail())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MaterialInformationService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->rt_id);
	}
	else
	{
		jvo->fail(dto->rt_id);
	}
	// 响应结果
	return jvo;
}

MaterialInformationPageJsonVO::Wrapper MaterialInformationController::execQuerySample(const MaterialInformationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	MaterialInformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MaterialInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MaterialInformationController::execRemoveMaterialInformation(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MaterialInformationService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
