#pragma once
#ifndef _MATERIAL_DAO
#define _MATERIAL_DAO
#include "BaseDAO.h"
#include "../../domain/do/materialsInformation/MaterialDO.h"
#include "../../domain/query/materialsInformation/MaterialQuery.h"

/**
 * ������Ϣ�����ݿ����
 */
class MaterialDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MaterialQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MaterialDO> selectWithPage(const MaterialQuery::Wrapper& query);
	// ��������
	uint64_t insert(const MaterialDO& iObj);
	// �޸�����
	int update(const MaterialDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_MATERIAL_DAO
