#pragma once
#ifndef _MATERIALPRODUCTS_MAPPER_
#define _MATERIALPRODUCTS_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/DetectionTemplate/MaterialProductsDO.h"

class MaterialProductsMapper : public Mapper<MaterialProductsDO>
{
public:
	MaterialProductsDO mapper(ResultSet* resultSet) const override
	{
		MaterialProductsDO data;
		data.setrecord_id(resultSet->getUInt64(1));
		data.setitem_code(resultSet->getString(2));
		data.setitem_name(resultSet->getString(3));
		data.setspecification(resultSet->getString(4));
		data.setunit_of_measure(resultSet->getString(5));
		data.setquantity_check(resultSet->getUInt64(6));
		data.setquantity_unqualified(resultSet->getUInt64(7));
		data.setcr_rate(resultSet->getDouble(8));
		data.setmaj_rate(resultSet->getDouble(9));
		data.setmin_rate(resultSet->getDouble(10));
		data.setremark(resultSet->getString(11));
		return data;
	}
};
#endif // !_MATERIALPRODUCTS_MAPPER_
