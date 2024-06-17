#pragma once
#ifndef _PROCESSPRODUCTS_DTO_
#define _PROCESSPRODUCTS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class ProcessProductsDTO : public oatpp::DTO
{
	DTO_INIT(ProcessProductsDTO, DTO);

	// Ψһ��ʶ
	DTO_FIELD(UInt64, routeid);
	DTO_FIELD_INFO(routeid) {
		info->description = ZH_WORDS_GETTER("product.field.routeid");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("product.field.id");
	}
	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("product.field.name");
	}
	// ����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("product.field.size");
	}
	// ��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("product.field.unit");
	}

};
/**
 * ���չ�����Ʒ�б��ҳ�������
 */
class ProductsPageDTO : public PageDTO<ProcessProductsDTO::Wrapper>
{
	DTO_INIT(ProductsPageDTO, PageDTO<ProcessProductsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
