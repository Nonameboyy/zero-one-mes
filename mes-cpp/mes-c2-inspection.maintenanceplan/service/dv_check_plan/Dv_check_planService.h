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

//---正式开始
#include "domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"
#include "domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class Dv_check_planService
{
public:
	//// 分页查询所有数据
	//MachineryPlanPageDTO::Wrapper listAll(const MachineryPlanQuery::Wrapper& query);
	//// 保存数据
	//uint64_t saveData(const MachineryPlanPageDTO::Wrapper& dto);
	//// 修改数据
	//bool updateData(const MachineryPlanPageDTO::Wrapper& dto);
	//// 通过ID删除数据
	//bool removeData(uint64_t id);

	//正式的
	DeletePlanQueryDTO::Wrapper listAll(const DeletePlanQuery::Wrapper& query);
	bool dv_check_planRemoveData(int64_t id);
	bool dv_check_machineryRemoveDataIDP(int64_t idp);
	bool dv_check_subjectRemoveDataIDP(int64_t idp);
};

#endif // !_SAMPLE_SERVICE_
