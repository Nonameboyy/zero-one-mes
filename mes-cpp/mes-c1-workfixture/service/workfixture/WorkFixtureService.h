#pragma once
#include "domain/dto/workfixture/WorkFixtureDTO.h"
#include "domain/query/workfixture/WorkFixtureQuery.h"

class WorkFixtureService
{
public:
	// 分页+条件查询列表数据
	WorkFixturePageDTO::Wrapper queryList(const WorkFixtureQuery::Wrapper &query);
	// 通过ID查询单条详情数据
	WorkFixtureDTO::Wrapper queryDetail(uint64_t id);
	// 添加数据
	uint64_t addData(const WorkFixtureDTO::Wrapper &dto);
	// 修改数据
	bool updateData(const WorkFixtureDTO::Wrapper &dto);
	// 删除数据
	bool removeData(const list<uint64_t>& id);
	// 导出数据的相关函数在下面定义
	string exportData(const list<uint64_t>& id);
};