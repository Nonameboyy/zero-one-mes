#include "stdafx.h"
#include "ProdTaskDAO.h"
#include "ProdTaskMapper.h"
#include <sstream>

// 修改数据
int ProdTaskDAO::update(const ProdTaskModifyDO& uObj)
{
	string sql = "UPDATE `pro_task` SET `task_name`=?, `process_name`=?, `workstation_name`=?, `start_time`=?,`end_time`=? WHERE `task_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%ull", uObj.getTask_name(),uObj.getProcess_name(), uObj.getWorkstation_name(),uObj.getStart_time(),uObj.getEnd_time(),uObj.getTask_id());
}

// 通过ID删除数据
int ProdTaskDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pro_task` WHERE `task_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}