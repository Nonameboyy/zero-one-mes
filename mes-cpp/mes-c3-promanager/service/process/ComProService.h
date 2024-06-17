#pragma once
#ifndef _PROCESSPRO_SERVICE_
#define _PROCESSPRO_SERVICE_
#include <list>
#include "domain/vo/process/ComProVo.h"
#include "domain/query/process/ComProQuery.h"
#include "domain/dto/process/ComProDTO.h"

/**
 * 删除组成工序的service
 */
class ComProService
{
public:
	// 分页查询所有数据
	ComProPageDTO::Wrapper listAll(const ProQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const NewProcessDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const ModifyProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 通过ID删除数据
	bool removeData(list<uint64_t> id);
};

#endif // !_SAMPLE_SERVICE_