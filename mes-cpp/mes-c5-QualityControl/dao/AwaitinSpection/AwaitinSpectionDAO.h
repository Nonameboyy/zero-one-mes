#pragma once
#ifndef __AWAITINSPECTION_DAO_
#define __AWAITINSPECTION_DAO_

#include "BaseDAO.h"
#include "domain/do/AwaitinSpection/AwaitinSpectionDO.h"
#include "domain/query/AwaitinSpection/AwaitinSpectionQuery.h"

class AwaitinSpectionDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const AwaitinSpectionQuery::Wrapper& query);
	// 分页查询数据
	list<AwaitinSpectionDO> selectAwaitinSpectionWithPage(const AwaitinSpectionQuery::Wrapper& query);
};

#endif // !__AWAITINSPECTION_DAO_
