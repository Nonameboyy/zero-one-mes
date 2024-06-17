#pragma once

#ifndef _PICK_DO_
#define _PICK_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PickDO
{
	// 领料单ID
	CC_SYNTHESIZE(int64_t, issueId, Id);
	// 领料单编号
	CC_SYNTHESIZE(string, issueCode, Icode);
	// 领料单名称
	CC_SYNTHESIZE(string, issueName, Iname);
	// 生产工单
	CC_SYNTHESIZE(string, workorderCode, Wcode);
public:
	PickDO() {
		issueId = 0;
		issueCode = "input issueCode";
		issueName = "input issueName";
		workorderCode = "input workorderCode";
	}
};

#endif // !_PICK_DO_
