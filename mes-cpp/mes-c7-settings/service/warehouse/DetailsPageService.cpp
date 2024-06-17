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
#include "DetailsPageService.h"
#include "../../dao/warehouse/DetailsPageDAO.h"
DetailsPageDTO::Wrapper DetailsPageService::listAll(const DetailsPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DetailsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DetailsPageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<Wm_WarehouseDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (Wm_WarehouseDO sub : result)
	{
		auto dto = DetailsDTO::createShared();
		dto->warehouse_code = sub.getWarehouse_code();
		dto->warehouse_name = sub.getWarehouse_name();
		dto->location = sub.getLocation();
		dto->area = sub.getArea();
		dto->charge = sub.getCharge();
		dto->remark = sub.getRemark();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_code, Warehouse_code);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_name, Warehouse_name ,location, Location);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, area, Area, charge, Charge, remark, Remark);
			pages->addData(dto);
	}
	return pages;
}

