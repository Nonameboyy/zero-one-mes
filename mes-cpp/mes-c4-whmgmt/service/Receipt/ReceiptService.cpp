#include "stdafx.h"
#include "ReceiptService.h"
#include "../../dao/Receipt/ReceiptDAO.h"
#include "../../domain/do/Receipt/ReceiptDO.h"
#include <list>

ReceiptPageTableDTO::Wrapper ReceiptService::listAll(const ReceiptTableQuery::Wrapper& query)
{
	auto pages = ReceiptPageTableDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	ReceiptPageTableDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}
	
	pages->total = count;
	pages->calcPages();
	std::list<ReceiptPageTableDO> result = dao.selectWithPage(query);

	// 将DO转换成DTO
	for (ReceiptPageTableDO sub : result)
	{
		auto dto = ReceiptDTO::createShared();

		dto->recptId = sub.getRecptId(); 
		dto->recptCode = sub.getRecptCode(); 
		dto->recptName = sub.getRecptName(); 
		dto->vendorName = sub.getVendorName(); 
		dto->poCode = sub.getPoCode(); 
		dto->recptDate = sub.getRecptDate(); 
		dto->status = sub.getStatus();

		pages->addData(dto);

	}

	return pages;
}

ReceiptDetailDTO::Wrapper ReceiptService::getDetail(const ReceiptDetailQuery::Wrapper& query)
{
	
	ReceiptDetailDAO dao;
	auto result = dao.selectByRecptCode(query);

	// 将DO转换成DTO
	auto detail = ReceiptDetailDTO::createShared();

	detail->recptId = result.getRecptId();
	detail->recptCode = result.getRecptCode();
	detail->recptName = result.getRecptName();
	detail->vendorName = result.getVendorName();
	detail->poCode = result.getPoCode();
	detail->recptDate = result.getRecptDate();
	detail->status = result.getStatus();
	detail->warehouseName = result.getWarehouseName();
	detail->remark = result.getRemark();


	return detail;
}
