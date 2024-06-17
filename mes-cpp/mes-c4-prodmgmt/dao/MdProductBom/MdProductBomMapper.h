#pragma once

#ifndef _MDPRODUCTBOM_MAPPER_
#define _MDPRODUCTBOM_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MdProductBom/MdProductBomDO.h"


class MdProductBomMapper : public Mapper<MdProductBomDO>
{
public:
	MdProductBomDO mapper(ResultSet* resultSet) const override
	{
		MdProductBomDO data;
		data.setBomItemId(resultSet->getInt64(1));
		data.setBomItemCode(resultSet->getString(2));
		data.setBomItemName(resultSet->getString(3));
		data.setBomItemSpc(resultSet->getString(4));
		data.setUnitOfMeasure(resultSet->getString(5));
		data.setItemOrProduct(resultSet->getString(6));
		data.setQuantity(resultSet->getDouble(7));

		return data;
	}
};

#endif // !_MDPRODUCTBOM_MAPPER_