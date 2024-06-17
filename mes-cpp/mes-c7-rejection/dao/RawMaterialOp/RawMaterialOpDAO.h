#pragma once
#ifndef _RAWMATERIALOP_DAO_
#define _RAWMATERIALOP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RawMaterialOp/RawMaterialOpDO.h"
#include "../../domain/query/RawMaterialOp/RawMaterialOpQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RawMaterialOpDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RawMaterialOpQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<RawMaterialOpDO> selectWithPage(const RawMaterialOpQuery::Wrapper& query);
	// ��������
	uint64_t insert(const RawMaterialOpDO& iObj);
	// �޸�����
	int update(const RawMaterialOpDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_RawMaterialOp_DAO_
