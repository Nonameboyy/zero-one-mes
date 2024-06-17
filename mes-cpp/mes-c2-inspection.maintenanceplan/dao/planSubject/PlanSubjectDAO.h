#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_DAO_
#define _PLANSUBJECT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/planSubject/PlanSubjectDO.h"
#include "../../domain/query/planSubject/PlanSubjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PlanSubjectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PlanSubjectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PlanSubjectTableDO> selectWithPage(const PlanSubjectQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<PlanSubjectTableDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const PlanSubjectTableDO& iObj);
	//// �޸�����
	//int update(const PlanSubjectTableDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_PLANSUBJECT_DAO_
