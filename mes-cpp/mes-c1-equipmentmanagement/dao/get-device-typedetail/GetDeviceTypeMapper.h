#pragma once

#include"../../../lib-mysql/include/Mapper.h"
#include"../../domain/do/equipment-type/EquipmentTypeDO.h"
/* *
* 类型设置具表字段匹配映射
*/

class GetDeviceTypeMapper : public Mapper<EquipmentTypeDO>
{
public:
	EquipmentTypeDO mapper(ResultSet* rset) const override
	{
		EquipmentTypeDO data;
		// 设备类型ID		
		data.setId(rset->getUInt64(1));
		// 设备类型编码			
		data.setCode(rset->getString(2));
		// 设备类型名称	
		data.setName(rset->getString(3));
		// 父类型ID 
		data.setParentId(rset->getUInt64(4));
		// 所有父节点ID	
		data.setAncestorId(rset->getString(5));
		// 是否启用	
		data.setEnable(rset->getString(6));
		// 备注  
		data.setRemark(rset->getString(7));
		// 创建者		
		data.setCreateBy(rset->getString(8));
		// 创建时间	
		data.setCreateTime(rset->getString(9));
		// 更新者
		data.setUpdateBy(rset->getString(10));
		// 更新时间			
		data.setUpdateTime(rset->getString(11));

		return data;
	}
};