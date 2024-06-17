#pragma once
/*
* 
*/
#ifndef _DV__CHECK__PLAN_DAO_
#define _DV__CHECK__PLAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"
//#include "../../domain/query/query-ForeverOMC/MachineryPlanQuery.h"

#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Dv_check_planDAO : public BaseDAO
{
public:
	/*
	// ͳ����������
	uint64_t count(const MachineryPlanQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Dv_check_planDO> selectWithPage(const MachineryPlanQuery::Wrapper& query);
	uint64_t Dv_check_planDAO::count(const MachineryPlanDetailsQuery::Wrapper& query);
	*/

	// ͨ��������ѯ����
	// list<Dv_check_planDO> selectByName(const string& name);
	
	//��ʱ��ע�͡����룬�޸ģ�ɾ����
	/*
	// ��������
	uint64_t insert(const Dv_check_planDO& iObj);
	// �޸�����
	int update(const Dv_check_planDO& uObj);
	*/
	// ͨ��IDɾ������
	int dv_check_planDeleteById(int64_t id);
	int dv_check_machineryDeleteByIdPlan(int64_t idp);
	int dv_check_subjectDeleteByIdPlan(int64_t idp);
	//---Ϊ�˽���ɾ���ĸ�����ѯ������һ������

	std::list<Dv_check_planDO> selectWithPage(const DeletePlanQuery::Wrapper& query);

	
};
#endif // !_DV__CHECK__PLAN_DAO_
