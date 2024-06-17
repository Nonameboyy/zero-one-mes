#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Croissant
 @Date: 2024/5/27

*/
#ifndef _WORKFIXTURETYPESETTINGDO_H_
#define _WORKFIXTURETYPESETTINGDO_H_
#include "../DoInclude.h"

/**
 * ��װ�о� �������� ���ݿ�ʵ����
 */
class WorkFixtureTypeSettingDO
{
	// ��װ�о�����ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ͱ���
	CC_SYNTHESIZE(string, code, Code);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// �Ƿ�������
	CC_SYNTHESIZE(string, flag, Flag);
	//����ά������
	CC_SYNTHESIZE(string, maintenType, MaintenType);
	//��������
	CC_SYNTHESIZE(int, period, Period);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(string, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(string, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//������
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
public:
	WorkFixtureTypeSettingDO() {
		id = 0;
		code = "";
		name = "";
		flag = 'Y';
	}
};

#endif // !_WORKFIXTURETYPESETTINGDO_H_
