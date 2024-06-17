#pragma once
#ifndef _EQUIPMENTYPEDO_H_
#define _EQUIPMENTYPEDO_H_

#include "../DoInclude.h"
/**
 * �豸�������ݿ�ʵ��
 */
class EquipmentTypeDO
{
	// �豸����ID
	CC_SYNTHESIZE(string, machineryTypeId, MachineryTypeId);
	//�豸���ͱ���
	CC_SYNTHESIZE(string, machineryTypeCode, MachineryTypeCode);
	//�豸��������
	CC_SYNTHESIZE(string, machineryTypeName, MachineryTypeName);
	// �Ƿ�����
	CC_SYNTHESIZE(char, enableFlag, EnableFlag);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//����id
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