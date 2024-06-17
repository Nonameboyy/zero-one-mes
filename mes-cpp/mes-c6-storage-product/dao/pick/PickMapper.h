#pragma once

#ifndef _PICK_MAPPER_
#define _PICK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pick/PickDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PickMapper : public Mapper<PickDO>
{
public:
	PickDO mapper(ResultSet* resultSet) const override
	{
		PickDO data;
		data.setId(resultSet->getInt64(1));
		data.setIcode(resultSet->getString(2));
		data.setIname(resultSet->getString(3));
		data.setWcode(resultSet->getString(4));
		return data;
	}
};

#endif // !_PICK_MAPPER_