#pragma once
#ifndef _DELETEWHSTORAGEORDER_DO_
#define _DELETEWHSTORAGEORDER_DO_

#include "../../DoInclude.h"

/*
ɾ����ⵥ�е�ʵ����
*/
class DeleteWhStorageorderDO
{
	//��ʶɾ����ⵥ�е�Ψһid��������line_id bigint
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
public:
	DeleteWhStorageorderDO() {
		line_id = 0;
	}
};

#endif // !_DELETEWHSTORAGEORDER_DO_
