//#include "stdafx.h"
////#include "PlanSubjectService.h"
////#include "../../dao/planSubject/PlanSubjectDAO.h"
////#include <domain/do/planSubject/PlanSubjectDO.h>
//
////ɾ��plan
////����ֵ
//#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
////����ֵ
//#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
////������
//#include "../../service/dv_check_plan/Dv_check_planService.h"
////DAO
//#include "../../dao/dv_check_plan/Dv_check_planDAO.h"
//
//
////PlanSubjectDetailPageDTO::Wrapper PlanSubjectService::listAll(const PlanSubjectQuery::Wrapper& query)
////{
////	// �������ض���
////	auto pages = PlanSubjectDetailPageDTO::createShared();
////	pages->pageIndex = query->pageIndex;
////	pages->pageSize = query->pageSize;
////
////	// ��ѯ����������
////	PlanSubjectDAO dao;
////	uint64_t count = dao.count(query);
////	if (count <= 0)
////	{
////		return pages;
////	}
////
////	// ��ҳ��ѯ����
////	pages->total = count;
////	pages->calcPages();
////	list<PlanSubjectTableDO> result = dao.selectWithPage(query);
////	// ��DOת����DTO
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
////	// ��װDO����
////	PlanSubjectTableDO data;
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
////		// ִ���������
////		PlanSubjectDAO dao;
////	return dao.insert(data);
////}
////
////bool PlanSubjectService::updateData(const PlanSubjectDTO::Wrapper& dto)
////{
////	// ��װDO����
////	PlanSubjectTableDO data;
////	// 	data.setId(dto->id.getValue(0));
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
////		// ִ�������޸�
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
//	// �������ض���
//	auto pages = DeletePlanQueryDTO::createShared();
//	// ��ѯ����������
//	Dv_check_planDAO dao;
//	// ��ҳ��ѯ����
//	list<Dv_check_planDO> result = dao.selectWithPage(query);//������������ݿ��ȡ�Ľ��������������ȡһ��
//	// ��DOת����DTO
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
////	// ��װDO����
////	PlanSubjectTableDO data;
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Type, type, Content, content, Standard, standard)
////		// ִ���������
////		PlanSubjectDAO dao;
////	return dao.insert(data);
////}
////
////bool PlanSubjectService::updateData(const PlanSubjectTableDTO::Wrapper& dto)
////{
////	// ��װDO����
////	PlanSubjectTableDO data;
////	// 	data.setId(dto->id.getValue(0));
////	// 	data.setName(dto->name.getValue(""));
////	// 	data.setSex(dto->sex.getValue(""));
////	// 	data.setAge(dto->age.getValue(1));
////	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Type, type, Content, content, Standard, standard, Code, code)
////		// ִ�������޸�
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



