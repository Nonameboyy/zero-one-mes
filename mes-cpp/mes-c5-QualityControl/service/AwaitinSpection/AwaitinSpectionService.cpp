#include "stdafx.h"
#include "AwaitinSpectionService.h"

AwaitinSpectionPageDTO::Wrapper AwaitinSpectionService::listAll(const AwaitinSpectionQuery::Wrapper& query)
{
	auto pages = AwaitinSpectionPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	AwaitinSpectionDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)	return pages;
	pages->total = count;
	pages->calcPages();
	list<AwaitinSpectionDO> res = dao.selectAwaitinSpectionWithPage(query);

	for (AwaitinSpectionDO sub : res) {
		auto dto = AwaitinSpectionDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, feedback_code, Feedback_code, feedback_type, Feedback_type, item_code, Item_code, item_name, Item_name, quantity_uncheck, Quantity_uncheck, workstation_name, Workstation_name);
		pages->addData(dto);
	}
	return pages;
	return {};
}