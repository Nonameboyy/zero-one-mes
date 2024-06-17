#pragma once
#ifndef _storage_DAO_
#define _storage_DAO_
#include "BaseDAO.h"
#include "../../domain/do/storage/storageDO.h"
#include "../../domain/query/storage/storageQuery.h"

/**
 * 示例表数据库操作实现
 */
class storageDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const storageQuery::Wrapper& query);
	// 分页查询数据
	list<storageDO> selectWithPage(const storageQuery::Wrapper& query);
	// 修改数据
	int update(const storageDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_storage_DAO_
