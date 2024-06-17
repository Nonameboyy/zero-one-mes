#pragma once
#ifndef _MATERIALPRODUCTSDTO_DTO_
#define _MATERIALPRODUCTSDTO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MaterialProductsDTO : public oatpp::DTO
{
	DTO_INIT(MaterialProductsDTO, DTO);
	// ��¼ID
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.record_id");
	}
	// ��Ʒ���ģ��ID
	DTO_FIELD(Int64, template_id);
	DTO_FIELD_INFO(template_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.template_id");
	}

	// ��Ʒ����ID
	DTO_FIELD(Int64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_id");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_code");
	}
	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.item_name");
	}
	// ����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.specification");
	}
	
	// ��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.unit_of_measure");
	}

	// ��ͼ����
	DTO_FIELD(UInt32, quantity_check);
	DTO_FIELD_INFO(quantity_check) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.quantity_check");
	}

	// ��󲻺ϸ���
	DTO_FIELD(UInt32, quantity_unqualified);
	DTO_FIELD_INFO(quantity_unqualified) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.quantity_unqualified");
	}
	// �������ȱ����
	DTO_FIELD(Float64, cr_rate);
	DTO_FIELD_INFO(cr_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.cr_rate");
	}
	// �������ȱ����
	DTO_FIELD(Float64, maj_rate);
	DTO_FIELD_INFO(maj_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.maj_rate");
	}
	// �����΢ȱ����
	DTO_FIELD(Float64, min_rate);
	DTO_FIELD_INFO(min_rate) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.min_rate");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("MaterialProducts.field.remark");
	}

};



class MaterialProductsPageDTO : public PageDTO<MaterialProductsDTO::Wrapper>
{
	DTO_INIT(MaterialProductsPageDTO, PageDTO<MaterialProductsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_