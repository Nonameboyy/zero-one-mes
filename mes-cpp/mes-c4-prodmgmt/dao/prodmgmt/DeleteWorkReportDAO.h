#pragma once

#ifndef _DELETEWORKREPORT_DAO_H
#define _DELETEWORKREPORT_DAO_H
#include "BaseDAO.h"
#include "../../domain/do/prodmgmt/DeleteWorkReportDO.h"

/**
 * 删除报工 数据库操作实现
 */
class DeleteWorkReportDAO : public BaseDAO
{
public:
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_DELETEWORKREPORT_DAO_H
