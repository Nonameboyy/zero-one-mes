#ifndef _MACHINERY_SUBJECT_DAO_
#define _MACHINERY_SUBJECT_DAO_
#include "BaseDAO.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"
#include "../../domain/query/query-ForeverOMC/MachinerySubjectQuery.h"

/**
* ��챣���ƻ������ݿ����ʵ��
*/
class MachinerySubjectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MachinerySubjectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DvCheckSubjectDO> selectWithPage(const MachinerySubjectQuery::Wrapper& query);
};
#endif // !_MACHINERY_SUBJECT_DAO_