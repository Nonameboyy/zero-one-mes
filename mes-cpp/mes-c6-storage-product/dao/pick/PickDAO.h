#pragma once

#ifndef _PICK_DAO_
#define _PICK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pick/PickDO.h"
#include "../../domain/query/pick/PickQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class PickDAO : public BaseDAO
{
public:
	// ͳ����������
	//uint64_t count(const PickQuery::Wrapper& query);
	// ��ҳ��ѯ����
	//list<PickDO> selectWithPage(const PickQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<PickDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const PickDO& iObj);
	// �޸�����
	int update(const PickDO& uObj);
	
};
#endif // !_PICK_DAO_
