#include "stdafx.h"
#include "DetectionTemplateDAO.h"
#include "DetectionTemplateMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define DETECTIONTEMPLATE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->template_id) { \
	sql << " AND `template_id`=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->template_id.getValue(0)); \
} \
if (query->template_code) { \
	sql << " AND `template_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->template_code.getValue("")); \
} \
if (query->template_name) { \
	sql << " AND template_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->template_name.getValue("")); \
} \
if (query->qc_types) { \
	sql << " AND qc_types=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->qc_types.getValue("")); \
} \
if (query->enable_flag) { \
	sql << " AND enable_flag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->enable_flag.getValue("")); \
}
int DetectionTemplateDAO::deleteBydetectiontemplateId(uint64_t template_id)
{
	string sql = "DELETE FROM `qc_template` WHERE `template_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", template_id);
}

uint64_t DetectionTemplateDAO::count(const DetectionTemplateQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_template";
	DETECTIONTEMPLATE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<DetectionTemplateDO> DetectionTemplateDAO::selectTemplateListWithPage(const DetectionTemplateQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT template_id,template_code,template_name,qc_types,enable_flag FROM qc_template";
	DETECTIONTEMPLATE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DetectionTemplateMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DetectionTemplateDO, DetectionTemplateMapper>(sqlStr, mapper, params);
}

uint64_t DetectionTemplateDAO::insert(const DetectionTemplateDO& iObj)
{
	string sql = "INSERT INTO `qc_template` (`template_code`, `template_name` , `qc_types` , `enable_flag` , `remark` ) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s", iObj.getTemplate_Code(), iObj.getTemplate_Name(),
		iObj.getQc_Types(), iObj.getEnable_Flag(), iObj.getRemark());
}

bool DetectionTemplateDAO::update(const DetectionTemplateDO& iObj)
{
	string sql = "UPDATE `qc_template` SET `template_code`=?,`template_name`=?,`qc_types`=?,`enable_flag`=?,`remark`=? WHERE `template_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%ull", iObj.getTemplate_Code(),iObj.getTemplate_Name(),iObj.getQc_Types(),iObj.getEnable_Flag(),iObj.getRemark(), iObj.getTemplate_Id());
}

list<DetectionTemplateDO> DetectionTemplateDAO::selectByTemplate_code(string template_code) {
	string sql = "SELECT template_code,template_name,qc_types,enable_flag,remark FROM qc_template WHERE `template_code` LIKE CONCAT('%',?,'%')";
	DetectionTemplateDetilesMapper mapper;
	return sqlSession->executeQuery<DetectionTemplateDO, DetectionTemplateDetilesMapper>(sql, mapper, "%s", template_code);
}