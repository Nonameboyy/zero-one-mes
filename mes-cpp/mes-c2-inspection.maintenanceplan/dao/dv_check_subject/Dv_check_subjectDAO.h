#pragma once
/*
*
*/
#ifndef _DV__CHECK__SUBJECT_DAO_
#define _DV__CHECK__SUBJECT_DAO_
#include "BaseDAO.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

/**
 * 示例表数据库操作实现
 */
class Dv_check_subjectDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int dv_check_subjectDeleteById(int64_t id);
	//---为了进行删除的辅助查询，重载一下用用
	std::list<DvCheckSubjectDO> selectWithPage(const DeletePlanSubjectQuery::Wrapper& query);
};
#endif // !_DV__CHECK__SUBJECT_DAO_
