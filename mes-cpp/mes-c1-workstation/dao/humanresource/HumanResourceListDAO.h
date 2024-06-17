#pragma once
#ifndef _HUMANRESOURCELIST_DAO_
#define _HUMANRESOURCELIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/humanresource/HumanResourceListDO.h"
#include "../../domain/query/humanresource/HumanResourceListQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class HumanResourceListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const HumanResourceListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<HumanResourceListDO> selectWithPage(const HumanResourceListQuery::Wrapper& query);
	// ͨ������վID��ѯ����
	list<HumanResourceListDO> selectById(const string& workstationId);
	// ����µ�������Դ����
	uint64_t insert(const HumanResourceListDO& iObj);
	// �޸�����
	int update(const HumanResourceListDO& uObj);
	// ͨ����¼IDɾ������
	int deleteById(uint64_t recordId);
};
#endif // _HUMANRESOURCELIST_DAO_
