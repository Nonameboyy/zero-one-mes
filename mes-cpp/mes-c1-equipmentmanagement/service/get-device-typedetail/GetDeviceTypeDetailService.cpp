#include "stdafx.h"

#include"GetDeviceTypeDetailService.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../dao/get-device-typedetail/GetDeviceTypeDetailDAO.h"
#include"../../dao/get-device-typenametree/GetDeviceTypeNameTreeDAO.h"
list<EquipmentTypeDO> GetDeviceTypeDetailService::queryTypeDetail(const GetDeviceTypeDetailQuery::Wrapper& query)
{
	// 通过查询参数查询数据
	GetDeviceTypeDetailDAO dao;
	return dao.selectByCondition(query);;
}
