#pragma once
#ifndef _PRODUCT_SERVICE_
#define _PRODUCT_SERVICE_
#include <list>
#include "domain/vo/product/ProductVO.h"
#include "domain/query/product/ProductQuery.h"
#include "domain/dto/product/ProductDTO.h"

/**
 * �������ϵķ������
 */
class ProductTableService
{
public:
	// ��ҳ��ѯ��������
	ProductPageDTO::Wrapper listAll(const ProductQuery::Wrapper& query);
};
/**
 * ������������ķ������
 */
class ProductDetailService
{
public:
	// ��ѯ��������
	ProductDetailDTO::Wrapper listONE(const int& issue_id);
};

#endif
