#include "stdafx.h"
#include "HumanResourceListService.h"
#include "../../dao/humanresource/HumanResourceListDAO.h"

HumanResourcePageDTO::Wrapper HumanResourceListService::listAll(const HumanResourceListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = HumanResourcePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	HumanResourceListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<HumanResourceListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (HumanResourceListDO sub : result)
	{
		auto dto = HumanResourceListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, postName, PostName, quantity, Quantity, recordId, RecordId, workstationId, WorkstationId, postId, PostId)
			pages->addData(dto);
	}
	return pages;
}

uint64_t HumanResourceListService::saveData(const HumanResourceListDTO::Wrapper& dto)
{
	// 组装DO数据
	HumanResourceListDO data;
	//不需要recordid，会自动增加
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PostName, postName, Quantity, quantity, WorkstationId, workstationId, PostId, postId)
		// 执行数据添加
		HumanResourceListDAO dao;
	return dao.insert(data);
}

bool HumanResourceListService::updateData(const HumanResourceListDTO::Wrapper& dto)
{
	// 组装DO数据
	HumanResourceListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PostName, postName, Quantity, quantity, RecordId, recordId, WorkstationId, workstationId, PostId, postId)
		// 执行数据修改
		HumanResourceListDAO dao;
	return dao.update(data) == 1;
}

bool HumanResourceListService::removeData(uint64_t recordId)
{
	HumanResourceListDAO dao;
	return dao.deleteById(recordId) == 1;
}
