#include "stdafx.h"
#include "ProcessDAO.h"
#include "ProcessMapper.h"
#include "ProcessListMapper.h"
#include "../../lib-common/include/SimpleDateTimeFormat.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->routeCode) { \
	sql << " AND `route_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->routeCode.getValue("")); \
} \
if (query->routeName) { \
	sql << " AND route_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->routeName.getValue("")); \
} \
if (query->enableFlag) { \
	sql << " AND enable_flag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->enableFlag.getValue("")); \
}

// ͳ�ƹ����б���������
uint64_t ProcessDAO::count(const ProcessListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_route";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// ��ҳ��ѯ�����б�
std::list<ProRouteDO> ProcessDAO::selectWithPage(const ProcessListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT route_id,route_code,route_name,route_desc,enable_flag,remark FROM pro_route";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProcessMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProRouteDO, ProcessMapper>(sqlStr, mapper, params);
}
// ͨ��id��ѯ��������
std::list<ProRouteDO>  ProcessDAO::selectById(const ProcessDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT route_id,route_code,route_name,route_desc,enable_flag,remark FROM pro_route";
	SqlParams params;
	sql << " WHERE 1=1";
	if (query->routeId) {
		sql << " AND `route_id`=?";
		params.emplace_back(SqlParam("i", std::make_shared<int>(query->routeId.getValue(0))));
	};
	ProcessMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProRouteDO, ProcessMapper>(sqlStr, mapper, params);
	
}
// ��ӹ���
uint64_t ProcessDAO::insert(const ProRouteDO& iObj, const string username)
{
	string sql = "INSERT INTO `pro_route` (`route_code`, `route_name`, `route_desc`, `enable_flag`, `remark`,`create_by`,`create_time`) VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", iObj.getRouteCode(), iObj.getRouteName(), iObj.getRouteDesc(), iObj.getEnableFlag(), iObj.getRemark(), username, SimpleDateTimeFormat::format());
}
// �޸Ĺ���
int ProcessDAO::update(const ProRouteDO& iObj, const string updatename)
{
	string sql = "UPDATE `pro_route` SET `route_code`=?, `route_name`=?, `route_desc`=?, `enable_flag`=?, `remark`=?, `update_by`=?, `update_time`=? WHERE `route_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%ull", iObj.getRouteCode(), iObj.getRouteName(), iObj.getRouteDesc(), iObj.getEnableFlag(), iObj.getRemark(), updatename, SimpleDateTimeFormat::format(), iObj.getRouteId());
}

int ProcessDAO::deleteById(list<uint64_t> id)
{
	stringstream sql;
	sql << "DELETE FROM `pro_route_process` WHERE `record_id` in (";
	auto p = id.begin();
	//��һ����������
	sql << to_string(*p);
	++p;
	for (; p != id.end(); ++p) {
		if (*p) {
			sql << "," << to_string(*p);
		}
	}
	sql << ")";
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr);
}
//��������
list<ProRouteDO> ProcessDAO::selectWithProcessExport(const ProcessListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT route_code,route_name,route_desc,enable_flag FROM pro_route";
	SAMPLE_TERAM_PARSE(query, sql);
	ProcessListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProRouteDO, ProcessListMapper>(sqlStr, mapper, params);
}
//ɾ������
int ProcessDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pro_route` WHERE `route_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}