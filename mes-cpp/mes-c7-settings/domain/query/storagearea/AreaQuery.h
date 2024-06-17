#ifndef __LOCALQUERY_H__
#define __LOCALQUERY_H__

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �ֿ��λ��ҳ��ѯ��������
*/
class AreaQuery: public PageQuery
{
	DTO_INIT(AreaQuery, PageQuery)
	//�ֿ��λ����
	API_DTO_FIELD_DEFAULT(oatpp::String, area_code, ZH_WORDS_GETTER("storagearea:fields:areacode"))
	//�ֿ��λ����
	API_DTO_FIELD_DEFAULT(oatpp::String, area_name, ZH_WORDS_GETTER("storagearea:fields:areaname"))
	//����ID
	API_DTO_FIELD_DEFAULT(oatpp::Int64, location_id, ZH_WORDS_GETTER("storagearea:fields:locationId"))
	//�ֿ��λλ��x
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_x, ZH_WORDS_GETTER("storagearea:fields:positionx"))
	//�ֿ��λλ��y
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_y, ZH_WORDS_GETTER("storagearea:fields:positiony"))
	//�ֿ��λλ��z
	API_DTO_FIELD_DEFAULT(oatpp::Int32, position_z, ZH_WORDS_GETTER("storagearea:fields:positionz"))

};


#include OATPP_CODEGEN_END(DTO) 
#endif //__LOCALQUERY_H__

