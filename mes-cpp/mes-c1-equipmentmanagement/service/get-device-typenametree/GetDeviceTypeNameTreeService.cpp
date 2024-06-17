#include "stdafx.h"

#include"GetDeviceTypeNameTreeService.h"

#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../dao/get-device-typenametree/GetDeviceTypeNameTreeDAO.h"
list<EquipmentTypeDO> GetDeviceTypeNameTreeService::queryTypeNameTree(const string &name)
{
	GetDeviceTypeNameTreeDAO dao;
	return dao.selectByName(name);
}