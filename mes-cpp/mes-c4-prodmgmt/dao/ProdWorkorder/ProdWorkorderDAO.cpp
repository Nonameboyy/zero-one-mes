#include "stdafx.h"
#include "../../mes-c4-prodmgmt/dao/ProdWorkorder/ProdWorkorderDAO.h"
#include "../../mes-c4-prodmgmt/dao/ProdWorkorder/ProdWorkorderMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PRODWORKORDER_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->workorder_code) { \
	sql << " AND `workorder_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
} \
if (query->workorder_name) { \
	sql << " AND `workorder_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_name.getValue("")); \
} \
if (query->workorder_type) { \
	sql << " AND `workorder_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_type.getValue("")); \
} \
if (query->source_code) { \
	sql << " AND `source_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->source_code.getValue("")); \
} \
if (query->product_code) { \
	sql << " AND `product_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->product_code.getValue("")); \
} \
if (query->product_name) { \
	sql << " AND `product_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->product_name.getValue("")); \
} \
if (query->client_code) { \
	sql << " AND `client_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->client_code.getValue("")); \
} \
if (query->client_name) { \
	sql << " AND `client_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->client_name.getValue("")); \
} \
if (query->request_date) { \
	sql << " AND `request_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->request_date.getValue("")); \
}

//定义获取BOM列表的宏
#define PRODWORKORDER_BOM_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->line_id) { \
	sql << " AND `line_id`=?"; \
	SQLPARAMS_PUSH(params, "ull", std::uint64_t, query->line_id.getValue(0)); \
}


uint64_t ProdWorkorderDAO::count(const GetProdWorkorderListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_workorder";
	PRODWORKORDER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t ProdWorkorderDAO::countBom(const ProdWorkorderBomListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_workorder_bom";
	PRODWORKORDER_BOM_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//获取生产工单详情
std::list<ProdWorkorderInfoDO> ProdWorkorderDAO::selectByWorkorderId(const uint64_t& workorder_id)
{
	string sql = "SELECT workorder_code,workorder_name,order_source,source_code,status,workorder_type,product_code,product_name,product_spc,unit_of_measure,quantity,request_date,batch_code,client_code,client_name,vendor_code,vendor_name,remark FROM pro_workorder WHERE `workorder_id`=?";
	ProdWorkorderInfoMapper mapper;
	return sqlSession->executeQuery<ProdWorkorderInfoDO, ProdWorkorderInfoMapper>(sql, mapper, "%ull", workorder_id);
}

//获取生产工单列表
std::list<GetProdWorkorderListDO> ProdWorkorderDAO::selectWithPage(const GetProdWorkorderListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT workorder_code,workorder_name,workorder_type,source_code,product_code,product_name,client_code,client_name,request_date FROM pro_workorder";
	PRODWORKORDER_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetProdWorkorderListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetProdWorkorderListDO, GetProdWorkorderListMapper>(sqlStr, mapper, params);
}

//获取生产工单BOM列表
std::list<ProdWorkorderBomListDO> ProdWorkorderDAO::selectByBomId(const ProdWorkorderBomListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT line_id,item_code,item_name,item_spc,unit_of_measure,item_or_product,quantity FROM pro_workorder_bom";
	PRODWORKORDER_BOM_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProdWorkorderBomListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProdWorkorderBomListDO, ProdWorkorderBomListMapper>(sqlStr, mapper, params);
}

//添加生产工单
uint64_t ProdWorkorderDAO::insert(const AddProdWorkorderDO& iObj)
{
	string sql = "INSERT INTO `pro_workorder` (`workorder_id`, `workorder_code`, `workorder_name`, `order_source`, `status`, `workorder_type`, `product_code`, `product_name`, `product_spc`, `unit_of_measure`, `quantity`, `request_date`, `batch_code`, `remark`, `product_id`, `ancestors`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%s%s%s%s%s%s%s%s%s%d%s%s%s%ull%s", iObj.getWorkorder_id(), iObj.getWorkorder_code(), iObj.getWorkorder_name(), iObj.getOrder_source(), iObj.getStatus(), iObj.getWorkorder_type(), iObj.getProduct_code(), iObj.getProduct_name(), iObj.getProduct_spc(), iObj.getUnit_of_measure(), iObj.getQuantity(), iObj.getRequest_date(), iObj.getBatch_code(), iObj.getRemark(), iObj.getProduct_id(), iObj.getAncestors());
}