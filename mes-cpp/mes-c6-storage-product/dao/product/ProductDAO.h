#pragma once
#ifndef _PRODUCT_DAO
#define _PRODUCT_DAO
#include "BaseDAO.h"
#include "../../domain/do/product/ProductDO.h"
#include "../../domain/query/product/ProductQuery.h"

/**
 * 生产领料的数据库操作
 */
class ProductTableDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProductQuery::Wrapper& query);
	// 分页查询数据
	list<ProductTableDO> selectWithPage(const ProductQuery::Wrapper& query);
	
};
/**
 * 生产领料详情的数据库操作
 */
class ProductDetailDAO : public BaseDAO
{
public:
	// 查询数据
	ProductDetailDO selectWithDetail(const int& issue_id);
};
#endif
