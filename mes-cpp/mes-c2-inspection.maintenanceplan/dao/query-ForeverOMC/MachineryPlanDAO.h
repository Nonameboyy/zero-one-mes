#ifndef _MACHINERY_PLAN_DAO_
#define _MACHINERY_PLAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"
#include "../../domain/query/query-ForeverOMC/MachineryPlanQuery.h"

/**
* ��챣���ƻ������ݿ����ʵ��
*/
class MachineryPlanDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MachineryPlanQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Dv_check_planDO> selectWithPage(const MachineryPlanQuery::Wrapper& query);
	// ͨ���ƻ�ID��ѯ��ϸ��������
	list<Dv_check_planDO> selectByPlanId(const MachineryPlanDetailsQuery::Wrapper& query);
};
#endif // !_MACHINERY_PLAN_DAO_