#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_SERVICE_
#define _DV__CHECK__MACHINERY_SERVICE_
#include <list>
//---正式开始
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class Dv_check_machineryService
{
public:
	//正式的，删除操作
	DeletePlanMachineryQueryDTO::Wrapper listAll(const DeletePlanMachineryQuery::Wrapper& query);
	bool dv_check_machineryRemoveData(int64_t id);
};

#endif //
