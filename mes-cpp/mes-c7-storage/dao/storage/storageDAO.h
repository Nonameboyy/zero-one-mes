#pragma once
#ifndef _storage_DAO_
#define _storage_DAO_
#include "BaseDAO.h"
#include "../../domain/do/storage/storageDO.h"
#include "../../domain/query/storage/storageQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class storageDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const storageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<storageDO> selectWithPage(const storageQuery::Wrapper& query);
	// �޸�����
	int update(const storageDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_storage_DAO_
