#include "stdafx.h"
#include "WorkFixtureDAO.h"
#include "WorkFixtureMapper.h"

// DO数据对象条件解析宏，用于解析和组装必选以及可选参数，sql类型为string
#define DO_PARAMS_PARSE(obj, sql, params); \
sql += "SET `tool_name`=?, `tool_type_id`=?, `tool_type_code`=?, `tool_type_name`=?, `quantity`=?"; \
SQLPARAMS_PUSH(params, "s", std::string, obj.getToolName()); \
SQLPARAMS_PUSH(params, "ull", uint64_t, obj.getToolTypeId()); \
SQLPARAMS_PUSH(params, "s", std::string, obj.getToolTypeCode()); \
SQLPARAMS_PUSH(params, "s", std::string, obj.getToolTypeName()); \
SQLPARAMS_PUSH(params, "i", int32_t, obj.getQuantity()); \
if (obj.getToolCode() != "") { \
	sql += ", `tool_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getToolCode()); \
} \
if (obj.getBrand() != "") { \
	sql += ", `brand`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getBrand()); \
} \
if (obj.getSpec() != "") { \
	sql += ", `spec`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getSpec()); \
} \
if (obj.getQuantityAvail() != 0) { \
	sql += ", `quantity_avail`=?"; \
	SQLPARAMS_PUSH(params, "i", int32_t, obj.getQuantityAvail()); \
} \
if (obj.getMaintenType() != "") { \
	sql += ", `mainten_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getMaintenType()); \
} \
if (obj.getNextMaintenDate() != "") { \
	sql += ", `next_mainten_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getNextMaintenDate()); \
} \
if (obj.getStatus() != "") { \
	sql += ", `status`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getStatus()); \
} \
if (obj.getRemark() != "") { \
	sql += ", `remark`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, obj.getRemark()); \
}

#define QUERY_PARAMS_PARSE(query, sql, params) \
if (query->toolCode) { \
	sql += " AND `tool_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->toolCode.getValue({})); \
} \
if (query->toolName) { \
	sql += " AND `tool_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->toolName.getValue({})); \
} \
if (query->toolTypeId) { \
	sql += " AND `tool_type_id`=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->toolTypeId.getValue({})); \
} \
if (query->toolTypeCode) { \
	sql += " AND `tool_type_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->toolTypeCode.getValue({})); \
} \
if (query->toolTypeName) { \
	sql += " AND `tool_type_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->toolTypeName.getValue({})); \
} \
if (query->brand) { \
	sql += " AND `brand`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->brand.getValue({})); \
} \
if (query->spec) { \
	sql += " AND `spec`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->spec.getValue({})); \
} \
if (query->status) { \
	sql += " AND `status`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue({})); \
}

uint64_t WorkFixtureDAO::count(const WorkFixtureQuery::Wrapper &query)
{  // 查询基于参数查询语句的总数据条数
	string sql("SELECT COUNT(*) FROM `tm_tool` WHERE 1=1 ");
	SqlParams params;
	QUERY_PARAMS_PARSE(query, sql, params);
	return sqlSession->executeQueryNumerical(sql, params);
}

list<WorkFixtureDO> WorkFixtureDAO::selectWithPageCondition(const WorkFixtureQuery::Wrapper &query)
{  // 通过分页条件和查询条件来查询一组工装夹具的列表信息
	string sql("SELECT `tool_id`, `tool_code`, `tool_name`, `brand`, `spec`, `tool_type_id`, "
		"`tool_type_code`, `tool_type_name`, `quantity`, `quantity_avail`, `mainten_type`, "
		"`next_mainten_date`, `status`, `remark` FROM `tm_tool` WHERE 1=1");
	SqlParams params;
	QUERY_PARAMS_PARSE(query, sql, params);
	WorkFixtureMapper mapper;
	sql += " LIMIT " + to_string(((query->pageIndex - 1) * query->pageSize)) + ","
		+ to_string(query->pageSize);
	return sqlSession->executeQuery<WorkFixtureDO, WorkFixtureMapper>(sql, mapper, params);
}

list<WorkFixtureDO> WorkFixtureDAO::selectById(uint64_t id)
{  // 通过Id查询单条工装夹具的详细信息
	string sql("SELECT `tool_id`, `tool_code`, `tool_name`, `brand`, `spec`, `tool_type_id`, "
		"`tool_type_code`, `tool_type_name`, `quantity`, `quantity_avail`, `mainten_type`, "
		"`next_mainten_date`, `status`, `remark` FROM `tm_tool` WHERE `tool_id`=?");
	WorkFixtureMapper mapper;
	return sqlSession->executeQuery<WorkFixtureDO, WorkFixtureMapper>(sql, mapper, "%ull", id);
}

uint64_t WorkFixtureDAO::insert(const WorkFixtureDO &iObj)
{  // 插入一条新的工装夹具信息
	SqlParams params;
	string sql("INSERT INTO `tm_tool` ");
	// 解析并拼接所有参数
	DO_PARAMS_PARSE(iObj, sql, params);
	return sqlSession->executeInsert(sql, params);
}

int WorkFixtureDAO::update(const WorkFixtureDO &uObj)
{  // 根据工装夹具ID来修改对应工装夹具的信息
	SqlParams params;
	string sql("UPDATE `tm_tool` ");
	DO_PARAMS_PARSE(uObj, sql, params);
	// 工装夹具ID是修改的判断条件，此处还需补上
	sql += " WHERE `tool_id`=?";
	SQLPARAMS_PUSH(params, "ull", uint64_t, uObj.getToolId());
	return sqlSession->executeUpdate(sql, params);
}

int WorkFixtureDAO::deleteBatch(const list<uint64_t> &id)
{
	string sql("DELETE FROM `tm_tool` WHERE 1=0 ");
	SqlParams params;
	for (auto &i : id)
	{
		sql += "OR `tool_id`=? ";
		SQLPARAMS_PUSH(params, "ull", uint64_t, i);
	}
	return sqlSession->executeUpdate(sql, params);
}


//根据传入的id list查询数据
list<WorkFixtureDO> WorkFixtureDAO::selectByIdList(const list<uint64_t>& id)
{
	string sql("SELECT `tool_id`, `tool_code`, `tool_name`, `brand`, `spec`, `tool_type_id`, "
		"`tool_type_code`, `tool_type_name`, `quantity`, `quantity_avail`, `mainten_type`, "
		"`next_mainten_date`, `status`, `remark` FROM `tm_tool` WHERE 1=0 ");
	SqlParams params;
	WorkFixtureMapper mapper;
	for (auto& i : id)
	{
		string t = "OR `tool_id`=";
		t += to_string(i);
		t += " ";
		sql += t;
	}
	return sqlSession->executeQuery<WorkFixtureDO, WorkFixtureMapper>(sql, mapper);
}



// 导出相关函数在下面实现
