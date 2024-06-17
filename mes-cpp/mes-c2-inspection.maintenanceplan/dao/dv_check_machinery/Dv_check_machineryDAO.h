#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_DAO_
#define _DV__CHECK__MACHINERY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Dv_check_machineryDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int dv_check_machineryDeleteById(int64_t id);
	//---Ϊ�˽���ɾ���ĸ�����ѯ������һ������
	std::list<Dv_check_machineryDO> selectWithPage(const DeletePlanMachineryQuery::Wrapper& query);
};
#endif // !_DV__CHECK__MACHINERY_DAO_
