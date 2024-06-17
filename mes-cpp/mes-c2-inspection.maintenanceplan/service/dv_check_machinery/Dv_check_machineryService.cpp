#include "stdafx.h"
//ɾ��plan
//����ֵ
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//����ֵ
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
//������
#include "../../service/dv_check_machinery/Dv_check_machineryService.h"
//DAO��DO��DAO�����������
#include "../../dao/dv_check_machinery/Dv_check_machineryDAO.h"

DeletePlanMachineryQueryDTO::Wrapper Dv_check_machineryService:: listAll(const DeletePlanMachineryQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DeletePlanMachineryQueryDTO::createShared();
	// ��ѯ����������
	Dv_check_machineryDAO dao;
	// ��ҳ��ѯ����
	list<Dv_check_machineryDO> result = dao.selectWithPage(query);//������������ݿ��ȡ�Ľ��������������ȡһ��

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
