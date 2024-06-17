#pragma once

#ifndef _PROWORKORDER_DAO_
#define _PROWORKORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderDO.h"

/**
 * 生产工单表数据库操作实现
 */
class ProWorkorderDAO : public BaseDAO
{
public:
	// 通过姓名查询数据
	uint64_t selectByID(uint64_t workorder_id);
	// 修改数据
	int update(const ProdWorkorderDO& uObj);
	
	uint64_t countById(ProdWorkorderDO iObj);
	// 通过ID完成生产工单
	int completeById(uint64_t id);
	// 通过ID删除生产工单
	int deleteById(uint64_t id);
	//通过id确认生产工单
	int comfirmById(uint64_t id);
};
#endif // !_PROWORKORDER_DAO_
