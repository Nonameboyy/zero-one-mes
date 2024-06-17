#pragma once
#ifndef _RETURN_DAO_
#define _RETURN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/return/ReturnDO.h"
#include "../../domain/query/return/ReturnQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ReturnDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReturnQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ReturnDO> selectWithPage(const ReturnQuery::Wrapper& query);
	// ͨ���˻�����Ų�ѯ����
	list<ReturnDO> selectByRtCode(const string& rtcode);
	// ��������
	uint64_t insert(const ReturnDO& iObj);
};
#endif // !_RETURN_DAO_
