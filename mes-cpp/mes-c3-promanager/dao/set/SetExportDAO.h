#pragma once
#ifndef _SET_EXPOET_DAO_
#define _SET_EXPOET_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/query/set/ProcessExportQuery.h"

/**
 * 示例表数据库操作实现
 */
class SetExportDAO : public BaseDAO
{
public:
	// 导出工序 查询所有数据
	list<ProProcessDO> selectWithProcessExport(const ProcessExportQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_