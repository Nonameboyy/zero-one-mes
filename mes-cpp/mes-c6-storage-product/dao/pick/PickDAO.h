#pragma once

#ifndef _PICK_DAO_
#define _PICK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pick/PickDO.h"
#include "../../domain/query/pick/PickQuery.h"

/**
 * 示例表数据库操作实现
 */
class PickDAO : public BaseDAO
{
public:
	// 统计数据条数
	//uint64_t count(const PickQuery::Wrapper& query);
	// 分页查询数据
	//list<PickDO> selectWithPage(const PickQuery::Wrapper& query);
	// 通过姓名查询数据
	//list<PickDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const PickDO& iObj);
	// 修改数据
	int update(const PickDO& uObj);
	
};
#endif // !_PICK_DAO_
