#pragma once
/*
 @Author: Croissant
*/
#ifndef _WORKFIXTURETYPEMAPPER_H_
#define _WORKFIXTURETYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/workfixture/WorkFixtureTypeSettingDO.h"

/**
 * 示例表字段匹配映射
 */
class WorkFixtureTypeMapper : public Mapper<WorkFixtureTypeSettingDO>
{
public:
	WorkFixtureTypeSettingDO mapper(ResultSet* resultSet) const override
	{
		/*
	// 工装夹具类型ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 类型编码
	CC_SYNTHESIZE(string, code, Code);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
	// 是否编码管理
	CC_SYNTHESIZE(char, flag, Flag);
	//保养维护类型
	CC_SYNTHESIZE(string, maintenType, MaintenType);
	//保养周期
	CC_SYNTHESIZE(int, period, Period);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//预留字段3
	CC_SYNTHESIZE(string, attr3, Attr3);
	//预留字段4
	CC_SYNTHESIZE(string, attr4, Attr4);
	//创建者
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//更新者
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	//更新时间
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