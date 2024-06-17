#include "stdafx.h"
#include "HumanResourceListService.h"
#include "../../dao/humanresource/HumanResourceListDAO.h"

HumanResourcePageDTO::Wrapper HumanResourceListService::listAll(const HumanResourceListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = HumanResourcePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	HumanResourceListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<HumanResourceListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	HumanResourceListDO data;
	//����Ҫrecordid�����Զ�����
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PostName, postName, Quantity, quantity, WorkstationId, workstationId, PostId, postId)
		// ִ���������
		HumanResourceListDAO dao;
	return dao.insert(data);
}

bool HumanResourceListService::updateData(const HumanResourceListDTO::Wrapper& dto)
{
	// ��װDO����
	HumanResourceListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PostName, postName, Quantity, quantity, RecordId, recordId, WorkstationId, workstationId, PostId, postId)
		// ִ�������޸�
		HumanResourceListDAO dao;
	return dao.update(data) == 1;
}

bool HumanResourceListService::removeData(uint64_t recordId)
{
	HumanResourceListDAO dao;
	return dao.deleteById(recordId) == 1;
}
