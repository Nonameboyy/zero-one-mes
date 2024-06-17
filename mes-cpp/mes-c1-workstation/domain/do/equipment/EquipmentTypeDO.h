#pragma once
#ifndef _EQUIPMENTYPEDO_H_
#define _EQUIPMENTYPEDO_H_

#include "../DoInclude.h"
/**
 * 设备类型数据库实体
 */
class EquipmentTypeDO
{
	// 设备类型ID
	CC_SYNTHESIZE(string, machineryTypeId, MachineryTypeId);
	//设备类型编码
	CC_SYNTHESIZE(string, machineryTypeCode, MachineryTypeCode);
	//设备类型名称
	CC_SYNTHESIZE(string, machineryTypeName, MachineryTypeName);
	// 是否启用
	CC_SYNTHESIZE(char, enableFlag, EnableFlag);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	//父级id
	CC_SYNTHESIZE(string, parentTypeId, ParentTypeId);
public:
	EquipmentTypeDO() {}
	EquipmentTypeDO(string machineryTypeId,string machineryTypeCode, string machineryTypeName, char enableFlag, string remark, string parentTypeId)
	{
		this->machineryTypeId = machineryTypeId;
		this->machineryTypeCode = machineryTypeCode;
		this->machineryTypeName = machineryTypeName;
		this->enableFlag = enableFlag;
		this->remark = remark;
		this->parentTypeId = parentTypeId;
	}
};

#endif // !_EQUIPMENTYPEDO_H_