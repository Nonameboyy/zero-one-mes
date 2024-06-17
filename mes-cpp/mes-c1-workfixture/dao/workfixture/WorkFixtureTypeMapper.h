#pragma once
/*
 @Author: Croissant
*/
#ifndef _WORKFIXTURETYPEMAPPER_H_
#define _WORKFIXTURETYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/workfixture/WorkFixtureTypeSettingDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class WorkFixtureTypeMapper : public Mapper<WorkFixtureTypeSettingDO>
{
public:
	WorkFixtureTypeSettingDO mapper(ResultSet* resultSet) const override
	{
		/*
	// ��װ�о�����ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���ͱ���
	CC_SYNTHESIZE(string, code, Code);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// �Ƿ�������
	CC_SYNTHESIZE(char, flag, Flag);
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
		*/
		WorkFixtureTypeSettingDO data;
		data.setId(resultSet->getUInt64(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setFlag(resultSet->getString(4));
		data.setMaintenType(resultSet->getString(5));
		data.setPeriod(resultSet->getUInt64(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};

#endif // !_WORKFIXTURETYPEMAPPER_H_