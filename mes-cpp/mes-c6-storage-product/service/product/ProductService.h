#pragma once
#ifndef _PRODUCT_SERVICE_
#define _PRODUCT_SERVICE_
#include <list>
#include "domain/vo/product/ProductVO.h"
#include "domain/query/product/ProductQuery.h"
#include "domain/dto/product/ProductDTO.h"

/**
 * 生产领料的服务操作
 */
class ProductTableService
{
public:
	// 分页查询所有数据
	ProductPageDTO::Wrapper listAll(const ProductQuery::Wrapper& query);
};
/**
 * 生产领料详情的服务操作
 */
class ProductDetailService
{
public:
	// 查询单个数据
	ProductDetailDTO::Wrapper listONE(const int& issue_id);
};

#endif
