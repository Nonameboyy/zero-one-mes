#pragma once
#ifndef _product_DAO_
#define _product_DAO_
#include "BaseDAO.h"
#include "../../domain/do/document/productDO.h"
#include "../../domain/query/document/productQuery.h"

/**
 * 表数据库操作实现
 */
class ProductDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProductPageQuery::Wrapper& query);
	// 分页查询数据
	list<ProductDO> selectWithPage(const ProductPageQuery::Wrapper& query);
	// 通过入库单单号查询数据
	list<ProductDO> selectByRecpt_code(const string& recpt_code);
	// 通过入库单名称查询数据
	list<ProductDO> selectByRecpt_name(const string& recpt_name);
	// 通过生产工单查询数据
	list<ProductDO> selectByWorkorder_code(const string& workorder_code);
	// 通过仓库名称查询数据
	list<ProductDO> selectByWarehouse_name(const string& warehouse_name);

	//detailQuery
	list<ProductDO> detailmes(const ProductDetailQuery::Wrapper& query);

};
#endif // !_rejectionQuery_DAO_