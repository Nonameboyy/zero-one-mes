#pragma once
/*
*
*/
#ifndef _DV__CHECK__SUBJECT_DAO_
#define _DV__CHECK__SUBJECT_DAO_
#include "BaseDAO.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class Dv_check_subjectDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int dv_check_subjectDeleteById(int64_t id);
	//---Ϊ�˽���ɾ���ĸ�����ѯ������һ������
	std::list<DvCheckSubjectDO> selectWithPage(const DeletePlanSubjectQuery::Wrapper& query);
};
#endif // !_DV__CHECK__SUBJECT_DAO_
