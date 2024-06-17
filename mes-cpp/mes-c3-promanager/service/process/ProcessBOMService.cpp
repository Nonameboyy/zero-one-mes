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
#include "ProcessBOMService.h"
#include "../../dao/process/ProcessBOMDAO.h"
#include"../../domain/do/pro/ProRouteProductBomDO.h"

bool ProcessBOMService::removeBOM(uint64_t id)
{
	ProcessBOMDAO dao;
	return dao.deleteById(id) == 1;
}
uint64_t ProcessBOMService::saveBOM(const ProductMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	ProRouteProductBomDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Route_id, route_id, Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Specification, specification, Quantity, quantity, Remark, remark)
		// 执行数据修改
		ProcessBOMDAO dao;
	return dao.insert(data, payload);
}
bool ProcessBOMService::updateBOM(const ProductModefyMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	ProRouteProductBomDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Record_id, record_id, Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Specification, specification, Quantity, quantity, Remark, remark)
		// 执行数据修改
		ProcessBOMDAO dao;
	return dao.update(data, payload) == 1;
}