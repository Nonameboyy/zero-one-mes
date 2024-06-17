#pragma once
#ifndef _MATERIALINFORMATION_MAPPER_
#define _MATERIALINFORMATION_MAPPER_
#pragma once
#include "Mapper.h"
#include "../../domain/do/RawMaterialOp/RawMaterialOpDO.h"

/*
 */
class RawMaterialOpMapper : public Mapper<RawMaterialOpDO>
{
public:
	RawMaterialOpDO mapper(ResultSet* resultSet) const override
	{
		RawMaterialOpDO data;
		data.setRt_Id(resultSet->getUInt64(1));
		data.setRt_Code(resultSet->getString(2));
		data.setRt_Name(resultSet->getString(3));
		data.setWorkororder_Id(resultSet->getUInt64(4));
		data.setWorkororder_Code(resultSet->getString(5));
		data.setWarehouse_Id(resultSet->getUInt64(6));
		data.setWarehouse_Code(resultSet->getString(7));
		data.setWarehouse_Name(resultSet->getString(8));
		data.setLocation_Id(resultSet->getUInt64(9));
		data.setLocation_Code(resultSet->getString(10));
		data.setLocation_Name(resultSet->getString(11));
		data.setArea_Id(resultSet->getUInt64(12));
		data.setArea_Code(resultSet->getString(13));
		data.setArea_Name(resultSet->getString(14));
		data.setRt_Date(resultSet->getString(15));
		data.setRemark(resultSet->getString(16));

		return data;
	}
};

#endif 