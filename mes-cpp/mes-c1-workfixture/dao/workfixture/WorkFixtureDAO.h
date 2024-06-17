#pragma once
#include "BaseDAO.h"
#include "../../domain/do/workfixture/WorkFixtureDO.h"
#include "../../domain/query/workfixture/WorkFixtureQuery.h"

class WorkFixtureDAO : public BaseDAO
{
public:
	// 获取查询语句的数据总条数
	uint64_t count(const WorkFixtureQuery::Wrapper &query);
	// 分页+条件查询数据
	list<WorkFixtureDO> selectWithPageCondition(const WorkFixtureQuery::Wrapper &query);
	// 通过ID查询单条数据
	list<WorkFixtureDO> selectById(uint64_t id);
	// 插入数据
	uint64_t insert(const WorkFixtureDO &iObj);
	// 修改数据
	int update(const WorkFixtureDO &uObj);
	// 批量删除数据
	int deleteBatch(const list<uint64_t> &id);
	// 根据id列表查询数据
	list<WorkFixtureDO> selectByIdList(const list<uint64_t>& id);
};