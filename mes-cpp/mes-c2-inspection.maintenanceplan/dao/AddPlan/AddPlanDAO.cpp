
#include "stdafx.h"
#include "AddPlanDAO.h"
#include "AddPlanMapper.h"
#include <sstream>






uint64_t AddPlanDAO::insert(const Dv_check_planDO& iObj)
{
	string sql = "INSERT INTO `dv_check_plan` (`plan_code`,`plan_name`, `plan_type`, `cycle_count`, `cycle_type`, `start_date`, `end_date`, `status`, `remark`,`create_by`, `create_time`) VALUES (?,?,?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%ui%s%s%s%s%s%s%s", iObj.getPlan_code(), iObj.getPlan_name(), iObj.getPlan_type(), iObj.getCycle_count(), iObj.getCycle_type(), iObj.getStart_date(), iObj.getEnd_date(), iObj.getStatus(), iObj.getRemark(), iObj.getCreate_by(), iObj.getCreate_time());
}

