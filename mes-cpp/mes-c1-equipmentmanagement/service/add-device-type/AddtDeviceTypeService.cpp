
#include "stdafx.h"

#include"AddtDeviceTypeService.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../dao/add-device-type/AddDeviceTypeDAO.h"
uint64_t AddDeviceTypeService::addData(const AddDeviceTypeListDTO::Wrapper& dto, std::string &code)
{
	// 组装DO数据
	EquipmentTypeDO data;
	data.setCode(code);
	data.setName(dto->machineryTypeName.getValue({})); 
	data.setParentId(dto->parentTypeId.getValue({}));
	data.setEnable(dto->status.getValue({}));
	data.setRemark(dto->remark.getValue({}));;
	if (dto->remark)  data.setRemark(dto->remark.getValue({}));
	// 执行数据添加
	AddDeviceTypeDAO dao;
	return dao.insert(data);
}
