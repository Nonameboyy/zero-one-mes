#pragma once
#ifndef __AREADO_H__
#define __AREADO_H__
#include "../DoInclude.h"
#include <iostream>

class AreaDO 
{
	CC_SYNTHESIZE(std::uint64_t, id, Id)
	CC_SYNTHESIZE(std::string, area_code, AreaCode)
	CC_SYNTHESIZE(std::string, area_name, AreaName)
	CC_SYNTHESIZE(std::uint64_t, location_id, Lid)
	CC_SYNTHESIZE(std::int32_t, position_x, X)
	CC_SYNTHESIZE(std::int32_t, position_y, Y)
	CC_SYNTHESIZE(std::int32_t, position_z, Z)
	CC_SYNTHESIZE(std::string, enable_flag, Ison)
	CC_SYNTHESIZE(double, areasize, AreaSize)
	CC_SYNTHESIZE(double, max_loa, MaxLoa)
	CC_SYNTHESIZE(std::string, remarktext, Remark)
	CC_SYNTHESIZE(std::string, attr1, Text1)
	CC_SYNTHESIZE(std::string, attr2, Text2)
	CC_SYNTHESIZE(std::int32_t, attr3, Text3)
	CC_SYNTHESIZE(std::int32_t, attr4, Text4)
	CC_SYNTHESIZE(std::string, create_by, CreateBy)
	CC_SYNTHESIZE(std::string, create_time, CreateTime)
	CC_SYNTHESIZE(std::string, update_by, UpdateBy)
	CC_SYNTHESIZE(std::string, update_time, UpdateTime)
public:
	AreaDO() {
		id = 0;
		area_code = "";
		area_name = "";
		location_id = 0;
		position_x = 0;
		position_y = 0;
		position_z = 0;
		enable_flag = 'Y';
		areasize = 0.0;
		max_loa = 0.0;
		remarktext = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}

	
	
};

#endif //__AREADO_H__