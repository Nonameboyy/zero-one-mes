#ifndef _MACHINERY_PLAN_MAPPER_
#define _MACHINERY_PLAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_check_plan/dv_check_planDO.h"

/**
* Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
*/
class MachineryPlanMapper : public Mapper<Dv_check_planDO>
{
public:
	Dv_check_planDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_planDO data;
		data.setPlan_id(resultSet->getUInt64(1));
		data.setPlan_code(resultSet->getString(2));
		data.setPlan_name(resultSet->getString(3));
		data.setPlan_type(resultSet->getString(4));
		data.setStart_date(resultSet->getString(5));
		data.setEnd_date(resultSet->getString(6));
		data.setCycle_type(resultSet->getString(7));
		data.setCycle_count(resultSet->getUInt64(8));
		data.setStatus(resultSet->getString(9));
		return data;
	}
};

class MachineryPlanDetailsMapper : public Mapper<Dv_check_planDO>
{
public:
	Dv_check_planDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_planDO data;
		data.setPlan_id(resultSet->getUInt64(1));
		data.setPlan_code(resultSet->getString(2));
		data.setPlan_name(resultSet->getString(3));
		data.setPlan_type(resultSet->getString(4));
		data.setStart_date(resultSet->getString(5));
		data.setEnd_date(resultSet->getString(6));
		data.setCycle_type(resultSet->getString(7));
		data.setCycle_count(resultSet->getUInt64(8));
		data.setStatus(resultSet->getString(9));
		data.setRemark(resultSet->getString(10));
		return data;
	}
};

#endif // !_MACHINERY_PLAN_MAPPER_