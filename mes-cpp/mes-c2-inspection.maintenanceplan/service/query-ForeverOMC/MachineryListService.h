#ifndef _MACHINERY_LIST_SERVICE_
#define _MACHINERY_LIST_SERVICE_
#include <list>
#include "domain/vo/query-ForeverOMC/MachineryListVO.h"
#include "domain/query/query-ForeverOMC/MachineryListQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryListDTO.h"

/**
* ��챣���ƻ�����ʵ��
*/
class MachineryListService
{
public:
	// ��ҳ��ѯ��������
	MachineryListPageDTO::Wrapper listAll(const MachineryListQuery::Wrapper& query);
};

#endif // !_MACHINERY_LIST_SERVICE_