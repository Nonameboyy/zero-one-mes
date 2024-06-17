#pragma once
#ifndef _WAREHOUSEMANAGEMENT_MAPPER_
#define _WAREHOUSEMANAGEMENT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/WarehouseManagement/WarehouseManagementDO.h"


class WarehouseManagementExportMapper : public Mapper<WarehouseManagementDO>
{
public:
	WarehouseManagementDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		WarehouseManagementDO data;
		data.setItem_Id(resultSet->getInt64(i++));
		data.setItem_Code(resultSet->getString(i++));
		data.setItem_Name(resultSet->getString(i++));
		data.setSpecification(resultSet->getString(i++));
		data.setUnit_Of_Measure(resultSet->getString(i++));
		data.setBatch_Code(resultSet->getString(i++));
		data.setWarehouse_Name(resultSet->getString(i++));
		data.setLocation_Name(resultSet->getString(i++));
		data.setArea_Name(resultSet->getString(i++));
		data.setVendor_Code(resultSet->getString(i++));
		data.setVendor_Name(resultSet->getString(i++));
		data.setVendor_Nick(resultSet->getString(i++));
		data.setWorkorder_Code(resultSet->getString(i++));
		data.setRecpt_Date(resultSet->getString(i++));
		data.setExpire_Date(resultSet->getString(i++));
		return data;
	}
};

class WarehouseManagementMapper : public Mapper<WarehouseManagementDO>
{
public:
	WarehouseManagementDO mapper(ResultSet* resultSet) const override
	{
		int i = 1;
		WarehouseManagementDO data;
		data.setItem_Id(resultSet->getInt64(i++));
		data.setItem_Code(resultSet->getString(i++));
		data.setBatch_Code(resultSet->getString(i++));
		data.setWarehouse_Name(resultSet->getString(i++));
		data.setVendor_Code(resultSet->getString(i++));
		data.setVendor_Name(resultSet->getString(i++));
		data.setExpire_Date(resultSet->getString(i++));
		return data;
	}
};


#endif // !_WAREHOUSEMANAGEMENT_MAPPER_