#ifndef _MACHINERY_LIST_SERVICE_
#define _MACHINERY_LIST_SERVICE_
#include <list>
#include "domain/vo/query-ForeverOMC/MachineryListVO.h"
#include "domain/query/query-ForeverOMC/MachineryListQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryListDTO.h"

/**
* 点检保养计划服务实现
*/
class MachineryListService
{
public:
	// 分页查询所有数据
	MachineryListPageDTO::Wrapper listAll(const MachineryListQuery::Wrapper& query);
};

#endif // !_MACHINERY_LIST_SERVICE_