#include "stdafx.h"
#include "MachineryPlanService.h"
#include "../../dao/query-ForeverOMC/MachineryPlanDAO.h"

MachineryPlanPageDTO::Wrapper MachineryPlanService::listAll(const MachineryPlanQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MachineryPlanPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MachineryPlanDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Dv_check_planDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
	// 构建返回对象
	auto dto = MachineryPlanDetailsDTO::createShared();
	
	// 查询数据
	MachineryPlanDAO dao;
	list<Dv_check_planDO> sub = dao.selectByPlanId(query);

	if (sub.empty())
		return dto;

	// 取出数据
	Dv_check_planDO res = sub.front();

	// 将DO转换成DTO
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, res, plan_id, Plan_id, plan_code, Plan_code, plan_name, Plan_name, plan_type, Plan_type, start_date, Start_date, end_date, End_date, cycle_type, Cycle_type, cycle_count, Cycle_count, status, Status, remark, Remark);
	
	return dto;
}