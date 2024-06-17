#pragma once
#ifndef _FEEDBACK_DAO_
#define _FEEDBACK_DAO_

#include "BaseDAO.h"
#include "../../domain/query/FeedBack/FeedBackQuery.h"
#include "../../domain/do/FeedBack/FeedBackDO.h"
/**
 * 分页查询报工实现
 */
class FeedBackDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const FeedBackQuery::Wrapper& query);
	// 分页查询数据
	std::list<FeedBackDO> selectWithPage(const FeedBackQuery::Wrapper& query);
	// 通过姓名查询数据
	std::list<FeedBackDO> selectByName(const string& name);
};

#endif // _FeedBAck_DAO_
