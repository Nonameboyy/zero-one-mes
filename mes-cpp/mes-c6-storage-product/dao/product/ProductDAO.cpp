#include "stdafx.h"
#include "ProductDAO.h"
#include "ProductMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->issue_code) { \
	sql << " AND `issue_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->issue_code.getValue("")); \
} \
if (query->issue_name) { \
	sql << " AND issue_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->issue_name.getValue("")); \
} \
if (query->warehouse_name) { \
	sql << " AND warehouse_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->warehouse_name.getValue("")); \
}\
if (query->issue_date) {\
		sql << " AND issue_date=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->issue_date.getValue("")); \
}\
if (query->status) {\
		sql << " AND status=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue("")); \
}\

uint64_t ProductTableDAO::count(const ProductQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_issue_header ";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ProductTableDO> ProductTableDAO::selectWithPage(const ProductQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT issue_id,issue_code,issue_name,workorder_code,client_code,client_name,issue_date,status FROM  wm_issue_header";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProductTableMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProductTableDO, ProductTableMapper>(sqlStr, mapper, params);
}

ProductDetailDO ProductDetailDAO::selectWithDetail(const int& issue_id)
{
	stringstream sql;
	sql << "SELECT issue_id,issue_code,issue_name,workorder_code,client_code,client_name,issue_date,status,warehouse_name,remark FROM  wm_issue_header where issue_id=?";
	ProductDetailMapper mapper;
	string sqlStr = sql.str();
	std::list<ProductDetailDO> A = sqlSession->executeQuery<ProductDetailDO, ProductDetailMapper>(sqlStr, mapper, "%i", issue_id);
	if (A.size() == 0) return {};
	return A.front();
}
