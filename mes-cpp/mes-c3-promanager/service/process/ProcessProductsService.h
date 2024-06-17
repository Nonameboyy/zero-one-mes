#pragma once
#ifndef _PROCESSPRODUCT_SERVICE_
#define _PROCESSPRODUCT_SERVICE_

#include <list>
#include "domain/vo/process/ProcessProductsVO.h"
#include "domain/query/process/ProcessProductsQuery.h"
#include "domain/dto/process/ProcessProductsDTO.h"

/**
 * 获取工艺关联产品列表的service
 */
class ProcessProductsService
{
public:
	// 分页查询所有数据
	ProductsPageDTO::Wrapper listAll(const ProcessProductsQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_