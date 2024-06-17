#pragma once
#ifndef _HUMANRESOURCELIST_DO_
#define _HUMANRESOURCELIST_DO_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 */
class HumanResourceListDO
{
	// 岗位名称
	CC_SYNTHESIZE(string, postName, PostName);
	// 岗位数量
	CC_SYNTHESIZE(int, quantity, Quantity);
	// 记录ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);
	// 工作站ID
	CC_SYNTHESIZE(uint64_t, workstationId, WorkstationId);
	// 岗位ID
	CC_SYNTHESIZE(uint64_t, postId, PostId);


public:
	HumanResourceListDO() {
		postName = "CEO";
		quantity = 1;
		recordId = 1;
		workstationId = 1;
		postId = 1;
	}
};

#endif // !_humanresclist_DO_
