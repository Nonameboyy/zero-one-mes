#pragma once
/*
* 
*/
#ifndef _DV__CHECK__SUBJECTSERVICE_SERVICE_
#define _DV__CHECK__SUBJECTSERVICE_SERVICE_
#include <list>
//#include "domain/vo/sample/SampleVO.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto/sample/SampleDTO.h"

#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"
#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"

//---��ʽ��ʼ
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Dv_check_planService
{
public:
	//// ��ҳ��ѯ��������
	//MachineryPlanPageDTO::Wrapper listAll(const MachineryPlanQuery::Wrapper& query);
	//// ��������
	//uint64_t saveData(const MachineryPlanPageDTO::Wrapper& dto);
	//// �޸�����
	//bool updateData(const MachineryPlanPageDTO::Wrapper& dto);
	//// ͨ��IDɾ������
	//bool removeData(uint64_t id);

	//��ʽ��
	DeletePlanQueryDTO::Wrapper listAll(const DeletePlanQuery::Wrapper& query);
	bool dv_check_planRemoveData(int64_t id);
	bool dv_check_machineryRemoveDataIDP(int64_t idp);
	bool dv_check_subjectRemoveDataIDP(int64_t idp);
};

#endif // !_SAMPLE_SERVICE_
