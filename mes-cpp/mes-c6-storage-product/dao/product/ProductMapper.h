#pragma once
#ifndef _PRODUCT_MAPPER_
#define _PRODUCT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/product/ProductDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProductTableMapper : public Mapper<ProductTableDO>
{
public:
	ProductTableDO mapper(ResultSet* resultSet) const override
	{
		ProductTableDO data;
		data.setIssue_id(resultSet->getUInt64(1));
		data.setIssue_code(resultSet->getString(2));
		data.setIssue_name(resultSet->getString(3));
		data.setWorkorder_code(resultSet->getString(4));
		data.setClient_code(resultSet->getString(5));
		data.setClient_name(resultSet->getString(6));
		data.setIssue_date(resultSet->getString(7));
		data.setStatus1(resultSet->getString(8));
		return data;
	}
};
class ProductDetailMapper : public Mapper<ProductDetailDO>
{
public:
	ProductDetailDO mapper(ResultSet* resultSet) const override
	{
		ProductDetailDO data;
		data.setIssue_id(resultSet->getUInt64(1));
		data.setIssue_code(resultSet->getString(2));
		data.setIssue_name(resultSet->getString(3));
		data.setWorkorder_code(resultSet->getString(4));
		data.setClient_code(resultSet->getString(5));
		data.setClient_name(resultSet->getString(6));
		data.setIssue_date(resultSet->getString(7));
		data.setStatus1(resultSet->getString(8));
		data.setWarehouse_name(resultSet->getString(9));
		data.setRemark(resultSet->getString(10));
		
		return data;
	}
};


#endif
