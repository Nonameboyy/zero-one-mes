#pragma once
#ifndef _HUMANRESOURCELIST_DAO_
#define _HUMANRESOURCELIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/humanresource/HumanResourceListDO.h"
#include "../../domain/query/humanresource/HumanResourceListQuery.h"
/**
 * 示例表数据库操作实现
 */
class HumanResourceListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const HumanResourceListQuery::Wrapper& query);
	// 分页查询数据
	list<HumanResourceListDO> selectWithPage(const HumanResourceListQuery::Wrapper& query);
	// 通过工作站ID查询数据
	list<HumanResourceListDO> selectById(const string& workstationId);
	// 添加新的人力资源数据
	uint64_t insert(const HumanResourceListDO& iObj);
	// 修改数据
	int update(const HumanResourceListDO& uObj);
	// 通过记录ID删除数据
	int deleteById(uint64_t recordId);
};
#endif // _HUMANRESOURCELIST_DAO_
