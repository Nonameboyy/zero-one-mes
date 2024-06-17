#pragma once
#ifndef _AWAITINSPECTION_MAPPER_
#define _AWAITINSPECTION_MAPPER_

#include "Mapper.h"
#include "domain/do/AwaitinSpection/AwaitinSpectionDO.h"

class AwaitinSpectionMapper : public Mapper<AwaitinSpectionDO>
{
public:
	AwaitinSpectionDO mapper(ResultSet* resultSet) const override
	{
		AwaitinSpectionDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setFeedback_type(resultSet->getString(2));
		data.setFeedback_code(resultSet->getString(3));
		data.setItem_code(resultSet->getString(4));
		data.setItem_name(resultSet->getString(5));
		data.setQuantity_uncheck(resultSet->getDouble(6));
		data.setWorkstation_name(resultSet->getString(7));
		return data;
	}
};

#endif // !_AWAITINSPECTION_MAPPER_