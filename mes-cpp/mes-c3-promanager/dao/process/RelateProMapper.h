#pragma once
#ifndef _RELATEPRO_MAPPER_
#define _RELATEPRO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProRouteProductDO.h"

///**
// * 添加+修改关联产品字段匹配映射
// */
//class ProRouteProductMapper : public Mapper<ProRouteProductDO>
//{
//public:
//	SampleDO mapper(ResultSet* resultSet) const override
//	{
//		ProRouteProductDO data;
//		data.setItem_Code(resultSet->getString(1));
//		data.setItem_Name(resultSet->getString(2));
//		data.setUnit_Of_Measure(resultSet->getString(3));
//		data.setSpecification(resultSet->getString(4));
//		data.setRemark(resultSet->getString(5));
//		return data;
//	}
//};
/**
 * 导出
 */
class exportRouteProductMapper : public Mapper<ProRouteProductDO>
{
public:
	ProRouteProductDO mapper(ResultSet* resultSet) const override
	{
		ProRouteProductDO data;
		data.setRecord_Id(resultSet->getUInt64(1));
		data.setRoute_Id(resultSet->getUInt64(2));
		data.setItem_Id(resultSet->getUInt64(3));
		data.setItem_Code(resultSet->getString(4));
		data.setItem_Name(resultSet->getString(5));
		data.setSpecification(resultSet->getString(6));
		data.setUnit_Of_Measure(resultSet->getString(7));
		data.setQuantity(resultSet->getUInt(8));
		data.setProduction_Time(resultSet->getDouble(9));
		data.setTime_Unit_Type(resultSet->getString(10));
		data.setRemark(resultSet->getString(11));

		return data;
	}
};
#endif // !_RELATEPRO_MAPPER_