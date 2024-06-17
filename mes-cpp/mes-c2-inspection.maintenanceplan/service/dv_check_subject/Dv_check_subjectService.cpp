#include "stdafx.h"
//ɾ��plan
//����ֵ
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//����ֵ
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
//������
#include "../../service/dv_check_subject/Dv_check_subjectService.h"
//DAO��DO��DAO�����������
#include "../../dao/dv_check_subject/Dv_check_subjectDAO.h"

DeletePlanSubjectQueryDTO::Wrapper Dv_check_subjectService::listAll(const DeletePlanSubjectQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DeletePlanSubjectQueryDTO::createShared();
	// ��ѯ����������
	Dv_check_subjectDAO dao;
	// ��ҳ��ѯ����
	list<DvCheckSubjectDO> result = dao.selectWithPage(query);//������������ݿ��ȡ�Ľ��������������ȡһ��

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

