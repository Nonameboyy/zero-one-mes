#pragma once
#ifndef _rejectionQuery_SERVICE_
#define _rejectionQuery_SERVICE_
#include <list>
#include "domain/vo/document/productVO.h"
#include "domain/dto/document/productDTO.h"
#include "domain/query/document/productQuery.h"
/**
 * �����б��ҳ��ѯ����
 */
class ProductService
{
public:
	// ��ҳ��ѯ��������
	ProductPageDTO::Wrapper listAll(const ProductPageQuery::Wrapper& query);
	//��ѯ��ϸ����
	ProductDTO::Wrapper queryDetail(const ProductDetailQuery::Wrapper& query);


};


#endif 