#ifndef _MACHINERY_SUBJECT_SERVICE_
#define _MACHINERY_SUBJECT_SERVICE_
#include <list>
#include "domain/vo/query-ForeverOMC/MachinerySubjectVO.h"
#include "domain/query/query-ForeverOMC/MachinerySubjectQuery.h"
#include "domain/dto/query-ForeverOMC/MachinerySubjectDTO.h"

/**
* 点检保养项目服务实现
*/
class MachinerySubjectService
{
public:
	// 分页查询所有数据
	MachinerySubjectPageDTO::Wrapper listAll(const MachinerySubjectQuery::Wrapper& query);
};

#endif // !_MACHINERY_SUBJECT_SERVICE_