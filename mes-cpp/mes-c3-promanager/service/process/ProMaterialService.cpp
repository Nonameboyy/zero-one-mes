#include "stdafx.h"
#include "ProMaterialService.h"
#include "../../dao/process/ProMaterialDAO.h"

//分页查询条件查询 产品制成物料表
ProMaterialPageDTO::Wrapper ProMaterialService::listAll(const ProMaterialQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ProMaterialPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProMaterialDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProRouteProductBomDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProRouteProductBomDO sub : result)
	{
		auto dto = ProMaterialDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, item_code, Item_code, item_name, Item_name, specification, Specification, unit_of_measure, Unit_of_measure, quantity, Quantity)
			pages->addData(dto);

	}
	return pages;
}
