#pragma once
#ifndef _INSPECT_MAPPER_
#define _INSPECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class InspectMapper : public Mapper<InspectDO>
{
public:
	InspectDO mapper(ResultSet* resultSet) const override
	{
		InspectDO data;
		//data.setIqc_id(resultSet->getInt64(1));
		data.setIqc_code(resultSet->getString(1));
		data.setIqc_name(resultSet->getString(2));
		data.setTemplate_id(resultSet->getUInt64(3));
		data.setVendor_id(resultSet->getUInt64(4));
		data.setVendor_nick(resultSet->getString(5));
		data.setVendor_batch(resultSet->getString(6));
		data.setItem_code(resultSet->getString(7));
		data.setItem_name(resultSet->getString(8));
		data.setQuantity_recived(resultSet->getDouble(9));
		data.setQuantity_check(resultSet->getInt64(10));
		data.setQuantity_unqualified(resultSet->getInt64(11));
		data.setCheck_result(resultSet->getString(12));
		data.setRecive_date(resultSet->getString(13));
		data.setInspect_date(resultSet->getString(14));
		data.setInspector(resultSet->getString(15));
		data.setList_status(resultSet->getString(16));
		
		return data;
	}
};

class Inspect_detailMapper : public Mapper<Inspect_detailDO>
{
public:
	Inspect_detailDO mapper(ResultSet* resultSet) const override
	{
		Inspect_detailDO data;
		data.setIqc_id(resultSet->getUInt64(1));
		data.setIqc_code(resultSet->getString(2));
		data.setIqc_name(resultSet->getString(3));
		data.setVendor_code(resultSet->getString(4));
		data.setVendor_nick(resultSet->getString(5));
		data.setVendor_batch(resultSet->getString(6));
		data.setItem_code(resultSet->getString(7));
		data.setItem_name(resultSet->getString(8));
		data.setUnit_of_measure(resultSet->getString(9));
		data.setQuantity_recived(resultSet->getDouble(10));
		data.setQuantity_check(resultSet->getInt64(11));
		data.setQuantity_unqualified(resultSet->getInt64(12));
		data.setCheck_result(resultSet->getString(13));
		data.setRecive_date(resultSet->getString(14));
		data.setInspect_date(resultSet->getString(15));
		data.setMaj_quantity(resultSet->getInt64(16));
		data.setCr_quantity(resultSet->getInt64(17));
		data.setMin_quantity(resultSet->getInt64(18));
		data.setMaj_rate(resultSet->getDouble(19));
		data.setCr_rate(resultSet->getDouble(20));
		data.setMin_rate(resultSet->getDouble(21));
		data.setList_status(resultSet->getString(22));
		data.setRemark(resultSet->getString(23));
		return data;
	}
};

class TableMapper : public Mapper<InspectDO>
{
public:
	InspectDO mapper(ResultSet* resultSet) const override
	{
		InspectDO data;
		data.setIqc_code(resultSet->getString(1));
		data.setIqc_name(resultSet->getString(2));
		data.setVendor_code(resultSet->getString(3));
		data.setVendor_name(resultSet->getString(4));
		data.setItem_id(resultSet->getInt64(5));
		data.setItem_code(resultSet->getString(6));
		data.setItem_name(resultSet->getString(7));
		data.setSpecification(resultSet->getString(8));
		data.setUnit_of_measure(resultSet->getString(9));
		data.setQuantity_min_check(resultSet->getInt(10));
		data.setQuantity_max_unqualified(resultSet->getInt(11));
		data.setQuantity_recived(resultSet->getDouble(12));
		data.setQuantity_check(resultSet->getInt(13));
		data.setQuantity_unqualified(resultSet->getInt(14));
		data.setMaj_rate(resultSet->getDouble(15));
		data.setMin_rate(resultSet->getDouble(16));
		data.setCr_rate(resultSet->getDouble(17));
		data.setMaj_quantity(resultSet->getInt64(18));
		data.setMin_quantity(resultSet->getInt64(29));
		data.setCr_quantity(resultSet->getInt64(20));
		data.setCheck_result(resultSet->getString(21));
		data.setRecive_date(resultSet->getString(22));
		data.setInspect_date(resultSet->getString(23));
		data.setInspector(resultSet->getString(24));
		data.setList_status(resultSet->getString(25));
		return data;
	}
};


#endif // !_INSPECT_MAPPER_
