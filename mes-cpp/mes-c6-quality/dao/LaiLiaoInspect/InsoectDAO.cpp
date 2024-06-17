#include "stdafx.h"
#include "InspectDAO.h"
#include "InspectMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->iqc_code) { \
	sql << " AND `iqc_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->iqc_code.getValue("")); \
} ;\
if (query->vendor_code) { \
	sql << " AND `vendor_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendor_code.getValue("")); \
} ;\
if (query->vendor_name) { \
	sql << " AND `vendor_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendor_name.getValue("")); \
} ;\
if (query->vendor_batch) { \
	sql << " AND `vendor_batch`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendor_batch.getValue("")); \
} ;\
if (query->item_code) { \
	sql << " AND `item_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_code.getValue("")); \
} ;\
if (query->item_name) { \
	sql << " AND `item_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_name.getValue("")); \
} ;\
if (query->check_result) { \
	sql << " AND `check_result`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->check_result.getValue("")); \
} ;\
if (query->recive_date) { \
	sql << " AND `recive_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recive_date.getValue("")); \
} ;\
if (query->inspect_date) { \
	sql << " AND `inspect_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->inspect_date.getValue("")); \
} ;\
if (query->inspector) { \
	sql << " AND `inspector`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->inspector.getValue("")); \
} ;\


uint64_t InspectDAO::count(const InspectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_iqc ";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//分页查询列表
std::list<InspectDO> InspectDAO::selectWithPage(const InspectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT iqc_code,iqc_name,template_id,vendor_name,vendor_nick,vendor_batch,item_code,item_name,quantity_recived,quantity_check,quantity_unqualified,check_result,recive_date,inspect_date,inspector,status FROM  qc_iqc";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InspectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InspectDO, InspectMapper>(sqlStr, mapper, params);
}

//查询详情
Inspect_detailDO InspectDAO::selectWithID(const int& iqc_id)
{
	stringstream sql;
	sql << "SELECT iqc_id, iqc_code, iqc_name,vendor_code, vendor_nick, vendor_batch, item_code, item_name, unit_of_measure,quantity_recived, quantity_check, quantity_unqualified, check_result, recive_date, inspect_date,maj_quantity, cr_quantity,min_quantity,maj_rate,cr_rate, min_rate,status ,remark FROM  qc_iqc where iqc_id=?";
	Inspect_detailMapper mapper;
	string sqlStr = sql.str();
	std::list<Inspect_detailDO> A = sqlSession->executeQuery<Inspect_detailDO, Inspect_detailMapper>(sqlStr, mapper, "%i", iqc_id);
	if (A.size() == 0) return {};
	return A.front();
}

//新增检验表
uint64_t InspectDAO::insert(const InspectDO& iObj)
{                                  //`iqc_id`,
	string sql = "INSERT INTO `qc_iqc` ( `iqc_id`,`iqc_code`,`iqc_name`,`template_id`, `vendor_id`, `vendor_code`,`vendor_name`,`vendor_nick`,`vendor_batch`,`item_id`,`item_code`,`item_name` ,`quantity_recived`,`quantity_check`,`quantity_unqualified`,`check_result`,`recive_date`,`inspect_date`,`inspector`,`remark`,`status`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?,?,?,?,?,?,?,?,?,?)";//
	return sqlSession->executeInsert(sql, "%ull%s%s%ull%ull%s%s%s%s%ull%s%s%d%i%i%s%s%s%s%s%s",  //
		iObj.getIqc_id(),
		iObj.getIqc_code(),
		iObj.getIqc_name(),
		iObj.getTemplate_id(),
		iObj.getVendor_id(),
		iObj.getVendor_code(),
		iObj.getVendor_name(),

		iObj.getVendor_nick(),
		iObj.getVendor_batch(),
		iObj.getItem_id(),		
		iObj.getItem_code(),
		iObj.getItem_name(),
		iObj.getQuantity_recived(),
		iObj.getQuantity_check(),
		iObj.getQuantity_unqualified(),
		iObj.getCheck_result(),
		iObj.getRecive_date(),
		iObj.getInspect_date(),
		iObj.getInspector(),
		iObj.getRemark(),
		iObj.getList_status()
		);
}

//修改检验表
int InspectDAO::update(const InspectDO& uObj)
{
	string sql = "UPDATE `qc_iqc` SET `iqc_code` = ?, `iqc_name`= ?,  `vendor_code`= ?, `vendor_nick`= ?, `vendor_batch`= ?, `item_code`= ?, `item_name`= ?, `unit_of_measure`=?,`quantity_recived`= ? ,`quantity_check`=?,`quantity_unqualified`=?,`check_result`=?,`recive_date`=?,`inspect_date`=?,`status`=? ,`remark`=? WHERE `iqc_id` = ?;";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%d%i%i%s%s%s%s%s%ull",
		uObj.getIqc_code(),
		uObj.getIqc_name(),
		//uObj.getVendor_id(),
		uObj.getVendor_code(),
		//uObj.getVendor_name(),
		uObj.getVendor_nick(),
		uObj.getVendor_batch(),
		uObj.getItem_code(),
		uObj.getItem_name(),
		uObj.getUnit_of_measure(),
		uObj.getQuantity_recived(),
		uObj.getQuantity_check(),
		uObj.getQuantity_unqualified(),
		uObj.getCheck_result(),
		uObj.getRecive_date(),
		uObj.getInspect_date(),
		uObj.getList_status(),
		uObj.getRemark(),
		uObj.getIqc_id());
}

//删除检验表
int InspectDAO::deleteById(uint64_t iqc_id)
{
	string sql = "DELETE FROM `qc_iqc` WHERE `iqc_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", iqc_id);
}

//确认检验单
int InspectDAO::Is_Ok( InspectDO& uObj)
{
	string sql = "UPDATE `qc_iqc` SET `status`='CONFIRMED' WHERE `iqc_id` = ?;";

	return sqlSession->executeUpdate(sql, "%ull",
		uObj.getIqc_id());
}

//完成检验单
int InspectDAO::Finished( InspectDO& uObj)
{
	string sql = "UPDATE `qc_iqc` SET `status`='FINISHED' WHERE `iqc_id` = ?;";

	return sqlSession->executeUpdate(sql, "%ull",
		uObj.getIqc_id());
}

//导出前的查询
std::list<InspectDO> InspectDAO::selectAll(const Inspect_tableQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT";
	sql << " `iqc_code`, `iqc_name`";
	sql << " `vendor_code`,`vendor_name`,";
	sql << " `item_id`, `item_code`, `item_name`,";
	sql << " `specification`, `unit_of_measure`, `quantity_min_check`,`quantity_max_unqualified`,";
	sql << " `quantity_recived`, `quantity_check`, `quantity_unqualified`,`maj_rate`,`min_rate`,`cr_rate`,";
	sql << " `maj_quantity`, `min_quantity`,`cr_quantity`,`check_result`,`recive_date`,`inspect_date`,`inspector`,`status`";
	sql << " FROM qc_iqc WHERE 1 = 1";

	SqlParams params;
	if (query->iqc_id) {
		sql << " AND (iqc_id=?)";
		SQLPARAMS_PUSH(params, "i", std::int64_t, query->iqc_id.getValue(1));
	}
	TableMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<InspectDO, TableMapper>(sqlStr, mapper, params);
}
