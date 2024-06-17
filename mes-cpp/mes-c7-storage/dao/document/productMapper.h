#pragma once
#ifndef _product_MAPPER_
#define _product_MAPPER_

#include "Mapper.h"
#include "../../domain/do/document/productDO.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProductMapper : public Mapper<ProductDO>
{
public:
	ProductDO mapper(ResultSet* resultSet) const override
	{
		ProductDO data;
		data.setRecpt_id(resultSet->getUInt64(1));
		data.setRecpt_code(resultSet->getString(2));
		data.setRecpt_name(resultSet->getString(3));
		data.setWorkorder_code(resultSet->getString(4));
		data.setWarehouse_name(resultSet->getString(5));
		data.setProduct_code(resultSet->getString(6));
		data.setProduct_name(resultSet->getString(7));
		data.setRecpt_date(resultSet->getString(8));
		data.setStatus(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_