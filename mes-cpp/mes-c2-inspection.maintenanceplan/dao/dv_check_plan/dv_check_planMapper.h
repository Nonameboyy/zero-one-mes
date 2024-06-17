#pragma once
/*
* 
*/
#ifndef _DV__CHECK__PLAN_MAPPER_
#define _DV__CHECK__PLAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"

/**
 * dv_check_plan±Ì£¨◊÷∂Œ∆•≈‰”≥…‰
 */
class Dv_check_planMapper : public Mapper<Dv_check_planDO>
{
public:
	Dv_check_planDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_planDO data;


		data.setPlan_id(resultSet->getUInt64(1));
		data.setPlan_code(resultSet->getString(2));
		data.setPlan_name(resultSet->getString(3));
		data.setPlan_type(resultSet->getString(4));
		//data.setStatus(resultSet->getString(5));
		data.setStart_date(resultSet->getString(5));
		data.setEnd_date(resultSet->getString(6));
		data.setCycle_type(resultSet->getString(7));
		data.setCycle_count(resultSet->getUInt(8));
		data.setStatus(resultSet->getString(9));
		data.setRemark(resultSet->getString(10));
		data.setAttr1(resultSet->getString(11));
		data.setAttr2(resultSet->getString(12));
		data.setAttr3(resultSet->getUInt(13));
		data.setAttr4(resultSet->getUInt(14));
		data.setCreate_by(resultSet->getString(15));
		data.setCreate_time(resultSet->getString(16));
		data.setUpdate_by(resultSet->getString(17));
		data.setUpdate_time(resultSet->getString(18));

		//data.set(resultSet->getString());
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		return data;
	}
};


class Dv_check_planDeleteMapper : public Mapper<Dv_check_planDO>
{
public:
	Dv_check_planDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_planDO data;
		data.setPlan_id(resultSet->getUInt64(1));
		data.setPlan_code(resultSet->getString(2));
		data.setPlan_name(resultSet->getString(3));
		//data.set(resultSet->getString());
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		return data;
	}
};

#endif // !_DV__CHECK__PLAN_MAPPER_
