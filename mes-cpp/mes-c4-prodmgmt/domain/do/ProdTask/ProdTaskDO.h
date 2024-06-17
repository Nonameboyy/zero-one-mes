#pragma once

#include "../DoInclude.h"
/*
* 修改生产任务实体类
*/
class ProdTaskModifyDO
{
	//任务ID
	CC_SYNTHESIZE(uint64_t, task_id, Task_id);
	// 任务名
	CC_SYNTHESIZE(string, task_name, Task_name);
	// 工作站
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	// 工序
	CC_SYNTHESIZE(string, process_name, Process_name);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, End_time);
public:
	//ProdTaskModifyDO() {}
	ProdTaskModifyDO() {
		task_id = 0;
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};
/*
* 删除生产任务实体类
*/

class ProdTaskRemoveDO
{
	//任务ID
	CC_SYNTHESIZE(uint64_t, task_id, Task_id);
	// 任务名
	CC_SYNTHESIZE(string, task_name, Task_name);
	// 工作站
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	// 工序
	CC_SYNTHESIZE(string, process_name, Process_name);
	// 开始时间
	CC_SYNTHESIZE(string, start_time, Start_time);
	// 结束时间
	CC_SYNTHESIZE(string, end_time, End_time);
public:
	//ProdTaskRemoveDO() {}
	ProdTaskRemoveDO() {
		task_id = 0;
		task_name = "";
		workstation_name = "";
		process_name = "";
		start_time = "";
		end_time = "";
	}
};

