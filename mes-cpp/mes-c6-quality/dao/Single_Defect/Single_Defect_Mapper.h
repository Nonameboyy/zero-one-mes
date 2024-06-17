#pragma once
#ifndef _SINGLE_DEFECT_MAPPER_
#define _SINGLE_DEFECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Single_Defect/Single_Defect_DO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class IndexMapper : public Mapper<IndexDO>
{
public:
	IndexDO mapper(ResultSet* resultSet) const override
	{
		IndexDO data;
		//data.setIqc_id(resultSet->getInt64(1));
		data.setIndex_name(resultSet->getString(1));
		data.setIndex_type(resultSet->getString(2));
		data.setQc_tool(resultSet->getString(3));
		data.setCheck_method(resultSet->getString(4));
		data.setStander_val(resultSet->getDouble(5));
		data.setUnit_of_measure(resultSet->getString(6));
		data.setThreshold_max(resultSet->getDouble(7));
		data.setThreshold_min(resultSet->getDouble(8));
		data.setCr_quantity(resultSet->getInt(9));
		data.setMaj_quantity(resultSet->getInt(10));
		data.setMin_quantity(resultSet->getInt(11));
		data.setRemark(resultSet->getString(12));
		return data;
	}
};

class DefectMapper : public Mapper<DefectDO>
{
public:
	DefectDO mapper(ResultSet* resultSet) const override
	{
		DefectDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setIqc_id(resultSet->getUInt64(2));
		data.setLine_id(resultSet->getUInt64(3));
		data.setDefect_name(resultSet->getString(4));
		data.setDefect_level(resultSet->getString(5));
		data.setDefect_quantity(resultSet->getInt(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};

#endif // !_SINGLE_DEFECT_MAPPER_
