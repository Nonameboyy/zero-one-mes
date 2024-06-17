#pragma once


#ifndef _PRODTASK_Mapper_
#define _PRODTASK_Mapper_

#include "Mapper.h"
#include "../../domain/do/ProdTask/ProdTaskDO.h"
/**
 * �޸���������
 */
class ProdTaskModifyMapper : public Mapper<ProdTaskModifyDO>
{
public:
	ProdTaskModifyDO mapper(ResultSet* resultSet) const override
	{
		ProdTaskModifyDO data;
		//����ʱ��
		data.setEnd_time(resultSet->getString(1));
		//��ʼʱ��
		data.setStart_time(resultSet->getString(2));
		//������
		data.setProcess_name(resultSet->getString(3));
		//������
		data.setTask_name(resultSet->getString(4));
		//����վ��
		data.setWorkstation_name(resultSet->getString(5));
		//����id
		data.setTask_id(resultSet->getUInt64(6));
		return data;
	}
};

/**
 * ɾ����������
 */
class ProdTaskRemoveMapper : public Mapper<ProdTaskRemoveDO>
{
public:
	ProdTaskRemoveDO mapper(ResultSet* resultSet) const override
	{
		ProdTaskRemoveDO data;

		//����ʱ��
		data.setEnd_time(resultSet->getString(1));
		//��ʼʱ��
		data.setStart_time(resultSet->getString(2));
		//������
		data.setProcess_name(resultSet->getString(3));
		//������
		data.setTask_name(resultSet->getString(4));
		//����վ��
		data.setWorkstation_name(resultSet->getString(5));
		//����id
		data.setTask_id(resultSet->getUInt64(6));
		return data;
	}
};



#endif // !_PRODTASK0_Mapper_
