#ifndef _MACHINERY_PLAN_SERVICE_
#define _MACHINERY_PLAN_SERVICE_
#include <list>
#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"
#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"

/**
* ��챣���ƻ�����ʵ��
*/
class MachineryPlanService
{
public:
	// ��ҳ��ѯ��������
	MachineryPlanPageDTO::Wrapper listAll(const MachineryPlanQuery::Wrapper& query);
	// �ƻ�ID��ѯ��ϸ����
	MachineryPlanDetailsDTO::Wrapper getDetails(const MachineryPlanDetailsQuery::Wrapper& query);
};

#endif // !_MACHINERY_PLAN_SERVICE_