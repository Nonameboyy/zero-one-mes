#pragma once

#ifndef _DELETEWORKREPORT_DO_H
#define _DELETEWORKREPORT_DO_H
#include "../DoInclude.h"

/**
 * 删除报工 数据库实体类
 */
class DeleteWorkReportDO
{
	// 数据库的表： pro_feedback
	// 
	// 记录ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);

public:
	DeleteWorkReportDO() {
		recordId = 0;
	}
};

#endif // !_DELETEWORKREPORT_DO_H
