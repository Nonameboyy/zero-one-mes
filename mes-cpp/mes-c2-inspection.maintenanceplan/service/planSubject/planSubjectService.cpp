//#include "stdafx.h"
////#include "PlanSubjectService.h"
////#include "../../dao/planSubject/PlanSubjectDAO.h"
////#include <domain/do/planSubject/PlanSubjectDO.h>
//
////删除plan
////返回值
//#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
////输入值
//#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
////作用域
//#include "../../service/dv_check_plan/Dv_check_planService.h"
////DAO
//#include "../../dao/dv_check_plan/Dv_check_planDAO.h"
//
//
////PlanSubjectDetailPageDTO::Wrapper PlanSubjectService::listAll(const PlanSubjectQuery::Wrapper& query)
////{
////	// 构建返回对象
////	auto pages = PlanSubjectDetailPageDTO::createShared();
////	pages->pageIndex = query->pageIndex;
////	pages->pageSize = query->pageSize;
////
////	// 查询数据总条数
////	PlanSubjectDAO dao;
////	uint64_t count = dao.count(query);
////	if (count <= 0)
////	{
////		return pages;
////	}
////
////	// 分页查询数据
////	pages->total = count;
////	pages->calcPages();
////	list<PlanSubjectTableDO> result = dao.selectWithPage(query);
////	// 将DO转换成DTO
////	for (PlanSubjectTableDO sub : result)
////	{
////		auto dto = PlanSubjectDTO::createShared();
////		// 		dto->id = sub.getId();
////		// 		dto->name = sub.getName();
////		// 		dto->sex = sub.getSex();
////		// 		dto->age = sub.getAge();
////		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
////			pages->addData(dto);
////
////	}
////	return pages;
////}
////
////uint64_t PlanSubjectService::saveData(const PlanSubjectDTO::Wrapper& dto)
////{
////	// 组装DO数据
////	PlanSubjectTableDO data;
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
////		// 执行数据添加
////		PlanSubjectDAO dao;
////	return dao.insert(data);
////}
////
////bool PlanSubjectService::updateData(const PlanSubjectDTO::Wrapper& dto)
////{
////	// 组装DO数据
////	PlanSubjectTableDO data;
////	// 	data.setId(dto->id.getValue(0));
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
////		// 执行数据修改
////		PlanSubjectDAO dao;
////	return dao.update(data) == 1;
////}
////
////bool PlanSubjectService::removeData(uint64_t id)
////{
////	PlanSubjectDAO dao;
////	return dao.deleteById(id) == 1;
////}
//
//DeletePlanQueryDTO::Wrapper Dv_check_planService::listAll(const DeletePlanQuery::Wrapper& query)
//{
//	// 构建返回对象
//	auto pages = DeletePlanQueryDTO::createShared();
//	// 查询数据总条数
//	Dv_check_planDAO dao;
//	// 分页查询数据
//	list<Dv_check_planDO> result = dao.selectWithPage(query);//这里好像是数据库读取的结果，我这里最多读取一次
//	// 将DO转换成DTO
//	//for (Dv_check_planDO sub : result)
//	//{
//	//	auto dto = DeletePlanQueryDTO::createShared();
//	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, code, Code, name, Name, type, Type, content, Content, standard, Standard);
//	//	pages->addData(dto);
//	//}
//	//return pages;
//		for (Dv_check_planDO sub : result)
//	{
//		auto dto = DeletePlanQueryDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, plan_id, Plan_id,
//			plan_code, Plan_code, plan_name,Plan_name);
//		//pages->addData(dto);
//		pages = dto;
//	}
//	return pages;
//}
//
//
////uint64_t PlanSubjectService::saveData(const PlanSubjectTableDTO::Wrapper& dto)
////{
////	// 组装DO数据
////	PlanSubjectTableDO data;
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Type, type, Content, content, Standard, standard)
////		// 执行数据添加
////		PlanSubjectDAO dao;
////	return dao.insert(data);
////}
////
////bool PlanSubjectService::updateData(const PlanSubjectTableDTO::Wrapper& dto)
////{
////	// 组装DO数据
////	PlanSubjectTableDO data;
////	// 	data.setId(dto->id.getValue(0));
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Type, type, Content, content, Standard, standard, Code, code)
////		// 执行数据修改
////		PlanSubjectDAO dao;
////	return dao.update(data) == 1;
////}
////
//
//bool Dv_check_planService::dv_check_planRemoveData(int64_t id)
//{
//	Dv_check_planDAO dao;
//	return dao.dv_check_planDeleteById(id) == 1;
//}
//
//bool Dv_check_planService::dv_check_machineryRemoveDataIDP(int64_t idp)
//{
//	Dv_check_planDAO dao;
//	return dao.dv_check_machineryDeleteByIdPlan(idp) == 1;
//}
//
//bool Dv_check_planService::dv_check_subjectRemoveDataIDP(int64_t idp)
//{
//	Dv_check_planDAO dao;
//	return dao.dv_check_subjectDeleteByIdPlan(idp) == 1;
//}



