#pragma once
#ifndef _PROMATERIAL_MAPPER_
#define _PROMATERIAL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProRouteProductBomDO.h"

/**
 * 产品制成物料表字段匹配映射
 */
class ProMaterialMapper : public Mapper<ProRouteProductBomDO>
{
public:
	ProRouteProductBomDO mapper(ResultSet* resultSet) const override
	{
		ProRouteProductBomDO data;
		data.setItem_code(resultSet->getString(1));
		data.setItem_name(resultSet->getString(2));
		data.setSpecification(resultSet->getString(3));
		data.setUnit_of_measure(resultSet->getString(4));
		data.setQuantity(resultSet->getDouble(5));
		return data;
	}
};

#endif // !_PROMATERIAL_MAPPER_