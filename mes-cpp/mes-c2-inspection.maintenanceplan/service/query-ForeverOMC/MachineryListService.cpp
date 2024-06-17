#include "stdafx.h"
#include "MachineryListService.h"
#include "../../dao/query-ForeverOMC/MachineryListDAO.h"

MachineryListPageDTO::Wrapper MachineryListService::listAll(const MachineryListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MachineryListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MachineryListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<Dv_check_machineryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (Dv_check_machineryDO sub : result)
	{
		auto dto = MachineryListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, machinery_code, Machinery_code, machinery_name, Machinery_name, machinery_brand, Machinery_brand, machinery_spec, Machinery_spec, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}