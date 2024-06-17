#pragma once
#ifndef _PROCESSINSPECTION_MAPPER_
#define _PROCESSINSPECTION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ProcessInspection/ProcessInspectionDO.h"

class ProcessInspectionMapper : public Mapper<ProcessInspectionDO> {
public:
	ProcessInspectionDO mapper(ResultSet* resultSet) const override {
		ProcessInspectionDO data;
		int i = 1;
		data.setId(resultSet->getUInt64(i++));
		data.setIpqc_Code(resultSet->getString(i++));
		data.setIpqc_Name(resultSet->getString(i++));
		data.setIpqc_Type(resultSet->getString(i++));
		data.setWorkorder_Code(resultSet->getString(i++));
		data.setWorkorder_Name(resultSet->getString(i++));
		data.setWorkstation_Code(resultSet->getString(i++));
		data.setWorkstation_Name(resultSet->getString(i++));
		data.setQuantity_Check(resultSet->getDouble(i++));
		data.setItem_Code(resultSet->getString(i++));
		data.setItem_Name(resultSet->getString(i++));
		data.setUnit_Of_Measure(resultSet->getString(i++));
		data.setSpecification(resultSet->getString(i++));
		data.setProcess_Code(resultSet->getString(i++));
		data.setProcess_Name(resultSet->getString(i++));
		data.setTask_Code(resultSet->getString(i++));
		data.setQuantity_Unqualified(resultSet->getDouble(i++));
		data.setQuantity_Qualified(resultSet->getDouble(i++));
		data.setCr_Quantity(resultSet->getDouble(i++));
		data.setMaj_Quantity(resultSet->getDouble(i++));
		data.setMin_Quantity(resultSet->getDouble(i++));
		data.setInspect_Date(resultSet->getString(i++));
		data.setCheck_Result(resultSet->getString(i++));
		data.setInspector(resultSet->getString(i++));
		data.setRemark(resultSet->getString(i++));
		return data;
	}
};

class ProcessInspectionQueryMapper : public Mapper<ProcessInspectionDO> {
public:
	ProcessInspectionDO mapper(ResultSet* resultSet) const override {
		ProcessInspectionDO data;
		int i = 1;
		data.setId(resultSet->getUInt64(i++));
		data.setIpqc_Code(resultSet->getString(i++));
		data.setIpqc_Type(resultSet->getString(i++));
		data.setWorkorder_Code(resultSet->getString(i++));
		data.setItem_Code(resultSet->getString(i++));
		data.setItem_Name(resultSet->getString(i++));
		data.setSpecification(resultSet->getString(i++));
		data.setUnit_Of_Measure(resultSet->getString(i++));
		data.setQuantity_Check(resultSet->getDouble(i++));
		data.setCheck_Result(resultSet->getString(i++));
		data.setInspect_Date(resultSet->getString(i++));
		data.setInspector(resultSet->getString(i++));
		data.setStatus_Order(resultSet->getString(i++));
		
		return data;
	}
};

#endif // !_PROCESSINSPECTION_MAPPER_
