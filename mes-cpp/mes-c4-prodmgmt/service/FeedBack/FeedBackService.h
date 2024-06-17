#pragma once

#ifndef _FEEDBACK_SERVICE_
#define _FEEDBACK_SERVICE_
#include <list>
#include "domain/vo/FeedBack/FeedBackVO.h"
#include "domain/query/FeedBack/FeedBackQuery.h"
#include "domain/dto/FeedBack/FeedBackDTO.h"

/**
 * ��������ʵ��
 */
class FeedBackService
{
public:
	// ��ҳ��ѯ��������
	FeedBackPageDTO::Wrapper listAll(const FeedBackQuery::Wrapper& query);
};

#endif // !_FEEDBACK_SERVICE_

