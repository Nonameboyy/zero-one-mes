#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_DAO_
#define _DV__CHECK__MACHINERY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"

/**
 * 示例表数据库操作实现
 */
class Dv_check_machineryDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int dv_check_machineryDeleteById(int64_t id);
	//---为了进行删除的辅助查询，重载一下用用
	std::list<Dv_check_machineryDO> selectWithPage(const DeletePlanMachineryQuery::Wrapper& query);
};
#endif // !_DV__CHECK__MACHINERY_DAO_
