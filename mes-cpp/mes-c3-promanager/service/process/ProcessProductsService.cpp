#include "stdafx.h"
#include "ProcessProductsService.h"
#include "../../dao/process/ProcessProductsDAO.h"
#include"../../mes-c3-promanager/domain/do/pro/ProRouteProductDO.h"

ProductsPageDTO::Wrapper ProcessProductsService::listAll(const ProcessProductsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProductsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProcessProductsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProRouteProductDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProRouteProductDO sub : result)
	{
		auto dto = ProcessProductsDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, routeid, Route_Id, item_code, Item_Code, item_name, Item_Name, specification, Specification, unit_of_measure, Unit_Of_Measure)
			pages->addData(dto);

	}
	return pages;
}