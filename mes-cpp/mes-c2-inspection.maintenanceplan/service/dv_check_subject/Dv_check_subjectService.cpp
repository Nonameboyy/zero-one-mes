#include "stdafx.h"
//删除plan
//返回值
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//输入值
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
//作用域
#include "../../service/dv_check_subject/Dv_check_subjectService.h"
//DAO，DO在DAO里面包含过了
#include "../../dao/dv_check_subject/Dv_check_subjectDAO.h"

DeletePlanSubjectQueryDTO::Wrapper Dv_check_subjectService::listAll(const DeletePlanSubjectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DeletePlanSubjectQueryDTO::createShared();
	// 查询数据总条数
	Dv_check_subjectDAO dao;
	// 分页查询数据
	list<DvCheckSubjectDO> result = dao.selectWithPage(query);//这里好像是数据库读取的结果，我这里最多读取一次

	for (DvCheckSubjectDO sub : result)
	{
		auto dto = DeletePlanSubjectQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			record_id, Record_id, plan_id, Plan_id, subject_id, Subject_id,
			subject_code, Subject_code, subject_name, Subject_name);
		//pages->addData(dto);
		pages = dto;
	}
	return pages;
}

bool Dv_check_subjectService::dv_check_subjectRemoveData(int64_t id)
{
	Dv_check_subjectDAO dao;
	return dao.dv_check_subjectDeleteById(id) == 1;
}

