#pragma once
#ifndef _HUMANRESOURCELIST_SERVICE_
#define _HUMANRESOURCELIST_SERVICE_
#include <list>
#include "domain/vo/humanresource/HumanResourceListVO.h"
#include "domain/query/humanresource/HumanResourceListQuery.h"
#include "domain/dto/humanresource/HumanResourceListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class HumanResourceListService
{
public:
	// 分页查询所有数据
	HumanResourcePageDTO::Wrapper listAll(const HumanResourceListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const HumanResourceListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const HumanResourceListDTO::Wrapper& dto);
	// 通过记录ID删除数据
	bool removeData(uint64_t recordId);
};

#endif 

