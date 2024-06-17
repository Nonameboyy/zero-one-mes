#ifndef _MACHINERY_SUBJECT_DAO_
#define _MACHINERY_SUBJECT_DAO_
#include "BaseDAO.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"
#include "../../domain/query/query-ForeverOMC/MachinerySubjectQuery.h"

/**
* 点检保养计划表数据库操作实现
*/
class MachinerySubjectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const MachinerySubjectQuery::Wrapper& query);
	// 分页查询数据
	list<DvCheckSubjectDO> selectWithPage(const MachinerySubjectQuery::Wrapper& query);
};
#endif // !_MACHINERY_SUBJECT_DAO_