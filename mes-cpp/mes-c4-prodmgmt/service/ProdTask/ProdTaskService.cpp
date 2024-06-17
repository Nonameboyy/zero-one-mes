
#include "stdafx.h"
#include "ProdTaskService.h"
#include "../../dao/ProdTask/ProdTaskDAO.h"

bool ProdTaskService::updateData(const ProdTaskModifyDTO::Wrapper& dto)
{
	// 组装DO数据
	ProdTaskModifyDO data;
// 	data.setId(dto->id.getValue(0));
// 	data.setName(dto->name.getValue(""));
// 	data.setSex(dto->sex.getValue(""));
// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Task_name, task_name, Workstation_name, workstation_name, Process_name, process_name, Start_time, start_time, End_time, end_time);
	// 执行数据修改
	ProdTaskDAO dao;
	return dao.update(data) == 1;
}

bool ProdTaskService::removeData(uint64_t id)
{
	ProdTaskDAO dao;
	return dao.deleteById(id) == 1;
}
