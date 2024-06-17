#pragma once
#ifndef _MATERIAL_SERVICE_
#define _MATERIAL_SERVICE_
#include <list>
#include "domain/vo/materialsInformation/MaterialVO.h"
#include "domain/query/materialsInformation/MaterialQuery.h"
#include "domain/dto/materialsInformation/MaterialDTO.h"

/**
 * 物料信息的服务操作
 */
class MaterialService
{
public:
	// 分页查询所有数据
	MaterialPageDTO::Wrapper listAll(const MaterialQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const MaterialDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const MaterialDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_MATERIAL_SERVICE_
