/*
 @Author: Croissant
*/
#include "stdafx.h"
#include "WorkFixtureTypeDAO.h"
#include "WorkFixtureTypeMapper.h"
#include <sstream>

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->typeCode) { \
	sql << " AND `tool_type_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typeCode.getValue("")); \
} \
if (query->typeName) { \
	sql << " AND `tool_type_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->typeName.getValue("")); \
} \
if (query->maintenType) { \
	sql << " AND `mainten_type`=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->maintenType.getValue("")); \
}

uint64_t WorkFixtureTypeDAO::count(const WorkFixtureTypeListQuery::Wrapper& query)
{
	/*
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//保养维护类型 REGULAR定期维护 USAGE按使用次数维护
	API_DTO_FIELD_DEFAULT(String, maintenType, ZH_WORDS_GETTER("workfixture.type.fields.mtype"));*/
	stringstream sql;
	sql << "SELECT COUNT(*) FROM tm_tool_type";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<WorkFixtureTypeSettingDO> WorkFixtureTypeDAO::selectAll()
{
	stringstream sql;
	sql << "SELECT tool_type_id,tool_type_code,tool_type_name,code_flag,mainten_type,mainten_period,remark FROM tm_tool_type";
	WorkFixtureTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkFixtureTypeSettingDO, WorkFixtureTypeMapper>(sqlStr, mapper);
}

list<WorkFixtureTypeSettingDO> WorkFixtureTypeDAO::selectWithPage(const WorkFixtureTypeListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT tool_type_id,tool_type_code,tool_type_name,code_flag,mainten_type,mainten_period,remark FROM tm_tool_type";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WorkFixtureTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkFixtureTypeSettingDO, WorkFixtureTypeMapper>(sqlStr, mapper, params);
}
list<WorkFixtureTypeSettingDO> WorkFixtureTypeDAO::selectByCode(string code) {
	string sql = "SELECT tool_type_id,tool_type_code,tool_type_name,code_flag,mainten_type,mainten_period,remark FROM tm_tool_type WHERE `tool_type_code`=?";
	WorkFixtureTypeMapper mapper;
	return sqlSession->executeQuery<WorkFixtureTypeSettingDO, WorkFixtureTypeMapper>(sql, mapper, "%s", code);
}
list<WorkFixtureTypeSettingDO> WorkFixtureTypeDAO::selectByName(string name) {
	string sql = "SELECT tool_type_id,tool_type_code,tool_type_name,code_flag,mainten_type,mainten_period,remark FROM tm_tool_type WHERE `tool_type_name`=?";
	WorkFixtureTypeMapper mapper;
	return sqlSession->executeQuery<WorkFixtureTypeSettingDO, WorkFixtureTypeMapper>(sql, mapper, "%s", name);
}

uint64_t WorkFixtureTypeDAO::insert(const WorkFixtureTypeSettingDO& iObj)
{
	string sql = "INSERT INTO `tm_tool_type` (`tool_type_code`, `tool_type_name`, `code_flag`, `mainten_type`, `mainten_period`, `remark`) VALUES ( ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%i%s", iObj.getCode(), iObj.getName(), iObj.getFlag(), iObj.getMaintenType(), iObj.getPeriod(), iObj.getRemark());
}

int WorkFixtureTypeDAO::update(const WorkFixtureTypeSettingDO& uObj)
{
	string sql = "UPDATE `tm_tool_type` SET `tool_type_code`=?, `tool_type_name`=?, `code_flag`=? ,`remark`=? WHERE `tool_type_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%ull", uObj.getCode(), uObj.getName(), uObj.getFlag(),uObj.getRemark(), uObj.getId());
}

int WorkFixtureTypeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `tm_tool_type` WHERE `tool_type_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
