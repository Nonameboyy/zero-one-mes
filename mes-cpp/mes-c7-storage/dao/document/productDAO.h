#pragma once
#ifndef _product_DAO_
#define _product_DAO_
#include "BaseDAO.h"
#include "../../domain/do/document/productDO.h"
#include "../../domain/query/document/productQuery.h"

/**
 * �����ݿ����ʵ��
 */
class ProductDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProductPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProductDO> selectWithPage(const ProductPageQuery::Wrapper& query);
	// ͨ����ⵥ���Ų�ѯ����
	list<ProductDO> selectByRecpt_code(const string& recpt_code);
	// ͨ����ⵥ���Ʋ�ѯ����
	list<ProductDO> selectByRecpt_name(const string& recpt_name);
	// ͨ������������ѯ����
	list<ProductDO> selectByWorkorder_code(const string& workorder_code);
	// ͨ���ֿ����Ʋ�ѯ����
	list<ProductDO> selectByWarehouse_name(const string& warehouse_name);

	//detailQuery
	list<ProductDO> detailmes(const ProductDetailQuery::Wrapper& query);

};
#endif // !_rejectionQuery_DAO_