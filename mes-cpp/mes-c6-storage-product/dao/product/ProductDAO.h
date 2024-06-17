#pragma once
#ifndef _PRODUCT_DAO
#define _PRODUCT_DAO
#include "BaseDAO.h"
#include "../../domain/do/product/ProductDO.h"
#include "../../domain/query/product/ProductQuery.h"

/**
 * �������ϵ����ݿ����
 */
class ProductTableDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProductQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProductTableDO> selectWithPage(const ProductQuery::Wrapper& query);
	
};
/**
 * ����������������ݿ����
 */
class ProductDetailDAO : public BaseDAO
{
public:
	// ��ѯ����
	ProductDetailDO selectWithDetail(const int& issue_id);
};
#endif
