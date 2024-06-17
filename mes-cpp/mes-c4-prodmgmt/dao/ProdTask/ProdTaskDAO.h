#pragma once

#ifndef _PRODTASK_DAO_
#define _PRODTASK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/ProdTask/ProdTaskDO.h"

class ProdTaskDAO : public BaseDAO
{
public:
	// �޸�����
	int update(const ProdTaskModifyDO& uObj);

	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};

#endif // !_PRODTASK_DAO_
