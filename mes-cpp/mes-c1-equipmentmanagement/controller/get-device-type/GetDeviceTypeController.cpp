#include "stdafx.h"
#include"GetDeviceTypeController.h"
#include"../../service/get-device-typedetail/GetDeviceTypeDetailService.h"
#include"../../service/get-device-typedetail/TreeDeviceTypeDetailMapper.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../../lib-common/include/tree/TreeUtil.h"
DeviceTypeDetailJsonVo::Wrapper GetDeviceTypeController::execQueryTypeNameDetail(const GetDeviceTypeDetailQuery::Wrapper& query)
{
	auto vo =  DeviceTypeDetailJsonVo::createShared();
	// 定义service并执行查询
	GetDeviceTypeDetailService service;
	auto listData = service.queryTypeDetail(query);
	// 转换为树形结构
	auto res = TreeUtil::listToTree(listData, TreeDeviceTypeDetailMapper());
	// 将根节点存储到列表中
	for (auto &one : res)
	{
		vo->data->push_back(DeviceTypeDetailDTO::Wrapper(dynamic_pointer_cast<DeviceTypeDetailDTO>(one),
			DeviceTypeDetailDTO::Wrapper::Class::getType()));
	}
	return vo;
}
