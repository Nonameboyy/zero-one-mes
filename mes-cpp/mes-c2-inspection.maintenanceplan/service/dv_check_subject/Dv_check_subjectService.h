#pragma once
/*
*
*/
#ifndef _DV__CHECK__SUBJECT_SERVICE_
#define _DV__CHECK__SUBJECT_SERVICE_
#include <list>
//---正式开始
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class Dv_check_subjectService
{
public:


	//正式的
	DeletePlanSubjectQueryDTO::Wrapper listAll(const DeletePlanSubjectQuery::Wrapper& query);
	bool dv_check_subjectRemoveData(int64_t id);
};

#endif //
