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
#include "ProinSpectDAO.h"
#include <sstream>
#include"../../dao/ProinSpect/ProinSpectMapper1.h"
#include"../../dao/ProinSpect/ProinSpectMapper2.h"


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ipqc_id) { \
	sql << " AND `ipqc_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->ipqc_id.getValue(0)); \
} \
if (query->line_id) { \
	sql << " AND line_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->line_id.getValue(0)); \
}

//定义一个让代码更加简洁
#define UPDATE_QC_IPQC(uObj) [=](){\
    if(uObj.getDefect_level()=="CR" ) return ProinspectDAO::update_qc(uObj, "cr_quantity");\
    else if(uObj.getDefect_level()=="MAJ") return ProinspectDAO::update_qc(uObj, "maj_quantity");\
    else return ProinspectDAO::update_qc(uObj, "min_quantity");\
}()

uint64_t ProinspectDAO::count1(const ProinspectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_ipqc_line";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t ProinspectDAO::count2(const ProinspectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_defect_record";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


int  ProinspectDAO::update_qc(const ProinspectDO& uObj, string mem1) {//用来修改最终显示的表--qc_ipqc_line
	string sql = "UPDATE `qc_ipqc_line` SET `" + mem1 + "` = (SELECT SUM(`defect_quantity`)  FROM(SELECT * FROM `qc_defect_record` WHERE `line_id` = ? AND `defect_level` = ? ) AS Q1) WHERE `line_id` = ? ";
	return sqlSession->executeUpdate(sql, "%ull%s%ull", uObj.getLine_id(), uObj.getDefect_level(), uObj.getLine_id());
}


uint64_t ProinspectDAO::insert(const ProinspectDO& iObj)
{
	sqlSession->beginTransaction();//开启事务
	string sql = "INSERT INTO `qc_defect_record` ( `qc_type`,`qc_id`, `line_id`,`defect_name`,`defect_level`,`defect_quantity`,`remark`) VALUES (?, ?, ?, ? ,?, ?, ?)";
	int result1 = sqlSession->executeInsert(sql, "%s%ull%ull%s%s%i%s", iObj.getQc_type(), iObj.getQc_id(), iObj.getLine_id(), iObj.getDefect_name(), iObj.getDefect_level(), iObj.getDefect_quantity(), iObj.getRemark());
	if (result1 == 0) {
		return 0;
	}
	else {
		int result2 = UPDATE_QC_IPQC(iObj);
		if (result2 == 0) {
			sqlSession->rollbackTransaction();//事务回滚
			return  0;
		}
		else {
			sqlSession->commitTransaction();
		}
	}
	return result1;
}

int ProinspectDAO::update(const ProinspectDO& uObj)
{
	sqlSession->beginTransaction();//开启事务
	string sql = "UPDATE `qc_defect_record` SET `qc_type`=?, `qc_id`=? , `line_id`= ?,`defect_name` = ?,`defect_level`= ?,`remark`= ? ,`defect_quantity` = ?  WHERE `record_id`=?";
	int result1 = sqlSession->executeUpdate(sql, "%s%ull%ull%s%s%s%i%ull", uObj.getQc_type(), uObj.getQc_id(), uObj.getLine_id(), uObj.getDefect_name(), uObj.getDefect_level(), uObj.getRemark(), uObj.getDefect_quantity(), uObj.getRecord_id());
	if (result1 == 0) {
		return 0;
	}
	else {
		int result2 = UPDATE_QC_IPQC(uObj);
		if (result2 == 0) {
			sqlSession->rollbackTransaction();//事务回滚
			return  0;
		}
		else {
			sqlSession->commitTransaction();
		}
	}
	return result1;
}

int ProinspectDAO::deleteById(const ProinspectDO& dObj)
{
	sqlSession->beginTransaction();//开启事务
	string sql = "DELETE FROM `qc_defect_record` WHERE `record_id`=?";
	int result1 = sqlSession->executeUpdate(sql, "%ull", dObj.getRecord_id());
	if (result1 == 0) {
		return 0;
	}
	else {
		int result2 = UPDATE_QC_IPQC(dObj);
		if (result2 == 0) {
			sqlSession->rollbackTransaction();//事务回滚
			return  0;
		}
		else {
			sqlSession->commitTransaction();
		}
	}
	return result1;
}

list<ProinspectDO> ProinspectDAO::selectByIpqc_id(const ProinspectQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT index_name,index_type,qc_tool,check_method,stander_val,\
	unit_of_measure,threshold_max,threshold_min,cr_quantity,maj_quantity,\
	min_quantity FROM qc_ipqc_line";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProinspectMapper1 mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProinspectDO, ProinspectMapper1>(sqlStr, mapper, params);
}

list<ProinspectDO> ProinspectDAO::selectByLine_id(const ProinspectQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT qc_type,qc_id,line_id,defect_name,defect_level,defect_quantity,remark FROM qc_defect_record";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProinspectMapper2 mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProinspectDO, ProinspectMapper2>(sqlStr, mapper, params);
}
