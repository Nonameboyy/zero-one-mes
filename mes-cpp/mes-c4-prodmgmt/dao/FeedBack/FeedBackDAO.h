#pragma once
#ifndef _FEEDBACK_DAO_
#define _FEEDBACK_DAO_

#include "BaseDAO.h"
#include "../../domain/query/FeedBack/FeedBackQuery.h"
#include "../../domain/do/FeedBack/FeedBackDO.h"
/**
 * ��ҳ��ѯ����ʵ��
 */
class FeedBackDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const FeedBackQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<FeedBackDO> selectWithPage(const FeedBackQuery::Wrapper& query);
	// ͨ��������ѯ����
	std::list<FeedBackDO> selectByName(const string& name);
};

#endif // _FeedBAck_DAO_
