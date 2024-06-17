#pragma once
#ifndef _PRODWORKORDERBOMLIST_DTO_
#define _PRODWORKORDERBOMLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ��ȡ��������BOM����б������
 */
class ProdWorkorderBomListDTO : public oatpp::DTO {
	DTO_INIT(ProdWorkorderBomListDTO, DTO);

	//BOM��ID;line_id;bigint
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("bom.field.line_id");
	}
	//BOM���ϱ��;item_code;varchar
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("bom.field.item_code");
	}
	//BOM��������;item_name;varchar
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("bom.field.item_name");
	}
	//����ͺ�;item_spc;varchar
	DTO_FIELD(String, item_spc);
	DTO_FIELD_INFO(item_spc) {
		info->description = ZH_WORDS_GETTER("bom.field.item_spc");
	}
	//��λ;unit_of_measure;varchar
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("bom.field.unit_of_measure");
	}
	//����/��Ʒ;item_or_product;varchar
	DTO_FIELD(String, item_or_product);
	DTO_FIELD_INFO(item_or_product) {
		info->description = ZH_WORDS_GETTER("bom.field.item_or_product");
	}
	//Ԥ��ʹ����;quantity;double
	DTO_FIELD(Float64, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("bom.field.quantity");
	}
};


/**
 * ��ȡ��������BOM����б��ҳ�������
 */
class ProdWorkorderBomListPageDTO : public PageDTO<ProdWorkorderBomListDTO::Wrapper>
{
	DTO_INIT(ProdWorkorderBomListPageDTO, PageDTO<ProdWorkorderBomListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODWORKORDERBOMLIST_DTO_