#pragma once
#ifndef _storage_SERVICE_
#define _storage_SERVICE_
#include <list>
#include "domain/dto/storage/storageDTO.h"
#include "domain/query/storage/storageQuery.h"
#include "domain/do/storage/storageDO.h"
#include "ExcelComponent.h"

/**
 * 产品入库信息的服务接口
 */
class storageService
{
public:

	// 添加数据
	uint64_t update(const storageDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	// 分页查询所有数据
	storagePageDTO::Wrapper listAll(const storageQuery::Wrapper& query);

};

#endif // !_storage_SERVICE_
