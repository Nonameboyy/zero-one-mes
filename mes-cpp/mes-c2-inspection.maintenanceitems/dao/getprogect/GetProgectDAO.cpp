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
#include "GetProgectDAO.h"
#include "GetProgectMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pCode) { \
	sql << " AND `subject_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pCode.getValue("")); \
} \
if (query->pName) { \
	sql << " AND `subject_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pName.getValue("")); \
} \
if (query->pType) { \
	sql << " AND `subject_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pType.getValue("")); \
}\

#define SAMPLE_TERAM_PARSE2(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pId) {\
	sql << " AND pId =?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->pId.getValue("")); \
}\

uint64_t GetProgectDAO::count(const GetProgectQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_subject";
	//SAMPLE_TERAM_PARSE(query, sql);
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<dvSubjectDO> GetProgectDAO::selectWithPage(const GetProgectQuery::Wrapper & query)
{

	stringstream sql;
	sql << "SELECT subject_id,subject_code,subject_type,subject_content,subject_standard,enable_flag,remark FROM dv_subject";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetProgectListAllMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<dvSubjectDO, GetProgectListAllMapper>(sqlStr, mapper, params);
}


std::list<dvSubjectDO> GetProgectDAO::selectById(const GetProgectDetailQuery::Wrapper& query)
{

	stringstream sql;
	sql << "SELECT subject_id, subject_code,subject_name,subject_type,subject_content,subject_standard,enable_flag  FROM dv_subject WHERE `subject_id`=? ";
	GetProgectIdMapper mapper;
	string sqlStr = sql.str();
	int id = query->pId;
	return sqlSession->executeQuery<dvSubjectDO, GetProgectIdMapper>(sqlStr, mapper, "i", id);
}