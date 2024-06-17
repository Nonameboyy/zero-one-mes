#pragma once
#ifndef __AWAITINSPECTION_DAO_
#define __AWAITINSPECTION_DAO_

#include "BaseDAO.h"
#include "domain/do/AwaitinSpection/AwaitinSpectionDO.h"
#include "domain/query/AwaitinSpection/AwaitinSpectionQuery.h"

class AwaitinSpectionDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const AwaitinSpectionQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<AwaitinSpectionDO> selectAwaitinSpectionWithPage(const AwaitinSpectionQuery::Wrapper& query);
};

#endif // !__AWAITINSPECTION_DAO_
