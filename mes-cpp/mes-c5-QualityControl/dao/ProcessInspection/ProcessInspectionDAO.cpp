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
#include "ProcessInspectionDAO.h"
#include "ProcessInspectionMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PROCESSINSPECTION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ipqc_code) { \
	sql << " AND `ipqc_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ipqc_code.getValue("")); \
} \
if (query->ipqc_type) { \
	sql << " AND ipqc_type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ipqc_type.getValue("")); \
} \
if (query->workorder_code) { \
	sql << " AND workorder_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workorder_code.getValue("")); \
}\
if (query->item_code) { \
	sql << " AND item_code=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_code.getValue("")); \
}\
if (query->item_name) { \
	sql << " AND item_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->item_name.getValue("")); \
}\
if (query->check_result) { \
	sql << " AND check_result=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->check_result.getValue("")); \
}


int ProcessInspectionDAO::update(const ProcessInspectionDO & uObj)
{
	//string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	//return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
	string sql = "UPDATE qc_ipqc \
		SET \
		ipqc_code=?,\
		ipqc_name=?,\
		ipqc_type=?,\
		workorder_code=?,\
		workorder_name=?,\
		workstation_code=?,\
		workstation_name=?,\
		item_code=?, \
		item_name=?, \
		specification=?, \
		process_code=?,\
		process_name=?,\
		task_code=?,\
		task_name=?,\
		unit_of_measure=?,\
		quantity_check=?, \
		quantity_unqualified=?,\
		quantity_qualified=?,\
		cr_quantity=?,\
		maj_quantity=?,\
		min_quantity=?,\
		inspect_date=?,\
		check_result=?, \
		inspector=?,\
		remark=? WHERE ipqc_id=?";
	return sqlSession->executeUpdate(sql,
		"%ull%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%s%s%s%s%ull",
		uObj.getIpqc_Code(), uObj.getIpqc_Name(),
		uObj.getIpqc_Type(), uObj.getWorkorder_Code(),
		uObj.getWorkorder_Name(), uObj.getWorkstation_Code(),
		uObj.getWorkstation_Name(), uObj.getItem_Code(),
		uObj.getItem_Name(), uObj.getSpecification(),
		uObj.getProcess_Code(), uObj.getProcess_Name(),
		uObj.getTask_Code(), uObj.getTask_Name(),
		uObj.getUnit_Of_Measure(), uObj.getQuantity_Check(),
		uObj.getQuantity_Unqualified(), uObj.getQuantity_Qualified(),
		uObj.getCr_Quantity(), uObj.getMaj_Quantity(),
		uObj.getMin_Quantity(), uObj.getInspect_Date(),
		uObj.getCheck_Result(), uObj.getInspector(),
		uObj.getRemark(), uObj.getId());
	//return {};
}

list<ProcessInspectionDO> ProcessInspectionDAO::select(const ProcessInspectionQuery::Wrapper& query,int flag)
{
	stringstream sql;
	sql << "SELECT ipqc_id,ipqc_code,ipqc_type,workorder_code,item_code, item_name, specification, unit_of_measure,quantity_check, check_result, inspect_date, inspector,`status` from qc_ipqc";
	PROCESSINSPECTION_TERAM_PARSE(query, sql);
	if(!flag)
		sql << " LIMIT " << ((query->pageIndex-1) * query->pageSize) << "," << query->pageSize;
	ProcessInspectionQueryMapper mapper;
	string str = sql.str();
	return sqlSession->executeQuery<ProcessInspectionDO, ProcessInspectionQueryMapper>(str, mapper,params);
}

uint64_t ProcessInspectionDAO::count(const ProcessInspectionQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_ipqc";
	PROCESSINSPECTION_TERAM_PARSE(query, sql);
	string str = sql.str();
	return sqlSession->executeQueryNumerical(str, params);
}

bool ProcessInspectionDAO::deleteById(uint64_t id)
{
	string sql = "delete from `qc_ipqc` where `ipqc_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

// 获取过程检验单详情
std::list<ProcessInspectionDO> ProcessInspectionDAO::selectInspectionDetails(const ProcessInspectionQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT ipqc_id,ipqc_code,ipqc_name,ipqc_type,workorder_code,workorder_name,workstation_code,workstation_name,quantity_check,item_code,item_name,unit_of_measure,specification,process_code,process_name,task_code,quantity_unqualified,quantity_qualified,cr_quantity,maj_quantity,min_quantity,inspect_date,check_result,inspector,remark FROM qc_ipqc";
	PROCESSINSPECTION_TERAM_PARSE(query, sql);
	ProcessInspectionMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProcessInspectionDO, ProcessInspectionMapper>(sqlStr, mapper, params);
	//return std::list<ProcessinSpectionDO>();
}

// 确认检验单
int ProcessInspectionDAO::updateConfirmOrders(const ProcessInspectionDO& uObj) {
	string sql = "UPDATE `qc_ipqc` SET `check_result`=?, `status`=? WHERE `ipqc_code`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getCheck_Result(), uObj.getStatus_Order(), uObj.getIpqc_Code());
	//return 0;
}

// 完成检验单
int ProcessInspectionDAO::updateFinishOrders(const ProcessInspectionDO& uObj) {
	string sql = "UPDATE `pro_feedback` SET `quantity_qualified`=`quantity_qualified`+?, `quantity_unquanlified`=`quantity_unquanlified`+?, `quantity_uncheck`=`quantity_uncheck`-? WHERE `task_code`=?";
	return sqlSession->executeUpdate(sql, "%d%d%d%s", uObj.getQuantity_Qualified(), uObj.getQuantity_Unqualified(), uObj.getQuantity_Check(), uObj.getTask_Code());
	//return 0;
}

uint64_t ProcessInspectionDAO::insert(const ProcessInspectionDO& iObj) {
	string sql = "INSERT INTO `qc_ipqc` \
		(`ipqc_code`, `ipqc_name`, `ipqc_type`,`template_id`, `workorder_id`,\
		`workstation_id`,`item_id`,`task_code`,`task_name`,`workorder_code`,\
		`workorder_name`, `workstation_code`, `workstation_name`, `process_code`,\
		`process_name`,`item_code`, `item_name`, `specification`, `unit_of_measure`,\
		`quantity_check`, `quantity_unqualified`, `quantity_qualified`, `cr_quantity`,\
		`maj_quantity`, `min_quantity`, `check_result`, `inspect_date`, `inspector`, `remark`)\
		 VALUES (?,?,?,?,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql,
		"%s%s%s%i%i%i%i%s%s%s%s%s%s%s%s%s%s%s%s%d%d%d%d%d%d%s%s%s%s",
		iObj.getIpqc_Code(), iObj.getIpqc_Name(),
		iObj.getIpqc_Type(), 0, 0, 0, 0, iObj.getTask_Code(),
		iObj.getTask_Name(), iObj.getWorkorder_Code(),
		iObj.getWorkorder_Name(), iObj.getWorkstation_Code(),
		iObj.getWorkstation_Name(), iObj.getProcess_Code(),
		iObj.getProcess_Name(), iObj.getItem_Code(),
		iObj.getItem_Name(), iObj.getSpecification(),
		iObj.getUnit_Of_Measure(), iObj.getQuantity_Check(),
		iObj.getQuantity_Unqualified(), iObj.getQuantity_Qualified(),
		iObj.getCr_Quantity(), iObj.getMaj_Quantity(),
		iObj.getMin_Quantity(), iObj.getCheck_Result(),
		iObj.getInspect_Date(), iObj.getInspector(),
		iObj.getRemark());
}