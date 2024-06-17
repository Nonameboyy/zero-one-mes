#pragma once
#ifndef _rejectionQuery_SERVICE_
#define _rejectionQuery_SERVICE_
#include <list>
#include "domain/vo/document/productVO.h"
#include "domain/dto/document/productDTO.h"
#include "domain/query/document/productQuery.h"
/**
 * 退料列表分页查询服务
 */
class ProductService
{
public:
	// 分页查询所有数据
	ProductPageDTO::Wrapper listAll(const ProductPageQuery::Wrapper& query);
	//查询详细数据
	ProductDTO::Wrapper queryDetail(const ProductDetailQuery::Wrapper& query);


};


#endif 