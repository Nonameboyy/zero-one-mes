#pragma once

#ifndef _PRODTASK_DAO_
#define _PRODTASK_DAO_

#include "BaseDAO.h"
#include "../../domain/do/ProdTask/ProdTaskDO.h"

class ProdTaskDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const ProdTaskModifyDO& uObj);

	// 通过ID删除数据
	int deleteById(uint64_t id);
};

#endif // !_PRODTASK_DAO_
