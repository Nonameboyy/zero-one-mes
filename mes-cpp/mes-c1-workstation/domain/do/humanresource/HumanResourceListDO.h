#pragma once
#ifndef _HUMANRESOURCELIST_DO_
#define _HUMANRESOURCELIST_DO_
#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class HumanResourceListDO
{
	// ��λ����
	CC_SYNTHESIZE(string, postName, PostName);
	// ��λ����
	CC_SYNTHESIZE(int, quantity, Quantity);
	// ��¼ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);
	// ����վID
	CC_SYNTHESIZE(uint64_t, workstationId, WorkstationId);
	// ��λID
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
