#pragma once

#include"../../../lib-common/include/tree/TreeNodeMapper.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
#include"../../domain/dto/device-typenametree/DeviceTypeNameTreeDTO.h"
class TreeDeviceTypeMapper : public TreeNodeMapper<EquipmentTypeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(EquipmentTypeDO *source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<DeviceTypeNameTreeDTO>();
		// 计算层级结构属性映射
		res->_id(to_string(source->getId()));
		res->_pid(source->getParentId() == 0 ? "" : to_string(source->getParentId()));
		// 扩展属性映射
		res->machineryTypeId = source->getId();
		res->machineryTypCode = source->getCode();
		res->machineryTypeName = source->getName();
		return res;
	}
};