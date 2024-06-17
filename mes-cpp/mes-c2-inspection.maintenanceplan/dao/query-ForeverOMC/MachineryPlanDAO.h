#ifndef _MACHINERY_PLAN_DAO_
#define _MACHINERY_PLAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"
#include "../../domain/query/query-ForeverOMC/MachineryPlanQuery.h"

/**
* 点检保养计划表数据库操作实现
*/
class MachineryPlanDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MachineryPlanQuery::Wrapper& query);
	// 分页查询数据
	list<Dv_check_planDO> selectWithPage(const MachineryPlanQuery::Wrapper& query);
	// 通过计划ID查询详细数据数据
	list<Dv_check_planDO> selectByPlanId(const MachineryPlanDetailsQuery::Wrapper& query);
};
#endif // !_MACHINERY_PLAN_DAO_