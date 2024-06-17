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
#include "ProProcessContentDAO.h"
#include "ProProcessContentMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ContentId) { \
	sql << " AND `content_id`=?"; \
	SQLPARAMS_PUSH(params, "i", long int, query->ContentId.getValue(1)); \
} \
if (query->OrderNum) { \
	sql << " AND order_num=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->OrderNum.getValue(1)); \
}

uint64_t ProProcessContentDAO::count(const SetStepExportQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pro_process_content";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ProProcessContentDO> ProProcessContentDAO::selectWithPage(const SetStepExportQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT content_id,order_num, FROM pro_process_content";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProProcessContentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessContentDO, ProProcessContentMapper>(sqlStr, mapper, params);
}

std::list<ProProcessContentDO> ProProcessContentDAO::selectByName(const string& name)
{
	string sql = "SELECT content_id,order_num, FROM pro_process_content WHERE `content_id` LIKE CONCAT(?,'%')";
	ProProcessContentMapper mapper;
	return sqlSession->executeQuery<ProProcessContentDO, ProProcessContentMapper>(sql, mapper, "%s", name);
}

uint64_t ProProcessContentDAO::insert(const ProProcessContentDO& iObj)
{
	string sql = "INSERT INTO `pro_process_content` (`content_id`, `order_num`) VALUES (?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getContentId(), iObj.getOrderNum());
}

int ProProcessContentDAO::update(const ProProcessContentDO& uObj)
{
	string sql = "UPDATE `pro_process_content` SET `order_num`=?, `content_text`=?, `device`=?, `material`=?, `doc_url`=?,`remark`=? WHERE `content_id`=?";
	return sqlSession->executeUpdate(sql, "%ull%s%s%s%s%s%ull", uObj.getOrderNum(), uObj.getContentText(), uObj.getDevice(), uObj.getMaterial(), uObj.getDocUrl(), uObj.getRemark(),uObj.getContentId());
}

int ProProcessContentDAO::deleteByprocessId(uint64_t id)
{
	string sql = "DELETE FROM `pro_process` WHERE `process_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ProProcessContentDAO::deleteBycontentId(uint64_t id)
{
	string sql = "DELETE FROM `pro_process_content` WHERE `content_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
