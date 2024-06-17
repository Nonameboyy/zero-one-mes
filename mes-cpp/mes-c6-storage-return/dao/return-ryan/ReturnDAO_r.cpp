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
#include "ReturnDAO_r.h"
#include "ReturnMapper_r.h"
#include <sstream>

#define DIS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rt_code) { \
	sql << " AND `rt_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rt_code.getValue("")); \
} \
if (query->rt_name) { \
	sql << " AND rt_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rt_name.getValue("")); \
} \
if (query->po_code) { \
	sql << " AND po_code=?"; \
	SQLPARAMS_PUSH(params, "s",std::string, query->po_code.getValue("")); \
}

//uint64_t ReturnDAO::count(const ReturnQuery::Wrapper& query)
//{
//	return 1;
//}
//
//std::list<ReturnDO> ReturnDAO::selectWithPage(const ReturnQuery::Wrapper& query)
//{
//	return {};
//}
//
//std::list<ReturnDO> ReturnDAO::selectByName(const string& name)
//{
//	return {};
//}
//
//uint64_t ReturnDAO::insert(const ReturnDO& iObj)
//{
//	return 1;
//}

uint64_t ReturnDAO_r::count(const ReturnQuery_r::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_rt_vendor";
	DIS_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ReturnDO_r> ReturnDAO_r::selectWithPage(const ReturnQuery_r::Wrapper& query, int flag)
{
	stringstream sql;
	sql << "SELECT rt_id,rt_code,rt_name,po_code, vendor_name, batch_code, rt_date, status, remark FROM wm_rt_vendor";
	DIS_TERAM_PARSE(query, sql);
	if (!flag)
		sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReturnMapper_r mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery <ReturnDO_r, ReturnMapper_r>(sqlStr, mapper, params);
}

int ReturnDAO_r::update(const ReturnDO_r& uObj)
{
	//rt_code rt_name po_code vendor_name batch_code rt_date status remark
	string sql = "UPDATE `wm_rt_vendor` SET `rt_code`=?, `rt_name`=?, `po_code`=? , `vendor_name`=?, `batch_code`=?, `rt_date`=?, `status`=? , `remark`=? WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%ull", uObj.getRt_code(), uObj.getRt_name(), uObj.getPo_code(), uObj.getVendor_name(),
		uObj.getBatch_code(), uObj.getRt_date(), uObj.getStatus_(), uObj.getRemark(), uObj.getRt_id());
}

int ReturnDAO_r::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `wm_rt_vendor` WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ReturnDAO_r::updateStatusById(uint64_t id)
{
	string executeStatus = "Finished";
	string sql = "UPDATE `wm_rt_vendor` SET `status`=? WHERE `rt_id`=?";
	return sqlSession->executeUpdate(sql, "s%%ull", executeStatus,id);
}
