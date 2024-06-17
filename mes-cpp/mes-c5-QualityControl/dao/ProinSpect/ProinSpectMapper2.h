#pragma once
#ifndef _PROINSPECT_MAPPER2_
#define _PROINSPECT_MAPPER2_

#include "Mapper.h"
#include "../../domain/do/ProinSpect/ProinSpectDO.h"

class ProinspectMapper2 : public Mapper<ProinspectDO>
{
public:
	ProinspectDO mapper(ResultSet* resultSet) const override
	{
		ProinspectDO data;

		data.setQc_type(resultSet->getString(1));
		data.setQc_id(resultSet->getUInt64(2));
		data.setLine_id(resultSet->getUInt64(3));
		data.setDefect_name(resultSet->getString(4));
		data.setDefect_level(resultSet->getString(5));
		data.setDefect_quantity(resultSet->getUInt(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};
#endif // !_PROINSPECT_MAPPER2_
