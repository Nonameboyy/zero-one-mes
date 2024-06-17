#pragma once
#ifndef __AREASERVICE_H__
#define __AREASERVICE_H__

#include "domain/dto/storagearea/AreaDTO.h"
#include "domain/query/storagearea/AreaQuery.h"


class AreaService 
{
public:
	// 分页查询所有数据
	AreaPageDTO::Wrapper listAllAreabyPage(const AreaQuery::Wrapper& query);
	// 添加一项库位
	uint64_t insertArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改一项库位
	bool updateArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除一项或多项库位
	bool removeArea( std::list<int64_t>& ids);
};

#endif //__AREASERVICE_H__
