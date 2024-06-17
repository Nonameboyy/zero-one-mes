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
#include "purchasereceivingDAO.h"
#include "purchasereceivingMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PURCHASERECEIVING_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->recptcode) { \
	sql << " AND `recpt_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recptcode.getValue("")); \
} \
if (query->recptname) { \
	sql << " AND recpt_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recptname.getValue("")); \
} \
if (query->vendorname) { \
	sql << " AND vendor_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->vendorname.getValue("")); \
} \
if (query->recptdate) { \
	sql << " AND recpt_date=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->recptdate.getValue("")); \
} \
if (query->pocode) { \
	sql << " AND po_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pocode.getValue("")); \
}

uint64_t purchasereceivingDAO::count(const GetListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM wm_item_recpt";
	PURCHASERECEIVING_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<GetListDO> purchasereceivingDAO::selectWithPage(const GetListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT recpt_code,recpt_name,vendor_name,recpt_date,po_code FROM wm_item_recpt";
	PURCHASERECEIVING_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetListDO, GetListMapper>(sqlStr, mapper, params);
}


uint64_t purchasereceivingDAO::insert(const AddListDO& iObj)
{
	string sql = "INSERT INTO `wm_item_recpt` (`recpt_code`, `recpt_name`, `recpt_date`,`po_code`,`status`,`vendor_id`,`warehouse_name`,`remark`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%i%s%s", iObj.getRecptcode(), iObj.getRecptname(), iObj.getRecptdate(), iObj.getPocode(), iObj.getStatus(), iObj.getVendorid(), iObj.getWarehousename(), iObj.getRemark());
}

int purchasereceivingDAO::update(const ModifyListDO& uObj)
{
	string sql = "UPDATE `wm_item_recpt` SET  `recpt_code`=?, `recpt_name`=?, `recpt_date`=? , `po_code`=? , `status`=? , `vendor_id`=?, `warehouse_name`=? , `remark`=? WHERE `recpt_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%i",
		uObj.getRecptcode(), uObj.getRecptname(), uObj.getRecptdate(), uObj.getPocode(),
		uObj.getStatus(), uObj.getVendorid(), uObj.getWarehousename(), uObj.getRemark(), uObj.getRecptid());
}
