#pragma once
#ifndef _PROINSPECT_MAPPER1_
#define _PROINSPECT_MAPPER1_

#include "Mapper.h"
#include "../../domain/do/ProinSpect/ProinSpectDO.h"

class ProinspectMapper1 : public Mapper<ProinspectDO>
{
public:
	ProinspectDO mapper(ResultSet* resultSet) const override
	{
		ProinspectDO data;

		data.setIndex_name(resultSet->getString(1));
		data.setIndex_type(resultSet->getString(2));
		data.setQc_tool(resultSet->getString(3));
		data.setCheck_method(resultSet->getString(4));
		data.setStander_val(resultSet->getDouble(5));
		data.setUnit_of_measure(resultSet->getString(6));
		data.setThreshold_max(resultSet->getDouble(7));
		data.setThreshold_min(resultSet->getDouble(8));
		data.setCr_quantity(resultSet->getDouble(9));
		data.setMaj_quantity(resultSet->getDouble(10));
		data.setMin_quantity(resultSet->getDouble(11));
		return data;
	}
};
#endif // !_PROINSPECT_MAPPER1_
