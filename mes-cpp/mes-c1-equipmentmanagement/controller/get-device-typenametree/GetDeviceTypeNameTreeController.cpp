#include "stdafx.h"

#include"GetDeviceTypeNameTreeController.h"
#include"../../service/get-device-typenametree/GetDeviceTypeNameTreeService.h"
#include"../../service/get-device-typenametree/TreeDeviceTypeMapper.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../../lib-common/include/tree/TreeUtil.h"
DeviceTypeNameTreeJsonVo::Wrapper GetDeviceTypeNameTreeController::execQueryNameTree(const GetDeviceTypeNameTreeQuery::Wrapper &query)
{  // 通过传入的名称获取名称树
	auto vo = DeviceTypeNameTreeJsonVo::createShared();
	GetDeviceTypeNameTreeService service;
	// 承接所有查找出来的设备类型数据
	auto listData = service.queryTypeNameTree(query->machineryTypeName.getValue({}));
	// 转换为树形结构
	auto res = TreeUtil::listToTree(listData, TreeDeviceTypeMapper());
	// 将根结点存储到列表中
	for (auto &one : res)
	{
		vo->data->push_back(DeviceTypeNameTreeDTO::Wrapper(dynamic_pointer_cast<DeviceTypeNameTreeDTO>(one),
			DeviceTypeNameTreeDTO::Wrapper::Class::getType()));
	}
	return vo;
}