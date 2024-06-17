#pragma once
#ifndef _PROCESSPRODUCT_MAPPER_
#define _PROCESSRODUCTT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProRouteProductDO.h"

/**
 * 工艺关联产品列表数据映射
 */
class ProcessProductsMapper : public Mapper<ProRouteProductDO>
{
public:
	ProRouteProductDO mapper(ResultSet* resultSet) const override
	{
		ProRouteProductDO data;
		data.setRoute_Id(resultSet->getUInt64(1));
		data.setItem_Code(resultSet->getString(2));
		data.setItem_Name(resultSet->getString(3));
		data.setSpecification(resultSet->getString(4));
		data.setUnit_Of_Measure(resultSet->getString(5));
		return data;
	}
};


#endif // !_SAMPLE_MAPPER_