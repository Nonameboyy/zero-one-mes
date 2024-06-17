#include "stdafx.h"
#include <sstream>
#include "TemplateDetectItemDAO.h"
#include "TemplateDetectItemMapper.h"

//定义条件解析宏，减少重复代码
#define TemplateDetectItem_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->template_id) { \
		sql << " AND `template_id`=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->template_id.getValue(0)); \
} \
if (query->index_id) { \
		sql << " AND index_id=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->index_id.getValue(0)); \
} \
if (query->index_code) { \
		sql << " AND index_code=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->index_code.getValue("")); \
} \
if (query->index_name) { \
		sql << " AND index_name=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->index_name.getValue("")); \
} \
if (query->index_type) { \
		sql << " AND index_type=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->index_type.getValue("")); \
}

uint64_t TemplateDetectItemDAO::count(const TemplateDetectItemQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `qc_template_index`";
	TemplateDetectItem_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<TemplateDetectItemDO> TemplateDetectItemDAO::selectTemplateDetectItemWithPage(const TemplateDetectItemQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `qc_template_index`";
	TemplateDetectItem_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TemplateDetectItemMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TemplateDetectItemDO, TemplateDetectItemMapper>(sqlStr, mapper, params);
}

int TemplateDetectItemDAO::updateTemplateDetectItem(const TemplateDetectItemDO& itemObj)
{
	string sql = "UPDATE `qc_template_index` SET `template_id`=?, `index_id`=?, `index_code`=?, `index_name`=?,`index_type`=?, `qc_tool`=?,`check_method`=?,`stander_val`=?,`unit_of_measure`=?,`threshold_max`=?,`threshold_min`=?,`doc_url`=?,`remark`=?,`attr1`=?,`attr2`=?,`attr3`=?,`attr4`=?,`create_by`=?,`update_by`=?,`update_time`=? WHERE `record_id`=?;";
	return sqlSession->executeUpdate(sql, "%ull%ull%s%s%s%s%s%d%s%d%d%s%s%s%s%i%i%s%s%dt%ull", itemObj.getTemplate_id(), itemObj.getIndex_id(), \
		itemObj.getIndex_code(), itemObj.getIndex_name(), itemObj.getIndex_type(), itemObj.getQc_tool(), itemObj.getCheck_method(), itemObj.getStander_val(), itemObj.getUnit_of_measure(), \
		itemObj.getThreshold_max(), itemObj.getThreshold_min(), itemObj.getDoc_url(), itemObj.getRemark(), itemObj.getAttr1(), itemObj.getAttr2(), \
		itemObj.getAttr3(), itemObj.getAttr4(), itemObj.getCreate_by(), itemObj.getUpdate_by(), itemObj.getUpdate_time(), itemObj.getRecord_id());
}

uint64_t TemplateDetectItemDAO::insertTemplateDetectItem(const TemplateDetectItemDO& itemObj)
{
	string sql = "INSERT INTO `qc_template_index` (`template_id`, `index_id`, `index_code`, `index_name`,`index_type`, `qc_tool`,`check_method`,`stander_val`,`unit_of_measure`,`threshold_max`,`threshold_min`,`doc_url`,`remark`,`attr1`,`attr2`,`attr3`,`attr4`,`create_by`,`create_time`,`update_by`,`update_time`)VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
	return sqlSession->executeInsert(sql, "%ull%ull%s%s%s%s%s%d%s%d%d%s%s%s%s%i%i%s%dt%s%dt", itemObj.getRecord_id(), itemObj.getIndex_id(),
		itemObj.getIndex_code(), itemObj.getIndex_name(), itemObj.getIndex_type(), itemObj.getQc_tool(), itemObj.getCheck_method(), itemObj.getStander_val(), itemObj.getUnit_of_measure(), \
		itemObj.getThreshold_max(), itemObj.getThreshold_min(), itemObj.getDoc_url(), itemObj.getRemark(), itemObj.getAttr1(), itemObj.getAttr2(), \
		itemObj.getAttr3(), itemObj.getAttr4(), itemObj.getCreate_by(), itemObj.getCreate_time(), itemObj.getUpdate_by(), itemObj.getUpdate_time());
}

int TemplateDetectItemDAO::deleteByRecordId(uint64_t record_id)
{
	string sql = "DELETE FROM `qc_template_index` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", record_id);
}

