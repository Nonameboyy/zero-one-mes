#include "stdafx.h"
#include "MachinerySubjectService.h"
#include "../../dao/query-ForeverOMC/MachinerySubjectDAO.h"

MachinerySubjectPageDTO::Wrapper MachinerySubjectService::listAll(const MachinerySubjectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MachinerySubjectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MachinerySubjectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DvCheckSubjectDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DvCheckSubjectDO sub : result)
	{
		auto dto = MachinerySubjectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, subject_code, Subject_code, subject_name, Subject_name, subject_type, Subject_type, subject_content, Subject_content, subject_standard, Subject_standard);
		pages->addData(dto);
	}
	return pages;
}