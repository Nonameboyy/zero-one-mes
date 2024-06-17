#include "stdafx.h"
#include "productDAO.h"
#include "productMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->recpt_code) { \
	sql << " AND recpt_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recpt_code.getValue("")); \
} \
if (query->recpt_name) { \
	sql << " AND recpt_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recpt_code.getValue("")); \
} \
if (query->workorder_code) {	\
		sql << " AND workorder_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
}\
if (query->warehouse_name) { \
	sql << " AND warehouse_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
}
//if (query->rt_id) { \
//	sql << " AND `rt_id`=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->rt_id.getValue(1)); \
//} \
//if (query->workorder_id) {\
//		sql << " AND workorder_id=?"; \
//		SQLPARAMS_PUSH(params, "i", int, query->workorder_id.getValue(1)); \
//}\
//if (query->location_name) { \
//	sql << " AND location_name=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->location_name.getValue("")); \
//}\
//if (query->area_name ) { \
//	sql << " AND larea_name =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->area_name .getValue("")); \
//}\
//if (query->rt_date ) { \
//	sql << " AND rt_date =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->rt_date .getValue("")); \
//}\
//if (query->status) { \
//	sql << " AND status =?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->status .getValue("")); \
//}

#define DETAIL_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->recpt_code) { \
	sql << " AND recpt_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recpt_code.getValue("")); \
} \
if (query->recpt_id) { \
	sql << " AND `recpt_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->recpt_id.getValue(1)); \
} 


uint64_t ProductDAO::count(const ProductPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_product_recpt";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//detailQuery
std::list<ProductDO> ProductDAO::detailmes(const ProductDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT recpt_code FROM wm_product_recpt";
	DETAIL_TERAM_PARSE(query, sql);
	ProductMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sqlStr, mapper, params);
}

std::list<ProductDO> ProductDAO::selectWithPage(const ProductPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT recpt_code,recpt_name,workorder_code,warehouse_name,item_code,item_name,recpt_date,status  FROM wm_product_recpt";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProductMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sqlStr, mapper, params);
}

// 通过入库单单号查询数据
std::list<ProductDO> ProductDAO::selectByRecpt_code(const string& recpt_code)
{
	string sql = "SELECT rt_code,recpt_name,workorder_code,warehouse_name,item_code,item_name,recpt_date,status  FROM wm_product_recpt WHERE `recpt_code` LIKE CONCAT('%',?,'%')";
	ProductMapper mapper;
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sql, mapper, "%s", recpt_code);
}

// 通过入库单名称查询数据
std::list<ProductDO> ProductDAO::selectByRecpt_name(const string& recpt_name)
{
	string sql = "SELECT rt_code,recpt_name,workorder_code,warehouse_name,item_code,item_name,recpt_date,status  FROM wm_product_recpt WHERE `recpt_name` LIKE CONCAT('%',?,'%')";
	ProductMapper mapper;
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sql, mapper, "%s", recpt_name);
}
// 通过生产工单查询数据
std::list<ProductDO> ProductDAO::selectByWorkorder_code(const string& workorder_code)
{
	string sql = "SELECT recpt_code,recpt_name,workorder_code,warehouse_name,item_code,item_name,recpt_date,status  FROM wm_product_recpt WHERE `workorder_code` LIKE CONCAT('%',?,'%')";
	ProductMapper mapper;
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sql, mapper, "%s", workorder_code);
}
// 通过仓库名称查询数据
std::list<ProductDO> ProductDAO::selectByWarehouse_name(const string& warehouse_name)
{
	string sql = "SELECT rt_code,recpt_name,workorder_code,warehouse_name,item_code,item_name,recpt_date,status FROM wm_product_recpt WHERE `warehouse_name` LIKE CONCAT('%',?,'%')";
	ProductMapper mapper;
	return sqlSession->executeQuery<ProductDO, ProductMapper>(sql, mapper, "%s", warehouse_name);
}



