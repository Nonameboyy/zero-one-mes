/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "QcDefectDAO.h"
#include "QcDefectMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->defect_name) { \
	sql << " AND `defect_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->defect_name.getValue("")); \
} \
if (query->index_type) { \
	sql << " AND index_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->index_type.getValue("")); \
} \
if (query->defect_level) { \
	sql << " AND defect_level=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->defect_level.getValue("")); \
}

uint64_t QcDefectDAO::count(const QcDefectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_defect";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QcDefectDO> QcDefectDAO::selectWithPage(const QcDefectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT defect_code,defect_name,index_type,defect_level FROM qc_defect";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QcDefectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<QcDefectDO, QcDefectMapper>(sqlStr, mapper, params);
}

std::list<QcDefectDO> QcDefectDAO::selectByName(const string& name)
{
	string sql = "SELECT defect_name,index_type,defect_level FROM qc_defect WHERE `defect_name` LIKE CONCAT('%',?,'%')";
	QcDefectMapper mapper;
	return sqlSession->executeQuery<QcDefectDO, QcDefectMapper>(sql, mapper, "%s", name);
}

std::list<QcDefectDO> QcDefectDAO::selectByType(const string& type)
{
	string sql = "SELECT defect_name,index_type,defect_level FROM qc_defect WHERE `index_type` LIKE CONCAT('%',?,'%')";
	QcDefectMapper mapper;
	return sqlSession->executeQuery<QcDefectDO, QcDefectMapper>(sql, mapper, "%s", type);
}

std::list<QcDefectDO> QcDefectDAO::selectByLevel(const string& level)
{
	string sql = "SELECT defect_name,index_type,defect_level FROM qc_defect WHERE `defect_level` LIKE CONCAT('%',?,'%')";
	QcDefectMapper mapper;
	return sqlSession->executeQuery<QcDefectDO, QcDefectMapper>(sql, mapper, "%s", level);
}

uint64_t QcDefectDAO::insert(const QcDefectDO& iObj)
{
	string sql = "INSERT INTO `qc_defect` (`defect_code`, `defect_name`, `index_type`, `defect_level`, `create_by`,	`create_time`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s", iObj.getDefectCode(), iObj.getDefectName(), iObj.getIndexType(), iObj.getDefectLevel(), iObj.getCreateBy(), iObj.getCreateTime());
}

uint64_t QcDefectDAO::remove(const string& ids)
{
	string sql = "DELETE FROM `qc_defect` WHERE `defect_id` IN (" + ids + ")";
	return sqlSession->executeUpdate(sql);
}

uint64_t QcDefectDAO::modify(const DefectModifyDTO::Wrapper& dto, const string& update_by, const string& update_time)
{
	const string sql = "UPDATE `qc_defect` SET `defect_name`=?, `index_type`=?, `defect_level`=?, `update_by`=?, `update_time`=? WHERE `defect_id`=?";
	return sqlSession->executeUpdate(sql,                            //
		"%s%s%s%s%s%ll",                //
		dto->defect_name.getValue({}),  //
		dto->index_type.getValue({}),   //
		dto->defect_level.getValue({}), //
		update_by,                      //
		update_time,                    //
		dto->defect_id.getValue({}));
}