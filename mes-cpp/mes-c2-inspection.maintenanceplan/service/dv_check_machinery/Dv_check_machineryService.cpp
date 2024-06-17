#include "stdafx.h"
//删除plan
//返回值
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//输入值
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
//作用域
#include "../../service/dv_check_machinery/Dv_check_machineryService.h"
//DAO，DO在DAO里面包含过了
#include "../../dao/dv_check_machinery/Dv_check_machineryDAO.h"

DeletePlanMachineryQueryDTO::Wrapper Dv_check_machineryService:: listAll(const DeletePlanMachineryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DeletePlanMachineryQueryDTO::createShared();
	// 查询数据总条数
	Dv_check_machineryDAO dao;
	// 分页查询数据
	list<Dv_check_machineryDO> result = dao.selectWithPage(query);//这里好像是数据库读取的结果，我这里最多读取一次

	for (Dv_check_machineryDO sub : result)
	{
		auto dto = DeletePlanMachineryQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			record_id, Record_id, plan_id, Plan_id, machinery_id, Machinery_id,
			machinery_code, Machinery_code, machinery_name, Machinery_name);
		pages = dto;
	}
	return pages;
}

bool Dv_check_machineryService::dv_check_machineryRemoveData(int64_t id)
{
	Dv_check_machineryDAO dao;
	return dao.dv_check_machineryDeleteById(id) == 1;
}
