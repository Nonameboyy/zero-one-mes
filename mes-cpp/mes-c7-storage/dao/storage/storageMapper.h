#pragma once
#ifndef _storage_MAPPER_
#define _storage_MAPPER_
#pragma once
#include "Mapper.h"
#include "../../domain/do/storage/storageDO.h"

/*
 */
class storageMapper : public Mapper<storageDO>
{
public:
	storageDO mapper(ResultSet* resultSet) const override
	{
		storageDO data;
		data.setRe_Id(resultSet->getUInt64(1));
		data.setRe_Code(resultSet->getString(2));
		data.setRe_Name(resultSet->getString(3));
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
		data.setRe_Date(resultSet->getString(15));
		data.setRemark(resultSet->getString(16));

		return data;
	}
};

#endif 