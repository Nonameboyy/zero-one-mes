#include "stdafx.h"
#include "MachineryListService.h"
#include "../../dao/query-ForeverOMC/MachineryListDAO.h"

MachineryListPageDTO::Wrapper MachineryListService::listAll(const MachineryListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MachineryListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MachineryListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Dv_check_machineryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Dv_check_machineryDO sub : result)
	{
		auto dto = MachineryListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, machinery_code, Machinery_code, machinery_name, Machinery_name, machinery_brand, Machinery_brand, machinery_spec, Machinery_spec, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}