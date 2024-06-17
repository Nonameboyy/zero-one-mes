#include "stdafx.h"
#include "ProMaterialService.h"
#include "../../dao/process/ProMaterialDAO.h"

//��ҳ��ѯ������ѯ ��Ʒ�Ƴ����ϱ�
ProMaterialPageDTO::Wrapper ProMaterialService::listAll(const ProMaterialQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProMaterialPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProMaterialDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProRouteProductBomDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProRouteProductBomDO sub : result)
	{
		auto dto = ProMaterialDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, item_code, Item_code, item_name, Item_name, specification, Specification, unit_of_measure, Unit_of_measure, quantity, Quantity)
			pages->addData(dto);

	}
	return pages;
}
