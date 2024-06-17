#pragma once
#ifndef __AREADTO_H__
#define __AREADTO_H__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �������
*/
class AreaDTO: public oatpp::DTO
{
	DTO_INIT(AreaDTO, DTO)
	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("storagearea.fields.areaId"))
	//�ֿ��λ����
	API_DTO_FIELD_DEFAULT(String, area_code, ZH_WORDS_GETTER("storagearea.fields.areacode"))
	//�ֿ��λ����
	API_DTO_FIELD_DEFAULT(String, area_name, ZH_WORDS_GETTER("storagearea.fields.areaname"))
	//����ID
	API_DTO_FIELD_DEFAULT(UInt64, location_id, ZH_WORDS_GETTER("storagearea.fields.locationId"))
	//�ֿ��λλ��x
	API_DTO_FIELD_DEFAULT(Int32, position_x, ZH_WORDS_GETTER("storagearea.fields.positionx") )
	//�ֿ��λλ��y
	API_DTO_FIELD_DEFAULT(Int32, position_y, ZH_WORDS_GETTER("storagearea.fields.positiony") )
	//�ֿ��λλ��z
	API_DTO_FIELD_DEFAULT(Int32, position_z, ZH_WORDS_GETTER("storagearea.fields.positionz") )
	//�Ƿ����ÿ�λ
	API_DTO_FIELD(String, enable_flag, ZH_WORDS_GETTER("storagearea.fields.enableFlag"),false,"Y")
	//��λ���
	API_DTO_FIELD(Float64, areasize, ZH_WORDS_GETTER("storagearea.fields.area"),false,10.0 )
	//���������
	API_DTO_FIELD(Float64, max_loa, ZH_WORDS_GETTER("storagearea.fields.maxLoa"),false,50.0 )
	//��ע
	API_DTO_FIELD_DEFAULT(String, remarktext, ZH_WORDS_GETTER("storagearea.fields.remark"))
};
/*
* ��ҳ������󣨷�ҳ��
*/
class AreaPageDTO : public PageDTO<AreaDTO::Wrapper>
{
	DTO_INIT(AreaPageDTO, PageDTO<AreaDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif //__AREADTO_H__
