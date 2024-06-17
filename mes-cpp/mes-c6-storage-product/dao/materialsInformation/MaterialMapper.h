#pragma once
#ifndef _MATERIAL_MAPPER_
#define _MATERIAL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/materialsInformation/MaterialDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class MaterialMapper : public Mapper<MaterialDO>
{
public:
	 MaterialDO mapper(ResultSet* resultSet) const override
	{
		 MaterialDO data;
		data.setLine_id(resultSet->getUInt64(1));
		data.setIssue_id(resultSet->getUInt64(2));
		data.setItem_id(resultSet->getUInt64(3));
		data.setItem_code(resultSet->getString(4));
		data.setItem_name(resultSet->getString(5));
		data.setSpecification(resultSet->getString(6));
		data.setUnit_of_measure(resultSet->getString(7));
		data.setQuantity_issued(resultSet->getDouble(8));
		data.setBatch_code(resultSet->getString(9));
		data.setWarehouse_name(resultSet->getString(10));
		data.setLocation_name(resultSet->getString(11));
		data.setArea_name(resultSet->getString(12));
		data.setRemark(resultSet->getString(13));
		return data;
	}
};

#endif // !_MATERIAL_MAPPER_