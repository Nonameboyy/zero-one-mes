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
#include "MaterialProductsService.h"
#include "../../../domain/do/DetectionTemplate/MaterialProductsDO.h"
#include "../../../dao/DetectionTemplate/MaterialProducts/MaterialProductsDAO.h"
MaterialProductsPageDTO::Wrapper MaterialProductsService::listAll(const MaterialProductsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MaterialProductsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MaterialProductsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MaterialProductsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MaterialProductsDO sub : result)
	{
		auto dto = MaterialProductsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(
			dto, sub,
			item_code, item_code,
			item_name, item_name,
			specification, specification,
			quantity_check, quantity_check,
			unit_of_measure, unit_of_measure,
			quantity_unqualified, quantity_unqualified,
			cr_rate, cr_rate,
			maj_rate, maj_rate,
			min_rate, min_rate,
			remark, remark
		);
		pages->addData(dto);

	}
	return pages;
	//return {};
}

uint64_t MaterialProductsService::saveMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// 组装DO数据
	MaterialProductsDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	data.setrecord_id(dto->record_id.getValue(1));
	data.setitem_code(dto->item_code.getValue(""));
	data.setitem_name(dto->item_name.getValue(""));
	data.setspecification(dto->specification.getValue(""));
	data.setunit_of_measure(dto->unit_of_measure.getValue(""));
	data.setquantity_check(dto->quantity_check.getValue(6));
	data.setquantity_unqualified(dto->quantity_unqualified.getValue(7));
	data.setcr_rate(dto->cr_rate.getValue(8));
	data.setmaj_rate(dto->maj_rate.getValue(9));
	data.setmin_rate(dto->min_rate.getValue(11));
	data.setremark(dto->remark.getValue(""));
	/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, templateId, templateId, itemCode, itemCode, itemName, itemName)*/
	// 执行数据添加
	MaterialProductsDAO dao;
	return dao.insertMaterialProducts(data);
}

bool MaterialProductsService::updateMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// 组装DO数据
	MaterialProductsDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	data.setrecord_id(dto->record_id.getValue(1));
	data.setitem_code(dto->item_code.getValue(""));
	data.setitem_name(dto->item_name.getValue(""));
	data.setspecification(dto->specification.getValue(""));
	data.setunit_of_measure(dto->unit_of_measure.getValue(""));
	data.setquantity_check(dto->quantity_check.getValue(6));
	data.setquantity_unqualified(dto->quantity_unqualified.getValue(7));
	data.setcr_rate(dto->cr_rate.getValue(8));
	data.setmaj_rate(dto->maj_rate.getValue(9));
	data.setmin_rate(dto->min_rate.getValue(11));
	data.setremark(dto->remark.getValue(""));
	/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, templateId, templateId, itemCode, itemCode, itemName, itemName)*/
	// 执行数据修改
	MaterialProductsDAO dao;
	return dao.updateMaterialProducts(data) == 1;
}

bool MaterialProductsService::deleteByRecordId(const oatpp::List<oatpp::UInt64>& record_ids)
{
	if (record_ids->empty()) {
		return false; 
	}

	MaterialProductsDAO dao;
	int result = dao.deleteByRecordId(record_ids);


	return result == record_ids->size();
}

