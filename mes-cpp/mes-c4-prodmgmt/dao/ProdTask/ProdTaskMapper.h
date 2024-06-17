#pragma once


#ifndef _PRODTASK_Mapper_
#define _PRODTASK_Mapper_

#include "Mapper.h"
#include "../../domain/do/ProdTask/ProdTaskDO.h"
/**
 * 修改生产任务
 */
class ProdTaskModifyMapper : public Mapper<ProdTaskModifyDO>
{
public:
	ProdTaskModifyDO mapper(ResultSet* resultSet) const override
	{
		ProdTaskModifyDO data;
		//结束时间
		data.setEnd_time(resultSet->getString(1));
		//开始时间
		data.setStart_time(resultSet->getString(2));
		//工序名
		data.setProcess_name(resultSet->getString(3));
		//任务名
		data.setTask_name(resultSet->getString(4));
		//工作站名
		data.setWorkstation_name(resultSet->getString(5));
		//工作id
		data.setTask_id(resultSet->getUInt64(6));
		return data;
	}
};

/**
 * 删除生产任务
 */
class ProdTaskRemoveMapper : public Mapper<ProdTaskRemoveDO>
{
public:
	ProdTaskRemoveDO mapper(ResultSet* resultSet) const override
	{
		ProdTaskRemoveDO data;

		//结束时间
		data.setEnd_time(resultSet->getString(1));
		//开始时间
		data.setStart_time(resultSet->getString(2));
		//工序名
		data.setProcess_name(resultSet->getString(3));
		//任务名
		data.setTask_name(resultSet->getString(4));
		//工作站名
		data.setWorkstation_name(resultSet->getString(5));
		//工作id
		data.setTask_id(resultSet->getUInt64(6));
		return data;
	}
};



#endif // !_PRODTASK0_Mapper_
