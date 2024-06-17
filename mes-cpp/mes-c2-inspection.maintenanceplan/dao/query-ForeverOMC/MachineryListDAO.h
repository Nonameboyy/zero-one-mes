#ifndef _MACHINERY_LIST_DAO_
#define _MACHINERY_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../domain/query/query-ForeverOMC/MachineryListQuery.h"

/**
* ��챣���ƻ������ݿ����ʵ��
*/
class MachineryListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MachineryListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Dv_check_machineryDO> selectWithPage(const MachineryListQuery::Wrapper& query);
};
#endif // !_MACHINERY_LIST_DAO_