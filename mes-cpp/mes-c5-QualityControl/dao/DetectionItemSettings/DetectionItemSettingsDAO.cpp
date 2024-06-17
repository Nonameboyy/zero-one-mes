#include "stdafx.h"
#include "DetectionItemSettingsDAO.h"
#include "DetectionItemSettingsMapper.h"
#include <sstream>

#define DIS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->code) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
} \
if (query->name) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->type) { \
	sql << " AND type=?"; \
	SQLPARAMS_PUSH(params, "s",std::string, query->type.getValue("")); \
}

uint64_t DetectionItemSettingsDAO::count(const DetectionItemSettingsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_index";
	DIS_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
	return -1;
}

std::list<DetectionItemSettingsDO> DetectionItemSettingsDAO::selectWithPage(const DetectionItemSettingsQuery::Wrapper& query,int flag)
{
	stringstream sql;
	sql << "SELECT index_id,index_code,index_name,index_type,qc_tool,remark FROM qc_index";
	DIS_TERAM_PARSE(query, sql);
	if(!flag)
		sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DetectionItemSettingsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery <DetectionItemSettingsDO, DetectionItemSettingsMapper>(sqlStr, mapper, params);
}

uint64_t DetectionItemSettingsDAO::insert(const DetectionItemSettingsDO& iobj)
{
	string sql = "INSERT INTO `qc_index` "
		" (`index_id`,`index_code`,`index_name`,`index_type`,`qc_tool`,`remark`) "
		" VALUES (?,?,?,?,?,?) ";
	return sqlSession->executeInsert(sql, "%ull%s%s%s%s%s",
		iobj.getId(), iobj.getCode(), iobj.getName(), iobj.getType(), iobj.getTool(), iobj.getRemark());
}

int DetectionItemSettingsDAO::update(const DetectionItemSettingsDO& uobj)
{
	string sql = "UPDATE `qc_index` SET "
		" `index_code`=?,`index_name`=?,`index_type`=?,`qc_tool`=?,`remark`=? "
		" WHERE `index_id`=?";
	return sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%ull", uobj.getCode(), uobj.getName(), uobj.getType(), uobj.getTool(), uobj.getRemark(),
		uobj.getId());

}

int DetectionItemSettingsDAO::remove(uint64_t id)
{
	string sql = "DELETE FROM `qc_index` WHERE `index_id` = ?";
	return sqlSession->executeUpdate(sql, "%ull", id);

}
