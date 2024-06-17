#pragma once

#ifndef _FEEDBACK_SERVICE_
#define _FEEDBACK_SERVICE_
#include <list>
#include "domain/vo/FeedBack/FeedBackVO.h"
#include "domain/query/FeedBack/FeedBackQuery.h"
#include "domain/dto/FeedBack/FeedBackDTO.h"

/**
 * 报工服务实现
 */
class FeedBackService
{
public:
	// 分页查询所有数据
	FeedBackPageDTO::Wrapper listAll(const FeedBackQuery::Wrapper& query);
};

#endif // !_FEEDBACK_SERVICE_

