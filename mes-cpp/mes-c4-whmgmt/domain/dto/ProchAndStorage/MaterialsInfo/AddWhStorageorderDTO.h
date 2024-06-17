#pragma once
#ifndef _ADDWHSTORAGEORDERDTO_H_
#define _ADDWHSTORAGEORDERDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
����һ�������ⵥ����Ϣ�����ݴ�������
*/
class AddWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(AddWhStorageorderDTO, DTO);

	//��20���ֶ�
	//��Ʒ����ID item_id bigint  
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("whstorageorder.field.item_id"), true, 72);
	//���ϱ��� item_code varchar
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("whstorageorder.field.item_code"),true, ZH_WORDS_GETTER("whstorageorder.default.item_code"));
	//�������� item_name varchar
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("whstorageorder.field.item_name"),true, ZH_WORDS_GETTER("whstorageorder.default.item_name"));
	
	//��λ unit_of_measure varchar
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("whstorageorder.field.unit_of_measure"),true, ZH_WORDS_GETTER("whstorageorder.default.unit_of_measure"));
	//������� quantity_recived double
	API_DTO_FIELD(Float64, quantity_recived, ZH_WORDS_GETTER("whstorageorder.field.quantity_recived"),true,1);
	//������κ� batch_code varchar
	API_DTO_FIELD_DEFAULT(String, batch_code, ZH_WORDS_GETTER("whstorageorder.field.batch_code"));
	//��Ч�� expire_date String
	API_DTO_FIELD_DEFAULT(String, expire_date, ZH_WORDS_GETTER("whstorageorder.field.expire_date"));
	
	//�ֿ�ID warehouse_id bigint
	API_DTO_FIELD(UInt64, warehouse_id, ZH_WORDS_GETTER("whstorageorder.field.warehouse_id"), true,210);
	//�ֿ���� warehouse_code varchar
	API_DTO_FIELD(String, warehouse_code, ZH_WORDS_GETTER("whstorageorder.field.warehouse_code"),true, ZH_WORDS_GETTER("whstorageorder.default.warehouse_code"));
	//�ֿ����� warehouse_name varchar
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("whstorageorder.field.warehouse_name"),true, ZH_WORDS_GETTER("whstorageorder.default.warehouse_name"));
	
	//����ID location_id bigint
	API_DTO_FIELD(UInt64, location_id, ZH_WORDS_GETTER("whstorageorder.field.location_id"), true, 210);
	//�������� location_code varchar
	API_DTO_FIELD(String, location_code, ZH_WORDS_GETTER("whstorageorder.field.location_code"), true, ZH_WORDS_GETTER("whstorageorder.default.location_code"));
	//�������� location_name varchar
	API_DTO_FIELD(String, location_name, ZH_WORDS_GETTER("whstorageorder.field.location_name"), true, ZH_WORDS_GETTER("whstorageorder.default.location_name"));
	
	//��λID area_id bigint
	API_DTO_FIELD(UInt64, area_id, ZH_WORDS_GETTER("whstorageorder.field.area_id"), true, 212);
	//��λ���� area_code varchar
	API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("whstorageorder.field.area_code"), true, ZH_WORDS_GETTER("whstorageorder.default.area_code"));
	//��λ���� area_name varchar
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("whstorageorder.field.area_name"), true, ZH_WORDS_GETTER("whstorageorder.default.area_name"));

	//�Ƿ���� iqc_check char
	API_DTO_FIELD(String, iqc_check, ZH_WORDS_GETTER("whstorageorder.field.iqc_check"),true, ZH_WORDS_GETTER("whstorageorder.default.iqc_check"));
	//���ϼ��鵥���� iqc_code varchar
	API_DTO_FIELD_DEFAULT(String, iqc_code, ZH_WORDS_GETTER("whstorageorder.field.iqc_code"));
	//���ϼ��鵥ID iqc_id bigint
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("whstorageorder.field.iqc_id"));
	//��ע remark varchar
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("whstorageorder.field.remark"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // _ADDWHSTORAGEORDERDTO_H_
