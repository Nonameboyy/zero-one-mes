#pragma once
#ifndef __AREADTO_H__
#define __AREADTO_H__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 传输对象
*/
class AreaDTO: public oatpp::DTO
{
	DTO_INIT(AreaDTO, DTO)
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("storagearea.fields.areaId"))
	//仓库库位编码
	API_DTO_FIELD_DEFAULT(String, area_code, ZH_WORDS_GETTER("storagearea.fields.areacode"))
	//仓库库位名称
	API_DTO_FIELD_DEFAULT(String, area_name, ZH_WORDS_GETTER("storagearea.fields.areaname"))
	//库区ID
	API_DTO_FIELD_DEFAULT(UInt64, location_id, ZH_WORDS_GETTER("storagearea.fields.locationId"))
	//仓库库位位置x
	API_DTO_FIELD_DEFAULT(Int32, position_x, ZH_WORDS_GETTER("storagearea.fields.positionx") )
	//仓库库位位置y
	API_DTO_FIELD_DEFAULT(Int32, position_y, ZH_WORDS_GETTER("storagearea.fields.positiony") )
	//仓库库位位置z
	API_DTO_FIELD_DEFAULT(Int32, position_z, ZH_WORDS_GETTER("storagearea.fields.positionz") )
	//是否启用库位
	API_DTO_FIELD(String, enable_flag, ZH_WORDS_GETTER("storagearea.fields.enableFlag"),false,"Y")
	//库位面积
	API_DTO_FIELD(Float64, areasize, ZH_WORDS_GETTER("storagearea.fields.area"),false,10.0 )
	//最大载重量
	API_DTO_FIELD(Float64, max_loa, ZH_WORDS_GETTER("storagearea.fields.maxLoa"),false,50.0 )
	//备注
	API_DTO_FIELD_DEFAULT(String, remarktext, ZH_WORDS_GETTER("storagearea.fields.remark"))
};
/*
* 分页传输对象（分页）
*/
class AreaPageDTO : public PageDTO<AreaDTO::Wrapper>
{
	DTO_INIT(AreaPageDTO, PageDTO<AreaDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif //__AREADTO_H__
