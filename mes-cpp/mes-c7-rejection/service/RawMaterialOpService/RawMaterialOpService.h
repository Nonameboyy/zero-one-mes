#pragma once
#ifndef _RawMaterialOp_SERVICE_
#define _RawMaterialOp_SERVICE_
#include <list>
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"
#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/do/RawMaterialOp/RawMaterialOpDO.h"
#include "ExcelComponent.h"

/**
 * 生产退料物料信息的服务接口
 */
class RawMaterialOpService
{
public:

	// 修改数据
	bool updateData(const RawMaterialOpDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);


	// 分页查询所有数据
	RawMaterialOpPageDTO::Wrapper listAll(const RawMaterialOpQuery::Wrapper& query);

};

#endif // !_RawMaterialOp_SERVICE_
