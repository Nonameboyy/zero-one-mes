#include "stdafx.h"
#include "MachineryPlanService.h"
#include "../../dao/query-ForeverOMC/MachineryPlanDAO.h"

MachineryPlanPageDTO::Wrapper MachineryPlanService::listAll(const MachineryPlanQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MachineryPlanPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MachineryPlanDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<Dv_check_planDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (Dv_check_planDO sub : result)
	{
		auto dto = MachineryPlanDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, plan_id, Plan_id, plan_code, Plan_code, plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date, end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count, status, Status);
		pages->addData(dto);
	}
	return pages;
}

MachineryPlanDetailsDTO::Wrapper MachineryPlanService::getDetails(const MachineryPlanDetailsQuery::Wrapper& query)
{
	// �������ض���
	auto dto = MachineryPlanDetailsDTO::createShared();
	
	// ��ѯ����
	MachineryPlanDAO dao;
	list<Dv_check_planDO> sub = dao.selectByPlanId(query);

	if (sub.empty())
		return dto;

	// ȡ������
	Dv_check_planDO res = sub.front();

	// ��DOת����DTO
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, res, plan_id, Plan_id, plan_code, Plan_code, plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date, end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count, status, Status, remark, Remark);
	
	return dto;
}