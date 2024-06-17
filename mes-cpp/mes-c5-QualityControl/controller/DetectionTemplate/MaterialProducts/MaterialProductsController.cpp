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
#include "MaterialProductsController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/DetectionTemplate/MaterialProducts/MaterialProductsService.h"

MaterialProductsPageJsonVO::Wrapper MaterialProductsController::execMaterialProducts(const MaterialProductsQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	MaterialProductsService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MaterialProductsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}

Uint64JsonVO::Wrapper MaterialProductsController::execModifyMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MaterialProductsService service;
	// 执行数据修改
	if (service.updateMaterialProducts(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper MaterialProductsController::execRemoveMaterialProduct(const oatpp::List<oatpp::UInt64>& record_ids)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 参数校验
	if (record_ids->empty()) {
		jvo->init(oatpp::UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MaterialProductsService service;

	// 执行数据删除
	if (service.deleteByRecordId(record_ids)) {
		
			jvo->init(oatpp::UInt64(1), RS_SUCCESS);  // 假设 success 方法能够处理单个 id
			return jvo;
	}
	else {
		
			jvo->init(oatpp::UInt64(1), RS_FAIL);  // 假设 fail 方法能够处理单个 id
		
	}

	// 响应结果
	return jvo;
}
	



Uint64JsonVO::Wrapper MaterialProductsController::execAddMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->record_id || !dto->item_code || !dto->item_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->record_id < 0 || dto->item_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	MaterialProductsService service;
	// 执行数据新增
	uint64_t record_id = service.saveMaterialProducts(dto);
	if (record_id > 0) {
		jvo->success(UInt64(record_id));
	}
	else
	{
		jvo->fail(UInt64(record_id));
	}
	//响应结果
	return jvo;
}