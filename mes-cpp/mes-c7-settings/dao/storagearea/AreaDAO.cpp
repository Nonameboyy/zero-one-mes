#include "stdafx.h"
#include "AreaDAO.h"
#include "dao/storagearea/AreaMapper.h"
#include <sstream>

//Ìõ¼þ½âÎöºê
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
SQLPARAMS_PUSH(params, "s", std::string, query->area_name.getValue("")); \
sql << " WHERE 1=1"; \
if (query->location_id) { \
	sql << " AND `location_id`=?"; \
	SQLPARAMS_PUSH(params, "ll", std::int64_t, query->location_id.getValue(0)); \
} \
if (query->area_code) { \
	sql << " AND area_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->area_code.getValue("")); \
} \
if (query->position_x) { \
	sql << " AND position_x=?"; \
	SQLPARAMS_PUSH(params, "i", std::int32_t, query->position_x.getValue(0)); \
} \
if (query->position_y) { \
	sql << " AND position_y=?"; \
	SQLPARAMS_PUSH(params, "i", std::int32_t, query->position_y.getValue(0)); \
} \
if (query->position_z) { \
	sql << " AND position_z=?"; \
	SQLPARAMS_PUSH(params, "i", std::int32_t, query->position_z.getValue(0)); \
} 

std::uint64_t AreaDAO::count(const AreaQuery::Wrapper& query)
{
	stringstream sql;
	sql << "WITH TMP AS (SELECT * FROM wm_storage_area WHERE `area_name` LIKE CONCAT('%',?,'%') ) SELECT COUNT(*) FROM TMP";
	SAMPLE_TERAM_PARSE(query, sql);
	std::string sqlstr = sql.str();
	return sqlSession->executeQueryNumerical(sqlstr, params);
}

std::list<AreaDO> AreaDAO::selectWithPage(const AreaQuery::Wrapper& query)
{
	stringstream sql;
	sql << "WITH TMP AS (SELECT * FROM wm_storage_area WHERE `area_name` LIKE CONCAT('%',?,'%') ) SELECT location_id,area_id,area_code,area_name,area,max_loa,position_x,position_y,position_z,enable_flag,remark, \
			attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM TMP";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AreaMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AreaDO, AreaMapper>(sqlStr, mapper, params);
}

std::list<AreaDO> AreaDAO::selectByName(const string& area_name)
{
	string sql = "SELECT * FROM wm_storage_area WHERE `area_name` LIKE CONCAT('%',?,'%')";
	AreaMapper mapper;
	return sqlSession->executeQuery<AreaDO, AreaMapper>(sql, mapper, "%s", area_name);
}

std::uint64_t AreaDAO::insert(const AreaDO& iObj)
{
	string sql = "INSERT INTO `wm_storage_area`(area_code, area_name, location_id, area, max_loa, position_x, position_y, position_z, enable_flag, remark, attr1, attr2, attr3, attr4, create_by, create_time, update_by, update_time) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%ll%d%d%i%i%i%s%s%s%s%i%i%s%s%s%s", iObj.getAreaCode(), iObj.getAreaName(),iObj.getLid(),iObj.getAreaSize(),
		iObj.getMaxLoa(),iObj.getX(),iObj.getY(),iObj.getZ(),iObj.getIson(),iObj.getRemark(),iObj.getText1(),iObj.getText2(),iObj.getText3(),iObj.getText4(),iObj.getCreateBy(),
		iObj.getCreateTime(),iObj.getUpdateBy(),iObj.getUpdateTime());
}

std::uint64_t AreaDAO::update(const AreaDO& uObj)
{
	//update wm_storage_area set location_id=4 where area_id=22;
	string sql = "UPDATE `wm_storage_area` SET `area_code`=?, `area_name`=?, `location_id`=?, `area`=?, `max_loa`=?, `position_x`=?, `position_y`=?, `position_z`=?, `enable_flag`=?, `remark`=?, `update_by`=?,  `update_time`=?  WHERE `area_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%ll%d%d%i%i%i%s%s%s%s%ll", uObj.getAreaCode(), uObj.getAreaName(), uObj.getLid(), uObj.getAreaSize(),
		uObj.getMaxLoa(),uObj.getX(),uObj.getY(),uObj.getZ(),uObj.getIson(),uObj.getRemark(),
		uObj.getUpdateBy(),uObj.getUpdateTime(),uObj.getId());
}

std::uint64_t AreaDAO::deleteById(std::list<int64_t>& ids)
{
	//delete from wm_storage_area where area_id in(6,16,26);
	stringstream sql;
	SqlParams params;
	sql << "DELETE FROM `wm_storage_area` WHERE `area_id` in  (  ?";
	
	auto i = ids.begin();
	SQLPARAMS_PUSH(params, "ll", std::int64_t, *i++);
	
	for ( ; i!=ids.end(); i++)
	{	
		sql << " , ?";
		SQLPARAMS_PUSH(params, "ll", std::int64_t, *i);
	}
	sql << ")";
	std::string sqlstr = sql.str();
	return sqlSession->executeUpdate(sqlstr, params);
}


