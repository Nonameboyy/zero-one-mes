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
#include "ProduceWorkDAO.h"
#include "ProduceWorkMapper.h"
#include <sstream>

list<ProduceWorkDO> ProduceWorkDAO::selectByRecord_id(const uint64_t& record_id)
{
	stringstream sql;
	sql << "SELECT record_id,feedback_type,workorder_code,task_code,item_code,item_name,unit_of_measure,specification,quantity_feedback,quantity_uncheck,nick_name,record_nick ,feedback_time,remark FROM pro_feedback WHERE record_id=" << record_id;
	ProduceWorkMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProduceWorkDO, ProduceWorkMapper>(sqlStr, mapper);
}
//
//
uint64_t ProduceWorkDAO::insert(const ProduceWorkDO& iObj)
{
	string sql = "INSERT INTO `pro_feedback`"
		         "(`feedback_type`, `workorder_code`, `task_code`, `item_code`,`item_name`,`unit_of_measure`,`specification`,`quantity_feedback`,`quantity_uncheck`,`nick_name`,`record_nick`,`feedback_time`,`remark`,"
		         "`workstation_id`, `workorder_id`, `route_id`, `process_id`, `item_id`)"
	             "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%d%d%s%s%s%s%ull%ull%ull%ull%ull", iObj.getFeedback_type(), iObj.getWorkorder_code(), iObj.getTask_code(),iObj.getItem_code(),
		iObj.getItem_name(),iObj.getUnit_of_measure(),iObj.getSpecification(),iObj.getQuantity_feedback(),iObj.getQuantity_uncheck(),iObj.getNick_name(),
		iObj.getRecord_nick(),iObj.getFeedback_time(),iObj.getRemark(),iObj.getWorkstation_id(),iObj.getWorkorder_id(),iObj.getRoute_id(),iObj.getProcess_id(),iObj.getItem_id());
}
//
int ProduceWorkDAO::update(const ProduceWorkDO& uObj)
{
	string sql = "UPDATE `pro_feedback` SET `feedback_type`=?, `workorder_code`=?, `task_code`=? ,`item_code`=?,"
	             "`item_name`=?,`unit_of_measure`=?,`specification`=?,`quantity_feedback`=?,`quantity_uncheck`=?,`nick_name`=?,`record_nick`=?,"
	             "`feedback_time`=?,`remark`=? WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%d%d%s%s%s%s%ull", \
		uObj.getFeedback_type(), uObj.getWorkorder_code(), uObj.getTask_code(), uObj.getItem_code(), uObj.getItem_name(),
		uObj.getUnit_of_measure(), uObj.getSpecification(), uObj.getQuantity_feedback(), uObj.getQuantity_uncheck(),
		uObj.getNick_name(), uObj.getRecord_nick(), uObj.getFeedback_time(), uObj.getRemark(),uObj.getRecord_id());
}

