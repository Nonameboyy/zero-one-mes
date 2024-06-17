#pragma once
#ifndef _DELETEWHSTORAGEORDER_DO_
#define _DELETEWHSTORAGEORDER_DO_

#include "../../DoInclude.h"

/*
删除入库单行的实体类
*/
class DeleteWhStorageorderDO
{
	//标识删除入库单行的唯一id（主键）line_id bigint
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
public:
	DeleteWhStorageorderDO() {
		line_id = 0;
	}
};

#endif // !_DELETEWHSTORAGEORDER_DO_
