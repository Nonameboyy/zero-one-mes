#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_SERVICE_
#define _DV__CHECK__MACHINERY_SERVICE_
#include <list>
//---��ʽ��ʼ
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Dv_check_machineryService
{
public:
	//��ʽ�ģ�ɾ������
	DeletePlanMachineryQueryDTO::Wrapper listAll(const DeletePlanMachineryQuery::Wrapper& query);
	bool dv_check_machineryRemoveData(int64_t id);
};

#endif //
