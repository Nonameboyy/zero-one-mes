#ifndef _MACHINERY_PLAN_SERVICE_
#define _MACHINERY_PLAN_SERVICE_
#include <list>
#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"
#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"

/**
* 点检保养计划服务实现
*/
class MachineryPlanService
{
public:
	// 分页查询所有数据
	MachineryPlanPageDTO::Wrapper listAll(const MachineryPlanQuery::Wrapper& query);
	// 计划ID查询详细数据
	MachineryPlanDetailsDTO::Wrapper getDetails(const MachineryPlanDetailsQuery::Wrapper& query);
};

#endif // !_MACHINERY_PLAN_SERVICE_