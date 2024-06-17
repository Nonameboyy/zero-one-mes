#ifndef __LOCALQUERY_H__
#define __LOCALQUERY_H__

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 仓库库位分页查询条件对象
*/
class AreaQuery: public PageQuery
{
	DTO_INIT(AreaQuery, PageQuery)
	//仓库库位编码
	API_DTO_FIELD_DEFAULT(oatpp::String, area_code, ZH_WORDS_GETTER("storagearea:fields:areacode"))
	//仓库库位名称
	API_DTO_FIELD_DEFAULT(oatpp::String, area_name, ZH_WORDS_GETTER("storagearea:fields:areaname"))
	//库区ID
	API_DTO_FIELD_DEFAULT(oatpp::Int64, location_id, ZH_WORDS_GETTER("storagearea:fields:locationId"))
	//仓库库位位置x
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_x, ZH_WORDS_GETTER("storagearea:fields:positionx"))
	//仓库库位位置y
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_y, ZH_WORDS_GETTER("storagearea:fields:positiony"))
	//仓库库位位置z
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_z, ZH_WORDS_GETTER("storagearea:fields:positionz"))

};


#include OATPP_CODEGEN_END(DTO) 
#endif //__LOCALQUERY_H__

