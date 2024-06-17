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
#include "ProductRecptService.h"
#include "dao/item-information/ProductRecptDAO.h"

ProductRecptPageDTO::Wrapper ProductRecptService::listAll(const ProductRecptQuery::Wrapper& query)
{
	//�������ض���PageDTO
	auto pages = ProductRecptPageDTO::createShared();
	pages->pageIndex = query->pageIndex;//��ȡ��ҳ��ѯ�Ĳ���:�ڼ�ҳ
	pages->pageSize = query->pageSize;//��ȡÿҳ��С

	//��ѯwm_product_recpt
	ProductRecptDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;//��¼����query������
	pages->calcPages();//����pagesize����һ���ж���ҳ
	list<ProductRecptDO> result = dao.selectWithPage(query);
	//DO->DTO
	for (ProductRecptDO sub : result)
	{
		auto dto = ProductRecptDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recpt_code, RecptCode, recpt_name, RecptName, workorder_code, WorkorderCode, workorder_name, WorkorderName, recpt_date, RecptDate, remark, Remark, item_id,ItemId);
		pages->addData(dto);
	}
	return pages;
}
uint64_t ProductRecptService::saveData(const ProductRecptDTO::Wrapper& dto)
{
	// ��װDO����
	ProductRecptDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RecptCode, recpt_code, RecptName, recpt_name, WorkorderCode, workorder_code, WorkorderName, workorder_name, RecptDate, recpt_date, Remark, remark, ItemId, item_id);
	// ִ���������
	ProductRecptDAO dao;
	return dao.insert(data);
}

bool ProductRecptService::removeData(uint64_t id)
{
	ProductRecptDAO dao;
	return dao.deleteById(id) == 1;
}

bool ProductRecptService::updateData(const ProductRecptDTO::Wrapper& dto)
{
	// ��װDO����
	ProductRecptDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RecptCode, recpt_code, RecptName, recpt_name, WorkorderCode, workorder_code, WorkorderName, workorder_name, RecptDate, recpt_date, Remark, remark, ItemId, item_id);
	// ִ�������޸�
	ProductRecptDAO dao;
	return dao.update(data) == 1;
}
