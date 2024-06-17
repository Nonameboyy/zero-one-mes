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
 * 示例表数据库操作实现
 */
class Dv_check_planDAO : public BaseDAO
{
public:
	/*
	// 统计数据条数
	uint64_t count(const MachineryPlanQuery::Wrapper& query);
	// 分页查询数据
	list<Dv_check_planDO> selectWithPage(const MachineryPlanQuery::Wrapper& query);
	uint64_t Dv_check_planDAO::count(const MachineryPlanDetailsQuery::Wrapper& query);
	*/

	// 通过姓名查询数据
	// list<Dv_check_planDO> selectByName(const string& name);
	
	//暂时先注释【插入，修改，删除】
	/*
	// 插入数据
	uint64_t insert(const Dv_check_planDO& iObj);
	// 修改数据
	int update(const Dv_check_planDO& uObj);
	*/
	// 通过ID删除数据
	int dv_check_planDeleteById(int64_t id);
	int dv_check_machineryDeleteByIdPlan(int64_t idp);
	int dv_check_subjectDeleteByIdPlan(int64_t idp);
	//---为了进行删除的辅助查询，重载一下用用

	std::list<Dv_check_planDO> selectWithPage(const DeletePlanQuery::Wrapper& query);

	
};
#endif // !_DV__CHECK__PLAN_DAO_
