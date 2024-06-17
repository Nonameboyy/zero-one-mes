#ifndef _MACHINERY_LIST_DAO_
#define _MACHINERY_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../domain/query/query-ForeverOMC/MachineryListQuery.h"

/**
* 点检保养计划表数据库操作实现
*/
class MachineryListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MachineryListQuery::Wrapper& query);
	// 分页查询数据
	list<Dv_check_machineryDO> selectWithPage(const MachineryListQuery::Wrapper& query);
};
#endif // !_MACHINERY_LIST_DAO_