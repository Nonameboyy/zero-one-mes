#pragma once
#ifndef _RAWMATERIALOP_DAO_
#define _RAWMATERIALOP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RawMaterialOp/RawMaterialOpDO.h"
#include "../../domain/query/RawMaterialOp/RawMaterialOpQuery.h"

/**
 * 示例表数据库操作实现
 */
class RawMaterialOpDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RawMaterialOpQuery::Wrapper& query);
	// 分页查询数据
	list<RawMaterialOpDO> selectWithPage(const RawMaterialOpQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const RawMaterialOpDO& iObj);
	// 修改数据
	int update(const RawMaterialOpDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_RawMaterialOp_DAO_
