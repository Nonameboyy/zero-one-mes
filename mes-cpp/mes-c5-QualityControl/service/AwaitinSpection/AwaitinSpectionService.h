#pragma once
#ifndef __AWAITINSPECTION_SERVICE_
#define __AWAITINSPECTION_SERVICE_

#include "domain/dto/AwaitinSpection/AwaitinSpectionDTO.h"
#include "domain/query/AwaitinSpection/AwaitinSpectionQuery.h"
#include "domain/do/AwaitinSpection/AwaitinSpectionDO.h"
#include "dao/AwaitinSpection/AwaitinSpectionDAO.h"

class AwaitinSpectionService
{
public:
    AwaitinSpectionPageDTO::Wrapper listAll(const AwaitinSpectionQuery::Wrapper& query);
};


#endif // !__AWAITINSPECTION_SERVICE_