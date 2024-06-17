#pragma once

#ifndef _PICK_SERVICE_
#define _PICK_SERVICE_
#include <list>
#include "../../domain/vo/pick/PickVO.h"
#include "../../domain/query/pick/PickQuery.h"
#include "../../domain/dto/pick/PickDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PickService
{
public:
	// 分页查询所有数据
	//PickPageDTO::Wrapper listAll(const PickQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const PickDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const PickDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_PICK_SERVICE_

