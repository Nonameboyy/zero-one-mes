#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_MAPPER_
#define _DV__CHECK__MACHINERY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"

/**
 * dv_check_machinery±Ì£¨◊÷∂Œ∆•≈‰”≥…‰
 */
class Dv_check_machineryDeleteMapper : public Mapper<Dv_check_machineryDO>
{
public:
	Dv_check_machineryDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_machineryDO data;

		data.setRecord_id(resultSet->getUInt64(1));
		data.setPlan_id(resultSet->getUInt64(2));
		data.setMachinery_id(resultSet->getUInt64(3));
		data.setMachinery_code(resultSet->getString(4));
		data.setMachinery_name(resultSet->getString(5));
		return data;
	}
};

#endif // !_DV__CHECK__MACHINERY_MAPPER_