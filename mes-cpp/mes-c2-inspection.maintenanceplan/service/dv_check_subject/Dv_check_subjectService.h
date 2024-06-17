#pragma once
/*
*
*/
#ifndef _DV__CHECK__SUBJECT_SERVICE_
#define _DV__CHECK__SUBJECT_SERVICE_
#include <list>
//---��ʽ��ʼ
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Dv_check_subjectService
{
public:


	//��ʽ��
	DeletePlanSubjectQueryDTO::Wrapper listAll(const DeletePlanSubjectQuery::Wrapper& query);
	bool dv_check_subjectRemoveData(int64_t id);
};

#endif //
