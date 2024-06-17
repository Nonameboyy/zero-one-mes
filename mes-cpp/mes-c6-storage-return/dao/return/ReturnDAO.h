#pragma once
#ifndef _RETURN_DAO_
#define _RETURN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/return/ReturnDO.h"
#include "../../domain/query/return/ReturnQuery.h"

/**
 * 示例表数据库操作实现
 */
class ReturnDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReturnQuery::Wrapper& query);
	// 分页查询数据
	list<ReturnDO> selectWithPage(const ReturnQuery::Wrapper& query);
	// 通过退货单编号查询数据
	list<ReturnDO> selectByRtCode(const string& rtcode);
	// 插入数据
	uint64_t insert(const ReturnDO& iObj);
};
#endif // !_RETURN_DAO_
