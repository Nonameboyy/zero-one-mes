#pragma once

#ifndef _PROWORKORDER_DAO_
#define _PROWORKORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderDO.h"

/**
 * �������������ݿ����ʵ��
 */
class ProWorkorderDAO : public BaseDAO
{
public:
	// ͨ��������ѯ����
	uint64_t selectByID(uint64_t workorder_id);
	// �޸�����
	int update(const ProdWorkorderDO& uObj);
	
	uint64_t countById(ProdWorkorderDO iObj);
	// ͨ��ID�����������
	int completeById(uint64_t id);
	// ͨ��IDɾ����������
	int deleteById(uint64_t id);
	//ͨ��idȷ����������
	int comfirmById(uint64_t id);
};
#endif // !_PROWORKORDER_DAO_
