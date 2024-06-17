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
 * 工装夹具 类型设置 数据库实体类
 */
class WorkFixtureTypeSettingDO
{
	// 工装夹具类型ID
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 类型编码
	CC_SYNTHESIZE(string, code, Code);
	// 类型名称
	CC_SYNTHESIZE(string, name, Name);
	// 是否编码管理
	CC_SYNTHESIZE(string, flag, Flag);
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
public:
	WorkFixtureTypeSettingDO() {
		id = 0;
		code = "";
		name = "";
		flag = 'Y';
	}
};

#endif // !_WORKFIXTURETYPESETTINGDO_H_
