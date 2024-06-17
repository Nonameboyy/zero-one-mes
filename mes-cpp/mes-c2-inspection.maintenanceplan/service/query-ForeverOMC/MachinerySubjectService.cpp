#include "stdafx.h"
#include "MachinerySubjectService.h"
#include "../../dao/query-ForeverOMC/MachinerySubjectDAO.h"

MachinerySubjectPageDTO::Wrapper MachinerySubjectService::listAll(const MachinerySubjectQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MachinerySubjectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MachinerySubjectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DvCheckSubjectDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (DvCheckSubjectDO sub : result)
	{
		auto dto = MachinerySubjectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, Record_id, subject_code, Subject_code, subject_name, Subject_name, subject_type, Subject_type, subject_content, Subject_content, subject_standard, Subject_standard);
		pages->addData(dto);
	}
	return pages;
}