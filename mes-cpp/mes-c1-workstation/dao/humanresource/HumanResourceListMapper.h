#pragma once
#ifndef _HUMANRESOURCELIST_MAPPER_
#define _HUMANRESOURCELIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/humanresource/HumanResourceListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class HumanResourceListMapper : public Mapper<HumanResourceListDO>
{
public:
	HumanResourceListDO mapper(ResultSet* resultSet) const override
	{
		HumanResourceListDO data;
		data.setPostName(resultSet->getString(1));
		data.setQuantity(resultSet->getInt(2));
		data.setRecordId(resultSet->getUInt64(3));
		data.setWorkstationId(resultSet->getUInt64(4));
		data.setPostId(resultSet->getUInt64(5));

		return data;
	}
};

#endif // !_HUMANRESOURCELIST_MAPPER_