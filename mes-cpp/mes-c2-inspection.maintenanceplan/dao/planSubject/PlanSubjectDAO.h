#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_DAO_
#define _PLANSUBJECT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/planSubject/PlanSubjectDO.h"
#include "../../domain/query/planSubject/PlanSubjectQuery.h"

/**
 * 示例表数据库操作实现
 */
class PlanSubjectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PlanSubjectQuery::Wrapper& query);
	// 分页查询数据
	list<PlanSubjectTableDO> selectWithPage(const PlanSubjectQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<PlanSubjectTableDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const PlanSubjectTableDO& iObj);
	//// 修改数据
	//int update(const PlanSubjectTableDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_PLANSUBJECT_DAO_
